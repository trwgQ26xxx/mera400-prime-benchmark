# MERA-400 Prime Search Test

This project is a small programming exercise in the style of classic **K&R C**. It searches for the **2000th prime number**, which is **17389**, and compares two trial-division strategies on a MERA-400 emulator.

Contact : trwgQ {leechers not welcome} 26 {remove spaces} xxx {remove spaces} {at} proton {dot} me

## Compilation on MERA-400

- Compile `prime.c` to `p.obj` : `cc0 prime p`
- Link `p.obj` to `pri.bin` : `ln p clib mlib ?out pri`
- Run `pri.bin` : `pri`

## Algorithm

For each candidate number, the program tests successive divisors until it can prove the number is composite or prime. Two variants were evaluated:

### `sqrt(N)`

Only divisors up to the square root of the tested number are checked.

This is enough because any composite number must have at least one factor not greater than its square root. The tradeoff is that every candidate also requires a `sqrt()` call.

### `N / 2`

Divisors are checked up to half of the tested number.

This avoids the square-root calculation and uses only integer arithmetic, but it performs many more divisor tests, especially for prime numbers.

## Performance Note

The number of divisor checks does not directly determine runtime.

The `sqrt(N)` version performs fewer checks, but it must evaluate a square root for each tested number. The `N / 2` version avoids `sqrt()`, but it pays for that with many more divisions and loop iterations.

On modern hardware the difference is small. On historical systems such as the MERA-400, the extra work becomes clearly visible, which makes this a good demonstration of why algorithm choice matters.

## Results

| Variant | Computation Time | Max. Checks per Number | Total Checks |
| --- | ---: | ---: | ---: |
| `sqrt(N)` | 37 s | 132 | 248,992 |
| `N / 2` | 14 min 40 s | 8,694 | 8,218,349 |

# License

Shield: [![CC BY-NC-SA 4.0][cc-by-nc-sa-shield]][cc-by-nc-sa]

This work is licensed under a
[Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License][cc-by-nc-sa].

[![CC BY-NC-SA 4.0][cc-by-nc-sa-image]][cc-by-nc-sa]

[cc-by-nc-sa]: http://creativecommons.org/licenses/by-nc-sa/4.0/
[cc-by-nc-sa-image]: https://licensebuttons.net/l/by-nc-sa/4.0/88x31.png
[cc-by-nc-sa-shield]: https://img.shields.io/badge/License-CC%20BY--NC--SA%204.0-lightgrey.svg
