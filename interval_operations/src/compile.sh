# echo "Compile to llvm ir"
g++ -fpic interval.cc -emit-llvm -S -c -o interval.ll -O1

unameOut="$(uname -s)"
case "${unameOut}" in
    Linux*)     machine=Linux;;
    Darwin*)    machine=Mac;;
    CYGWIN*)    machine=Cygwin;;
    MINGW*)     machine=MinGw;;
    *)          machine="UNKNOWN:${unameOut}"
esac
echo ${machine}

if [ "${machine}" == "Mac" ]; then
    echo "Compile to bitcode"
    /usr/local/opt/llvm/bin/llvm-as interval.ll -o interval.bc
    echo "Compile to object file"
    /usr/local/opt/llvm/bin/llc -filetype=obj interval.bc -o interval.o
    echo "Compile to dynamic library"
    gcc interval.o -o interval.dylib -dynamiclib -shared
    echo "Compile to shared object"
    gcc interval.o -o interval.so -shared
    echo "Found operations of dylib"
    nm -gU interval.dylib
elif [ "${machine}" == "Linux" ]; then
    less interval.ll
    echo "Compile to bitcode"
    llvm-as interval.ll -o interval.bc
    echo "Compile to object file"
    llc -filetype=obj interval.bc -o interval.o
    echo "Compile to dynamic library"
    gcc interval.o -o interval.dylib -dynamiclib -shared
    echo "Compile to shared object"
    gcc interval.o -o interval.so -shared
    echo "Found operations of so"
    nm -gD interval.so
fi
