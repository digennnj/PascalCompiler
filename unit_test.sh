#!/bin/bash
shopt -s nullglob
good() { echo -n $'\033[32m'"$@"$'\033[m';}
bad() { echo -n $'\033[31m'"$@"$'\033[m';}
for test_dir in "$@"; do
    echo -n "asm: "
    for asm_file in "${test_dir}/"*.asm.good; do
        prefix="${asm_file%%.asm.good}"
        name="${prefix##$test_dir/}"
        p_file="${prefix}".p
        test_file="${prefix}".asm
        if [[ ! -f "$p_file" ]]; then echo -n "[skip ${name}] "; continue; fi
        ./pascal "$p_file" &>/dev/null
        diff "${asm_file}" "${test_file}" &>/dev/null && good "${name} " || bad "${name} "
    done
    echo
    echo -n "exec: "
    for out_file in "${test_dir}/"*.out.good; do
        prefix="${out_file%%.out.good}"
        name="${prefix##$test_dir/}"
        in_file="${prefix}".in.good
        asm_file="${prefix}".asm.good
        test_file="${prefix}".out
        if [[ ! -f "$asm_file" ]]; then echo -n "[skip ${name}] "; continue; fi
        if [[ -f "$in_file" ]]; then cat "$in_file" | ./asm.py "$asm_file" >"${test_file}";
        else ./asm.py "$asm_file" | tee "${test_file}"; fi
        diff "${out_file}" "${test_file}" &>/dev/null && good "${name} " || bad "${name} "
    done
    echo
done
