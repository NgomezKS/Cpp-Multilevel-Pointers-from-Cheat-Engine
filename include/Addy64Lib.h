#pragma once

#ifndef _Addy64_H_
#define _Addy64_H_

#include <vector>
#include <Windows.h>
#include <TlHelp32.h>
#include <tchar.h>


namespace varAddy64 {
	DWORD_PTR baseAddress{ 0 };
	HANDLE    pHandle{ 0 };
	DWORD     pID{ 0 };
	HWND      hGameWindow{ 0 };
	DWORD_PTR  address{ 0 };
}

void getModuleBaseAddress(TCHAR* lpszModuleName);

void getWindowInfo64(char _moduleName[], char _windowName[]);

class Addy64
{

private:
	unsigned int size{ 0 };
	DWORD_PTR aux_address{ 0 };
	DWORD_PTR aux_address2{ 0 };
	std::vector<unsigned int> offsets;

public:

	Addy64(std::vector<unsigned int> _offsets)
	{			
		size = _offsets.size();
		offsets = _offsets;
		getAddress();
	};
	double getDouble();
	float  getFloat();
	int    getInt();

	void   writeFloat(float value);
	void   writeDouble(double value);
	void   writeInt(int value);

private:

	DWORD_PTR getAddress();
};

void getModuleBaseAddress(TCHAR* lpszModuleName)
{
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, varAddy64::pID);
	MODULEENTRY32 ModuleEntry32 = { 0 };
	ModuleEntry32.dwSize = sizeof(MODULEENTRY32);

	if (Module32First(hSnapshot, &ModuleEntry32))
	{
		do {
			if (_tcscmp(ModuleEntry32.szModule, lpszModuleName) == 0)
			{
				varAddy64::baseAddress = (DWORD_PTR)ModuleEntry32.modBaseAddr;
				break;
			}
		} while (Module32Next(hSnapshot, &ModuleEntry32));

	}
	CloseHandle(hSnapshot);
}

void getWindowInfo64(char _moduleName[], char _windowName[])
{
	GetWindowThreadProcessId(FindWindow(NULL, _windowName), &varAddy64::pID);
	varAddy64::pHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, varAddy64::pID);
	getModuleBaseAddress(_T(_moduleName));
}

DWORD_PTR Addy64::getAddress()
{	
	int offsetID;
	if (size == 1)
	{
		return varAddy64::baseAddress + offsets[0];
	}
	else if (size > 1)
	{
		ReadProcessMemory(varAddy64::pHandle, (LPCVOID)(varAddy64::baseAddress + offsets[0]), &aux_address, sizeof(aux_address), NULL);
		for (int i = 1; i < size - 1; i++)
		{
			ReadProcessMemory(varAddy64::pHandle, (LPCVOID)(aux_address + offsets[i]), &aux_address2, sizeof(aux_address2), NULL);
			aux_address = aux_address2;
			offsetID = offsets[i + 1];
			varAddy64::address = aux_address2 + offsetID;
		}

		return varAddy64::address;
		aux_address = 0;
	}

}

double    Addy64::getDouble()
{
	ReadProcessMemory(varAddy64::pHandle, (LPCVOID)(varAddy64::address), &aux_address, 8, NULL);
	return *((double*)&aux_address);
}
float     Addy64::getFloat()
{
	ReadProcessMemory(varAddy64::pHandle, (LPCVOID)(varAddy64::address), &aux_address, 4, NULL);
	return *((float*)&aux_address);
}
int       Addy64::getInt()
{
	ReadProcessMemory(varAddy64::pHandle, (LPCVOID)(varAddy64::address), &aux_address, 4, NULL);
	return *((int*)&aux_address);
}

void	  Addy64::writeDouble(double value)
{
	WriteProcessMemory(varAddy64::pHandle, (LPVOID)(varAddy64::address), &value, sizeof(double), 0);
}
void	  Addy64::writeFloat(float value)
{
	WriteProcessMemory(varAddy64::pHandle, (LPVOID)(varAddy64::address), &value, sizeof(float), 0);
}
void	  Addy64::writeInt(int value)
{
	WriteProcessMemory(varAddy64::pHandle, (LPVOID)(varAddy64::address), &value, sizeof(int), 0);
}
#endif