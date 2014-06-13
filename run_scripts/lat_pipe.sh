#!/system/bin/sh
set -o nounset          # Treat unset variables as an error

lat_pipe -P 1 -W 0 -N 5
sleep 10



lat_pipe -P 3 -W 0 -N 5
sleep 10

