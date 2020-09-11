#!/usr/bin/bash
# This is a basic bash script using the case statement
while getopts u:p:ab option; do
   case $option in
      u) user=$OPTARG;;
      p) user=$OPTARG;;
   esac
done

echo "User: $user / Pass: $pass"