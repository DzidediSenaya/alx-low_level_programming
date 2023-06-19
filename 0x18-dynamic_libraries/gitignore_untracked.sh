#!/bin/bash

untracked_files=$(git status --porcelain | grep "^??" | cut -c4-)

if [ -n "$untracked_files" ]; then
    echo "$untracked_files" >> .gitignore
fi

