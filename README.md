# scar-test-c

Minimal vulnerable C files for testing the [SCAR](https://github.com/johwes/SCAR) pipeline.

| File | CWE | IKOS checker |
|---|---|---|
| `bof.c` | CWE-121 Stack-based buffer overflow | `boa` |
| `oob_read.c` | CWE-125 Out-of-bounds read | `boa` |
| `divzero.c` | CWE-369 Divide by zero | `dbz` |
| `nullderef.c` | CWE-476 NULL pointer dereference | `nullity` |
