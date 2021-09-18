#! /usr/local/bin/bash

if [ "$#" -eq 0 ]
then
    echo "Need at a single execute command argument."
elif [ "$1" == "run" ]
then
    g++ src/main.cpp -o build/out && ./build/out
elif [ "$1" == "build" ]
then
    g++ src/main.cpp -o build/out
else
    echo "Unrecognized command argument."
fi