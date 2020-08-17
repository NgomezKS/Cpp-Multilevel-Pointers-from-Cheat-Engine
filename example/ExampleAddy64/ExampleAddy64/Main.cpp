#include <iostream>
#include <Addy64Lib.h>

/*
Project configuration.

	1.- Solution Plataforms: x64
	2.- Solution Properites -> Configuration Properites -> Advanced -> Character Set: "Use Multi-Byte Character Set"
	3.- Solution Properites -> C/C++ -> Additional Include Directories: Search and include the folder named 'include' that contains Addy64Lib.h

*/

char moduleName[] = "X-Plane.exe";
char windowName[] = "X-System";

int main()
{	
	float value;
	float newValue = 1.0f;

	// Offsets array
	std::vector<unsigned int> offsets = { 0x02662358, 0x10, 0x10, 0x8, 0x20, 0x18, 0xDC };

	// Gets the process handle and the base address
	getWindowInfo64(moduleName, windowName);

	// Creation of the flaps object and insert the offset array 
	Addy64 flaps(offsets);

	// Printing the actually value of flaps
	value = flaps.getFloat();
	std::cout << "Flaps position: " << flaps.getFloat() << std::endl;
	
	// Writing a new value in the flap direction
	flaps.writeFloat(newValue);
	std::cout << "New flaps position: " << flaps.getFloat() << std::endl;
}