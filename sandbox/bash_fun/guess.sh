#!/usr/bin/env bash

COMPUTER=50
PLAYING=0

while [ $PLAYING -eq 0 ]
do
   read -p "What is you guess? " INPUT
   if [ $INPUT -eq $COMPUTER ]
   then
      echo "You've won! The number was $COMPUTER"
      exit 0
   elif [ $INPUT -lt $COMPUTER ]
   then
      echo "The number was too low..."
   else
      echo "The number was too high..."
   fi
done

exit 0