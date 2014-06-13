#!/system/bin/sh
set -o nounset          # Treat unset variables as an error

bw_pipe -m 1000 -M 1000 -P 1 -W 0 -N 5
sleep 10
bw_pipe -m 2000 -M 2000 -P 1 -W 0 -N 5
sleep 10
bw_pipe -m 4000 -M 4000 -P 1 -W 0 -N 5
sleep 10
bw_pipe -m 8000 -M 8000 -P 1 -W 0 -N 5
sleep 10
bw_pipe -m 16000 -M 16000 -P 1 -W 0 -N 5
sleep 10
bw_pipe -m 32000 -M 32000 -P 1 -W 0 -N 5
sleep 10
bw_pipe -m 64000 -M 64000 -P 1 -W 0 -N 5
sleep 10

bw_pipe -m 1000 -M 1000 -P 3 -W 0 -N 5
sleep 10
bw_pipe -m 2000 -M 2000 -P 3 -W 0 -N 5
sleep 10
bw_pipe -m 4000 -M 4000 -P 3 -W 0 -N 5
sleep 10
bw_pipe -m 8000 -M 8000 -P 3 -W 0 -N 5
sleep 10
bw_pipe -m 16000 -M 16000 -P 3 -W 0 -N 5
sleep 10
bw_pipe -m 32000 -M 32000 -P 3 -W 0 -N 5
sleep 10
bw_pipe -m 64000 -M 64000 -P 3 -W 0 -N 5


