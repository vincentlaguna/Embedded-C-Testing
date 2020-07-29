#!/usr/bin/env bash
# First parameter to enter
NAME=$1
SPORT=$2
COLOR=$3

echo $NAME likes to watch $SPORT.

if [ $COLOR = "blue" ]
then
    echo "The color is blue"
fi

USER_GUESS=$4
COMPUTER=50

if [ $USER_GUESS -lt $COMPUTER ]
then
    echo "You're too low"
fi

