#!/bin/bash
read n1
n2=1
n3=0
n4=0
n5=0
while [ $n4 -lt $n1 ]
    do 
        let " n5 = $n2 + $n3"
        n2=$n3
        n3=$n5
        let " n4 = $n4 + 1"
    done
echo $n5
