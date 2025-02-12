#!/bin/bash

read -p "Enter a number: " num

isPrime=1

if [ $num -le 1 ]; then
  isPrime=0
else
  for ((i = 2; i < num; i++)); do
    if [ $((num % i)) -eq 0 ]; then
      isPrime=0
      break
    fi
  done
fi

if [$isPrime -eq 1]; then
  echo "$num is a prime number"
else
  echo "$num is not a prime number"
fi
