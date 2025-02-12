#!/bin/bash

read -p "Enter a number: " num
fact=1

while [ $num -gt 0 ]; do
  fact=$((fact * num))
  num=$((num - 1))
done

echo "The factorial is $fact"
