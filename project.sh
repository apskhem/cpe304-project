#! /usr/local/bin/bash

if [ "$#" -eq 0 ]
then
    echo "Need at a single execute command argument."
elif [ "$1" == "run" ]
then
    if [ "$#" -lt 2 ]
    then
        echo "Need a file destination path to be read."
    else
        g++ src/main.cpp -o build/out && ./build/out $2
    fi
elif [ "$1" == "build" ]
then
    g++ src/main.cpp -o build/out
else
    echo "Unrecognized command argument."
fi