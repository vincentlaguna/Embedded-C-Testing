#!/usr/bin/env bash

echo "The PATH is -> $PATH"
echo "The Terminal is -> $TERM"
echo "The Editor is -> $EDITOR"
# -z checks for an empty string
if [ -z $EDITOR ]
then
   echo "The EDITOR variable is not set"
fi

PATH="/vince"
echo "The PATH is -> $PATH"
