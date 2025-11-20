#!/usr/bin/env bash

read -p "enter the number: " -r n
fac=1
for (( i = 1; i <= n; i++ )); do
    fac=$(( fac * i ))
done
echo "the factorial of $n is $fac"
