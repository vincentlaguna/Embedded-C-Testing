#!/usr/bin/env bash

read -p "What is your first name: " NAME
echo "Your name is: $NAME"

VALID=0

while [ $VALID -eq 0 ]
do
   read -p "Please enter name and age: " NAME AGE
   if [[ ( -z $NAME ) || ( -z $AGE)]]
   then
      echo "Not enough parameters passed..."
      continue
   elif [[ ! $NAME =~ ^[A-Za-z]+$ ]] # Alphabetical validation through regex
   then
      echo "Non-alpha characters detected [ $NAME ]"
      continue
   elif [[ ! $AGE =~ ^[0-9]+$ ]] # Numerical validation through regex
   then
      echo "Non-digit characters detected [ $AGE ]"
      continue
   fi
   VALID=1
done

echo "Name = $NAME and Age = $AGE"

exit 0