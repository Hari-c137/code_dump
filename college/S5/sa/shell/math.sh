#!/usr/bin/env bash

echo "factorial"
echo "palindrome"
echo "prime"
echo "fibonacci"
echo "armstrongcheck"
echo "sumofnum"
echo "sumofodd"
echo "sumofeven"
echo "nnuma"
echo "nnumr"

read -p "select mode: " -r m

while true; do
    case $m in
    factorial)
        read -p "enter number: " -r n
        fac=1
        for ((i = 1; i <= n; i++)); do
            fac=$((fac * i)) # syntax
        done
        echo "factorial of $n is $fac"
        break
        ;;
    palindrome)
        read -p "enter string or number: " -r str
        rever=$(echo "$str" | rev)
        if [[ "$str" == "$rever" ]]; then ## dont use -eq operator
            echo "it is palindrome"
        else
            echo "it is not palindrome"
        fi
        break
        ;;
    prime)
        read -p "enter number: " -r p
        for ((i = 2; i <= "$p" / 2; i++)); do
            a=$((n % i))
            if [ $a -eq 0 ]; then
                echo "$n is not a prime number."
                exit 0
            fi
        done
        echo "prime"
        break
        ;;
    fibonacci)
        read -p "Enter number of terms: " -r n
        a=0
        b=1
        for ((i = 0; i < n; i++)); do
            echo -n "$a "
            b=$((a + b))
            a=$((b - a))
        done
        echo
        break
        ;;
    armstrongcheck)
        read -p "enter a number: " -r n
        arm=0
        temp=$n
        while [ "$n" -ne 0 ]; do
            r=$((n % 10))
            arm=$((arm + r * r * r))
            n=$((n / 10))
        done
        echo $arm
        if [ $arm -eq "$temp" ]; then
            echo "Armstrong"
        else
            echo "Not Armstrong"
        fi
        break
        ;;
    sumofnum)
        sum_all=0
        read -p "Enter numbers: " -r n

        while true; do
            sum_all=$((sum_all + n))
        done
        echo "Sum of all numbers: $sum_all"

        ;;
    sumofodd)

        sum_odd=0
        read -p "Enter numbers: " -r n

        while true; do
            if ((n % 2 != 0)); then
                sum_odd=$((sum_odd + n))
            fi
        done
        echo "Sum of odd numbers: $sum_odd"

        ;;
    sumofeven)

        sum_even=0
        read -p "Enter numbers: " -r n

        while true; do
            if ((n % 2 == 0)); then
                sum_even=$((sum_even + n))
            fi
        done

        echo "Sum of even numbers: $sum_even"

        ;;
    nnuma)
        read -p "enter the limit: " -r n
        for ((i = 0; i <= n; i++)); do echo "$i"; done
        break
        ;;
    nnumr)
        read -p "enter the limit: " -r n
        for ((i = n; i >= 0; i--)); do echo "$i"; done
        break
        ;;
    esac

done
