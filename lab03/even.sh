#!/bin/sh
# Script to delete even-numbered lines from a file

echo "Enter the filename:"
read filename

if [ ! -f "$filename" ]; then
  echo "File does not exist."
  exit 1
fi

# Using sed to print only odd lines
sed -n 'p;n' "$filename"
