#!/usr/bin/env bash

DELAY=$1

if [ -z $DELAY ]
then
   echo "You must supply a delay"
   exit1
fi

echo "Going to sleep for $DELAY seconds"

sleep $DELAY

echo "The Sleeper Has Awakened!"

exit 0 

# To put a script to sleep: >./delay.sh 5 &