# Cpp-Multilevel-Pointers-from-Cheat-Engine

One Paragraph of project description goes here

This library 

## Getting Started

### Project Configuration

1. Solution Plataforms: x64 or x32 (depends if you are using Addy64Lib or Addy32Lib) 

2. Use Multi-Byte Character Set 
   - Solution Properites -> Configuration Properites -> Advanced -> Character Set: Use Multi-Byte Character Set

3. Include the folder named 'include' that contains Addy64Lib.h and Addy32Lib.h
   - Solution Properites -> C/C++ -> Additional Include Directories: "$(ProjectDir)include"


### Tutorial
This function must be called at the beginning of the code.
It find the process handle, process id and the memory address of the module, using the module name and the window name.
```
char moduleName[] = "X-Plane.exe";
char windowName[] = "X-System";

getWindowInfo64(moduleName, windowName);
```
==========================================
==========================================
Create an object and receive as a parameter an array with all the offsets.
```
std::vector<unsigned int> offsets = { 0x02662358, 0x10, 0x10, 0x8, 0x20, 0x18, 0xDC };

Addy64 flaps(offsets);
```
==========================================
==========================================
adasdsadasd
```
flaps.getDouble();
flaps.getFloat();
flaps.getInt();

flaps.writeFloat(2.7f);
flaps.writeDouble(4.5644);
flaps.writeInt(10);
```

### And coding style tests

Explain what these tests test and why

```
Give an example
```

## Deployment

Add additional notes about how to deploy this on a live system
