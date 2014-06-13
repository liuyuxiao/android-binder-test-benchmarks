#!/system/bin/sh
set -o nounset          # Treat unset variables as an error
bw_tcp -s
sleep 5


bw_tcp -m 1000 -M 1000 -P 1 -W 0 -N 5  127.0.0.1
sleep 10
bw_tcp -m 2000 -M 2000 -P 1 -W 0 -N 5 127.0.0.1
sleep 10
bw_tcp -m 4000 -M 4000 -P 1 -W 0 -N 5 127.0.0.1
sleep 10
bw_tcp -m 8000 -M 8000 -P 1 -W 0 -N 5 127.0.0.1
sleep 10
bw_tcp -m 16000 -M 16000 -P 1 -W 0 -N 5 127.0.0.1
sleep 10
bw_tcp -m 32000 -M 32000 -P 1 -W 0 -N 5 127.0.0.1
sleep 10
bw_tcp -m 64000 -M 64000 -P 1 -W 0 -N 5 127.0.0.1
sleep 10

bw_tcp -m 1000 -M 1000 -P 3 -W 0 -N 5  127.0.0.1
sleep 10
bw_tcp -m 2000 -M 2000 -P 3 -W 0 -N 5 127.0.0.1
sleep 10
bw_tcp -m 4000 -M 4000 -P 3 -W 0 -N 5 127.0.0.1
sleep 10
bw_tcp -m 8000 -M 8000 -P 3 -W 0 -N 5 127.0.0.1
sleep 10
bw_tcp -m 16000 -M 16000 -P 3 -W 0 -N 5 127.0.0.1
sleep 10
bw_tcp -m 32000 -M 32000 -P 3 -W 0 -N 5 127.0.0.1
sleep 10
bw_tcp -m 64000 -M 64000 -P 3 -W 0 -N 5 127.0.0.1



