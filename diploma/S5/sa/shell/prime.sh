#!/usr/bin/env bash

read -p "enter a number: " -r n
for (( i = 2; i * i <= n; i++ )); do
  if (( "$n" % "$i" != 0)); then
    echo "prime"
    exit 0
  fi
done
echo "not prime"

