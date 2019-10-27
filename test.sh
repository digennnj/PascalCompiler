#!/bin/sh
pfile="$1"; asmfile="${1%%.p}".asm
echo "=== PASCAL" &&
cat "$pfile" &&
./pascal "$pfile"
echo "=== ASM" &&
cat "$asmfile" &&
echo "=== exec" &&
python3 asm.py "$asmfile"
