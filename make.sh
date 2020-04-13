#! /bin/bash

executable=$1

mkdir -p bin
rm -rf *.o
echo "compiling..."
gcc -c *.c
echo "done"
gcc -o ./bin/$executable *.o && ./bin/$executable
rm -rf *.o