#!/usr/bin/env bash
function GetFiles() {
   FILES=`ls -l | sort | head -10`
}

function ShowFiles() {
   local COUNT=1
   for FILE in $@
   do
      echoo "FILE #$COUNT = $FILE"
   done
}