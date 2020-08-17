#!/usr/bin/env bash

FILES=`ls -l | sort -r | head -3`

COUNT=1

for FILE in $FILES
do
   echo "FILE #$COUNT = $FILE"