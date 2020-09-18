# echo "Compile to llvm ir"
# clang++ -fpic interval.cc -emit-llvm -S -c -o interval.ll -O1
echo "Compile to bitcode"
/usr/local/opt/llvm/bin/llvm-as interval.ll -o interval.bc
echo "Compile to object file"
/usr/local/opt/llvm/bin/llc -filetype=obj interval.bc -o interval.o
echo "Compile to dynamic library"
clang interval.o -o interval.dylib -dynamiclib -shared
echo "Compile to shared object"
clang interval.o -o interval.so -shared
echo "Found operations of dylib"
nm -gU interval.dylib
echo "Found operations of so"
nm -gD interval.so
