#!/bin/bash

DIR="${HOME}/Documents/P0065_ESP32-WROVER/P0065_ESP32-WROVER-Platform/"

find_rst() {
    find ${DIR} -type f -name \*.rst -and -not -path \*esp\-idf\*
}

sync() {
    for file in $(find_rst); do
        new_file=$(echo $file | sed "s|${DIR}||")
        mkdir -p $(dirname ${new_file})
        cp -v ${file} ${new_file}
    done
    git add .
    git commit -a --amend -m "Sync"
    git push --force
}

if [ -z "$1" ]; then
    while true; do find_rst  | entr -ds './sync.sh do'; done
else
    sync
fi
