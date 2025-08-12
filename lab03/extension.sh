#!/bin/sh
# Script to rename all .txt files to .text recursively

find . -type f -name "*.txt" | while read file; do
  # Get the new filename by replacing .txt with .text
  newfile=$(echo "$file" | sed 's/\.txt$/.text/')
  
  # Rename the file
  mv "$file" "$newfile"
  
  echo "Renamed: $file -> $newfile"
done
