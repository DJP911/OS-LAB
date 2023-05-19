#!/bin/bash

echo "Enter a number: "
read num

factorial=1

for (( i=$num; i>=1; i-- ))
do
    factorial=$((factorial * i))
done

echo "Factorial of $num is: $factorial"

