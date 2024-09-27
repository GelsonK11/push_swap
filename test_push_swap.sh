#!/bin/bash

while [ 1 ]; do
    ARG=($(seq -1000 1000 | shuf -n 500))
    if ./push_swap "${ARG[@]}" | ./checker_linux "${ARG[@]}"; then
        ./push_swap "${ARG[@]}" | wc -l
    else
        echo "Checker failed for: ${ARG[@]}"
    fi
    sleep 0.1
done
