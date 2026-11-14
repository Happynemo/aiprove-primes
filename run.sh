#!/bin/sh
# fastest-primes run command: prefer the prebuilt binary, compile if missing.
#   ./run.sh < input.txt
# Reads N from stdin, prints pi(N) on stdout.
set -e
cd "$(dirname "$0")"
if [ ! -x ./primes ]; then
  cc -O3 -o primes primes.c
fi
exec ./primes
