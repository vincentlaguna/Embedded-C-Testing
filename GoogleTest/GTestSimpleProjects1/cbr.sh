#!/usr/bin/env bash

cd build

rm -r *

cmake ..

make

if [ -x testRunner ];
then
	./testRunner
else
	./myExecutable
fi

exit 0
