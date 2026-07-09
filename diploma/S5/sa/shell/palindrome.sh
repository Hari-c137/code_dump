#!/usr/bin/env bash

read -p "enter a string or number: " -r str

rstr=$(echo "$str" | rev)
if [[ "$str" == "$rstr" ]]; then
    echo "it is a palindrome"
else
    echo "not a palindrome"
fi
