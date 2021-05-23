#!/usr/bin/env bash

cd build

rm -r *

cmake ..

make

./testRunner

exit 0
