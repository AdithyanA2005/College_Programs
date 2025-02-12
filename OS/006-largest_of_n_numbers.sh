#!/bin/bash

declare -a arr

read -p "Enter array elements: " -a arr

echo -n "The elements of array: "

for element in ${arr[@]}; do
  echo -n "$element "
done

largest=${arr[0]}

for element in ${arr[@]}; do
  if [ $element -gt $largest ]; then
    largest=$element
  fi
done

echo -e "\nThe largest element is $largest"
