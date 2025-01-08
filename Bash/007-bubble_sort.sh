#!/bin/bash

# Prompt the user for the number of elements
read -p "Enter the number of elements: " n

# Declare an array
declare -a arr

# Read array elements from the user
read -p "Enter elements: " -a arr

# Bubble Sort logic
for ((i = 0; i < n - 1; i++)); do
  for ((j = 0; j < n - i - 1; j++)); do
    # Correctly compare the adjacent elements
    if [ "${arr[j]}" -gt "${arr[j + 1]}" ]; then
      # Swap the elements
      temp="${arr[j]}"
      arr[j]="${arr[j + 1]}"
      arr[j + 1]="$temp"
    fi
  done
done

# Output the sorted array
echo -n "Sorted array: "
for element in "${arr[@]}"; do
  echo -n "$element "
done
echo # Newline after printing the sorted arrayo
