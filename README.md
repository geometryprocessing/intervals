# Cross-platform Interval Library

## Compile the C file to dynamic library

Go to rounded_operations folder, in there, you will find compile.sh

The compile script is used to compile the C file first to llvm ir, then byte code, then object file, then a dynamic library

The line to compile C file to llvm ir is commented since tweaking the llvm ir is required, then the rest can be called

## Linking to main

After you get a dylib file, go to the main directory, and do the following:

```bash
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make
```

Currently the make process will fail since rounded.h file is not found, which is weird since it should be included inside the dylib file