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


### How works

This function must be called at the beginning of the code.
It find the process handle, process id and the memory address of the module, using the module name and the window name

```
char moduleName[] = "X-Plane.exe";
char windowName[] = "X-System";

void getWindowInfo64(moduleName, windowName);
```


And repeat

```
until finished
```


End with an example of getting some data out of the system or using it for a little demo


### And coding style tests

Explain what these tests test and why

```
Give an example
```

## Deployment

Add additional notes about how to deploy this on a live system
