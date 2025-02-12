#!/bin/bash

read -p "Enter number of terms: " num

a=0
b=1

echo -n "The series: "
for ((i = 0; i < num; i++)); do
  echo -n "$a "
  next=$((a + b))
  a=$b
  b=$next
done
