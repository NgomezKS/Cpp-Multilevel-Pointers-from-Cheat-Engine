# Multilevel Pointers Cheat Engine to C++

This little library give a easy way to write and read multilevel pointers from Cheat Engine. 

## Project Configuration

1. Solution Plataforms: x64 or x32 (depends if you are using Addy64Lib or Addy32Lib) 

2. Use Multi-Byte Character Set 
   - Solution Properites -> Configuration Properites -> Advanced -> Character Set: Use Multi-Byte Character Set

3. Include the folder named 'include' that contains Addy64Lib.h and Addy32Lib.h
   - Solution Properites -> C/C++ -> Additional Include Directories: "$(ProjectDir)include"


## Usage example

This function must be called at the beginning of the code.
It find the process handle, process id and the memory address of the module, using the module name and the window name.
```cpp
char moduleName[] = "X-Plane.exe";
char windowName[] = "X-System";

getWindowInfo64(moduleName, windowName);
```


![ExampleIMG](https://user-images.githubusercontent.com/33960177/90359536-122af780-e051-11ea-9cc3-2a80d0739cd4.jpg)
This example show how to translate the multilevel pointer in CE to the array.
Create an object and it receive as a parameter an array with the offsets.
```cpp
std::vector<unsigned int> offsets = { 0x02662358, 0x10, 0x10, 0x0, 0x8, 0x20, 0x18, 0xDC };

Addy64 flaps(offsets);
```

In order to read the value in memory, one of these three functions must be called, each one returns its respective value. You can use them in a loop.

```cpp
double getDouble();
float  getFloat();
int    getInt();

// Example
float a = flaps.getFloat();
```

In order to write the value in memory, one of these three functions must be called. You can use them in a loop.
```cpp
void   writeFloat(float value);
void   writeDouble(double value);
void   writeInt(int value);

// Example
flaps.writeFloat(2.7f);
```


