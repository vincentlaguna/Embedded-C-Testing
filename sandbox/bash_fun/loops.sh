#!/usr/bin/env bash
COUNT=0
NAMES=$@
END=$1

while [ $COUNT -lt $END ]
do
  echo "COUNT = $COUNT"
  ((COUNT++))
done

echo "While loop finished."

for NAME in $NAMES
do
  if [ $NAME = "Vincent" ]
  then
    continue # Skips and continues
    #break # Completely breaks out of the loop
  fi
  echo "Hello $NAME"
done

echo "For loop terminated."
exit 0