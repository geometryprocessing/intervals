# echo "Compile to llvm ir"
# clang++ -fpic interval_c.cc -emit-llvm -S -c -o interval_c.ll -O1

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
    echo "Compile to dylib"
    clang++ -fpic -shared -dynamiclib interval_c.cc -c -o interval_c.dylib -O1
    # echo "Compile to bitcode"
    # /usr/local/opt/llvm/bin/llvm-as interval_c.ll -o interval_c.bc
    # echo "Compile to object file"
    # /usr/local/opt/llvm/bin/llc -filetype=obj interval_c.bc -o interval_c.o
    # echo "Compile to dynamic library"
    # gcc interval_c.o -o interval_c.dylib -dynamiclib -shared
    # echo "Compile to shared object"
    # gcc interval_c.o -o interval_c.so -shared
    echo "Found operations of dylib"
    nm -gU interval_c.dylib
elif [ "${machine}" == "Linux" ]; then
    echo "Compile to so"
    gcc -shared -o libinterval_c.so -fPIC -O1 interval_c.cc
    ls
    # echo "Compile to bitcode"
    # llvm-as interval_c.ll -o interval_c.bc
    # echo "Compile to object file"
    # llc -filetype=obj interval_c.bc -o interval_c.o
    # echo "Compile to dynamic library"
    # gcc interval_c.o -o interval_c.dylib -dynamiclib -shared
    # echo "Compile to shared object"
    # gcc interval_c.o -o interval_c.so -shared
    echo "Found operations of so"
    nm -gD libinterval_c.so
fi
