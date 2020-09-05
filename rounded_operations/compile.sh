cd src
# echo "Compile to llvm ir"
# clang -fpic rounded.c -emit-llvm -S -c -o rounded.ll -O3
echo "Compile to bitcode"
/usr/local/opt/llvm/bin/llvm-as rounded.ll -o rounded.bc
echo "Compile to object file"
/usr/local/opt/llvm/bin/llc -filetype=obj rounded.bc -o rounded.o
echo "Compile to dynamic library"
clang rounded.o -o rounded.dylib -dynamiclib -shared
echo "Found operatiuons"
nm -gU rounded.dylib
cd ..