#!/bin/zsh

clear_console=true
output=""
error=""

while true; do
    if [ "$clear_console" = true ]; then
        clear
        echo "$output"
        echo "$error"
        clear_console=false
    fi

    clear
    echo "Watching addons for changes ..."
    inotifywait -e close_write ./addons/*.cpp &>/dev/null
    output=$(node-gyp configure && node-gyp build 2>&1)
    if [ $? -eq 0 ]; then
        output=$(./node-gyp configure && node-gyp build)
        error=""
    else
        error="$output"
        output=""
    fi
    clear_console=true
done

