#!/usr/bin/env bash

read -p "enter a number: " -r n

sum_all=0
for (( i=1; i<=n; i++ )); do
  sum_all=$(( sum_all + i ))
done

echo "sum = $sum_all"

