#!/bin/sh
pfile="$1"; asmfile="${1%%.p}".asm; outfile="${1%%.p}".out
echo "=== PASCAL" &&
cat "$pfile" &&
./pascal "$pfile" &&
echo "=== ASM" &&
cat "$asmfile" &&
echo "=== exec" &&
python3 asm.py "$asmfile" | tee "$outfile"
