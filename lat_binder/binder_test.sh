#!/bin/bash
set -o nounset          # Treat unset variables as an error

for((i=1; i<33; i*=2));
do
    binger_test -c $i -o binder_test_$i.log
    sleep 5
    done
