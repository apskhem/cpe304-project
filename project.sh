#! /usr/local/bin/bash

if [ "$#" -lt 2 ]
then
    echo "error: need a mode argument, e.g ./project.sh run simulator."
elif [ "$1" == "run" ]
then
    if [ "$#" -lt 3 ]
    then
        echo "error: need file path argument to be executed."
    else
        if [ "$2" == "simulator" -o "$2" == "assembler" ]
        then
            g++ src/$2/main.cpp -o build/$2 && ./build/$2 $3
        else
            echo "Invalid mode argument."
        fi
    fi
elif [ "$1" == "build" ]
then
    if [ "$2" == "simulator" -o "$2" == "assembler" ]
    then
        g++ src/$2/main.cpp -o build/$2
    else
        echo "Invalid mode argument."
    fi
else
    echo "Unrecognized command argument."
fi