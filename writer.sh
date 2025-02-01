#!/bin/bash

# writer.sh - Creates or overwrites a file with specified content
if [ $# -ne 2 ]; then
    echo "Error: Missing arguments"
    echo "Usage: $0 <file_path> <content>"
    exit 1
fi

writefile=$1
writestr=$2

dirname=$(dirname "$writefile")

if [ ! -d "$dirname" ]; then
    mkdir -p "$dirname" || { echo "Error: Failed to create directory '$dirname'"; exit 1; }
fi

echo "$writestr" > "$writefile" || { echo "Error: Failed to write to file '$writefile'"; exit 1; }

exit 0
