#!/bin/bash -eu
# OSS-Fuzz compatible build script.
# Environment variables set by the SCAR build-bitcode task (and OSS-Fuzz):
#   $CC, $CXX   — compiler (clang / clang++)
#   $CFLAGS     — base compiler flags (-O0 -g for SCAR static analysis)
#   $SRC        — root of the source tree
#   $WORK       — scratch directory for intermediate objects
#   $OUT        — destination for final binaries

mkdir -p "$WORK"

$CC $CFLAGS -I"$SRC/include" -c "$SRC/main.c"          -o "$WORK/main.o"
$CC $CFLAGS -I"$SRC/include" -c "$SRC/src/input.c"     -o "$WORK/input.o"
$CC $CFLAGS -I"$SRC/include" -c "$SRC/src/process.c"   -o "$WORK/process.o"
$CC $CFLAGS -I"$SRC/include" -c "$SRC/src/output.c"    -o "$WORK/output.o"

$CC $CFLAGS \
    "$WORK/main.o" "$WORK/input.o" "$WORK/process.o" "$WORK/output.o" \
    -o "$OUT/record_tool"
