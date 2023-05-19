#!/bin/bash

echo "Enter array elements: "
read -a arr

smallest=${arr[0]}

for i in "${arr[@]}"
do
    if [ $i -lt $smallest ]
    then
        smallest=$i
    fi
done

echo "Smallest element in the array is: $smallest"

