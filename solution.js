// fastest-primes (Node fallback): count primes <= N.
// Odd-only sieve on a Uint8Array. Reads N from stdin, prints pi(N).
// Run: echo 1000000 | node solution.js   -> 78498
const fs = require('fs');
const n = parseInt(fs.readFileSync(0, 'utf8').trim(), 10);
if (!(n >= 2)) { console.log(0); process.exit(0); }
const m = (n + 1) >> 1; // odds <= n, index i -> 2*i+1
const comp = new Uint8Array(m);
for (let p = 3; p * p <= n; p += 2) {
  if (!comp[p >> 1]) {
    const step = p << 1;
    for (let j = p * p; j <= n; j += step) comp[j >> 1] = 1;
  }
}
let cnt = 1; // prime 2
for (let i = 1; i < m; i++) if (!comp[i]) cnt++;
console.log(cnt);
