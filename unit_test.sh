#!/bin/bash
shopt -s nullglob
shopt -s globstar
good() { echo -n $'\033[32m'"$@"$'\033[m';}
bad() { echo -n $'\033[31m'"$@"$'\033[m';}
test_dirs=("$@")
if [[ $# -lt 1 ]]; then test_dirs=(TestCases/); fi
for test_dir in "${test_dirs[@]}"; do
    find "${test_dir}" -name '*.asm.good' -o -name '*.out.good' | sed -E 's/\.(asm|out)\.good$//g' | sort -u | while read prefix; do
        echo -n "${prefix}: "
        name="${prefix##$test_dir/}"
        in_file="${prefix}".in.good
        asm_file="${prefix}".asm.good
        out_file="${prefix}".out.good
        p_file="${prefix}".p
        testasm_file="${prefix}".asm
        testout_file="${prefix}".out

        if [[ -f "$p_file" && -f "$asm_file" ]]; then
            ./pascal "$p_file" &>/dev/null
            diff "${asm_file}" "${testasm_file}" &>/dev/null && good "asm " || bad "asm "
        fi

        if [[ -f "$asm_file" && -f "$out_file" ]]; then
            if [[ -f "$in_file" ]]; then cat "$in_file" | ./asm.py "$asm_file" 2>/dev/null >"${testout_file}";
            else ./asm.py "$asm_file" 2>/dev/null | tee "${testout_file}"; fi
            diff "${out_file}" "${testout_file}" &>/dev/null && good "out " || bad "out "
        fi
        echo
    done
done
