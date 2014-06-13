#!/bin/bash
set -o nounset          # Treat unset variables as an error
sizes=(32 64 128 256 512 1024 2048 4096 8192)

rm /tmp/test/yy

for size in ${sizes[@]};do
  printf "size=%d\n" $size
  adb shell " binder_test -n 100 -c 2 -s $size" | awk '{printf "%s\t%s\t%s\t%s\t",$2,$6,$7,$8}END{printf "\n"}' >> /tmp/test/yy
  sleep 5
done
