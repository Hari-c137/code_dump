
#!/usr/bin/env bash

read -p "enter a number: " -r n

sum_even=0
for (( i=1; i<=n; i++ )); do
  if (( i % 2 == 0 )); then
   sum_even=$(( sum_even + i ))
  fi
done

echo "sum = $sum_even"
