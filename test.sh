#!/bin/sh
pfile="$1"; suffix="$2"
prefix="${1%%.p}"; asmfile="${prefix}.asm"; outfile="${prefix}.out${suffix}"; infile="${prefix}.in${suffix}"
echo "=== $pfile" &&
cat -n "$pfile" &&
./pascal "$pfile" &&
echo "=== $asmfile" &&
cat -n "$asmfile" &&
echo "=== $outfile" &&
tee "$infile" | python3 asm.py "$asmfile" | tee "$outfile"
