#!/bin/bash 

#是注释，#!才是shebang

int=1
while [ $int -lt 5 ]
do
    echo $int
    let "int++"
done