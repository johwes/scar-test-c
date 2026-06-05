# scar-test-c

Minimal vulnerable C files for testing the [SCAR](https://github.com/johwes/SCAR) pipeline end-to-end.

Each file contains exactly one vulnerability targeting a specific IKOS checker.

| File | CWE | IKOS checker | Detected? |
|---|---|---|---|
| `bof.c` | CWE-121 Stack-based buffer overflow via `strcpy` | `boa` | No — IKOS does not model string lengths (known gap) |
| `oob_read.c` | CWE-125 Out-of-bounds read | `boa` | Yes |
| `divzero.c` | CWE-369 Divide by zero | `dbz` | Yes |
| `nullderef.c` | CWE-476 NULL pointer dereference | `nullity` | Yes |
| `uninit.c` | CWE-457 Use of uninitialized variable | `uva` | Yes |
| `signedoverflow.c` | CWE-190 Signed integer overflow | `sio` | Yes |
| `doublefree.c` | CWE-415 Double free | `dfa` | Yes |

## Purpose

`bof.c` is deliberately included to illustrate the string-function gap in IKOS — a `strcpy` overflow that the scanner cannot detect. All other files are expected to be flagged and patched by the SCAR repair loop.
