#!/usr/bin/env bash

read -p "enter a number: " -r n

sum_odd=0
for (( i=1; i<=n; i++ )); do
  if (( i % 2 != 0 )); then
   sum_odd=$(( sum_odd + i ))
  fi
done

echo "sum = $sum_odd"
