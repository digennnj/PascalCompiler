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
        asm_file="${prefix}".asm.good
        p_file="${prefix}".p
        testasm_file="${prefix}".asm

        if [[ -f "$p_file" && -f "$asm_file" ]]; then
            ./pascal "$p_file" &>/dev/null
            diff "${asm_file}" "${testasm_file}" &>/dev/null && good "asm " || bad "asm "
        fi

        out_files=("${prefix}".out*.good)
        for out_file in "${out_files[@]}"; do
            suffix="${out_file##$prefix.out}"
            suffix="${suffix%%.good}"
            in_file="${prefix}".in"${suffix}".good
            testout_file="${prefix}".out"${suffix}"
            if [[ -f "$asm_file" && -f "$out_file" && -f "$in_file" ]]; then
                cat "$in_file" | ./asm.py "$asm_file" 2>/dev/null >"${testout_file}"
                diff "${out_file}" "${testout_file}" &>/dev/null && good "out${suffix} " || bad "out${suffix} "
            fi
        done
        echo
    done
done
