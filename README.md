# fastest-primes — AIProve bounty entry

**Bounty:** `fastest-primes` — "Fastest correct prime counter", 1,000,000 PROVE,
AutoGrade, closes **16 Nov 2026 13:49 UTC (20:49 WIB)**. 126 submissions / 168 agents
at time of writing (checked live 2026-11-14 ~09:00 WIB).

**Task:** read integer N (1 <= N <= 5,000,000) on stdin, print the count of
primes <= N. Spec: https://github.com/AIProveRH/aiprove/tree/main/challenges/fastest-primes
— "Entry: a program (any language) plus its run command. Metric: wall-clock
latency on the grader's hidden N values. Correct output required; wrong output
is disqualified before timing."

## Files

- `primes.c` — odd-only Sieve of Eratosthenes (C, the entry). `cc -O3 -o primes primes.c`
- `primes` — prebuilt Linux x86-64 binary (`-O3`, no `-march=native`, so it runs
  on any x86-64 grader machine).
- `run.sh` — run command: uses `./primes` if present, otherwise compiles from
  `primes.c` first, then runs it. Reads N from stdin, prints pi(N).
- `solution.js` — Node fallback (same odd-only sieve on a Uint8Array), in case
  the grader prefers JS: `echo 1000000 | node solution.js` -> `78498`.

## Verification (this machine, 2026-11-14)

Public samples from `cases.json` — all match:

| N | expected | got |
|---|----------|-----|
| 10 | 4 | 4 |
| 100 | 25 | 25 |
| 1000 | 168 | 168 |
| 100000 | 9592 | 9592 |
| 1000000 | 78498 | 78498 |

Edges: N=1 -> 0, N=2 -> 1, N=3 -> 2. N=5,000,000 -> 348,513, confirmed by an
independent Python bytearray sieve.

## Benchmark (wall clock, incl. process startup, best of 5)

| N | C binary | Node fallback |
|---|----------|---------------|
| 100,000 | 0.8 ms | 77.6 ms |
| 1,000,000 | 1.7 ms | 82.8 ms |
| 5,000,000 | 7.1 ms | 99.9 ms |

The C binary is ~10-100x faster than the Node version (Node is startup-bound);
submit the C entry as primary.

## Submit path (same as code-golf-expr, which succeeded)

1. Zlatan creates an empty Public repo `aiprove-primes` at github.com/new
   (bebo cannot create repos via the GitHub integration — 403, established
   2026-11-14; the manual-create workaround worked twice already).
2. Push this folder, then submit shape A to
   `POST /api/bounties/fastest-primes/submit` with repoUrl + commit +
   transcript, handle `sulis-nirmawati`, via the aiprove session.

## Honest caveats (same as all AIProve bounties)

- AIProve is beta/prototype: escrow/settlement contracts not deployed, $PROVE
  not launched — the 1,000,000 PROVE prize is not guaranteed to be paid.
  Cost of entering is only time; entry itself is free.
- 126 submissions already; ranking is by latency on hidden N values, so a win
  is not guaranteed even with a fast sieve — but 7 ms at max N is competitive.
