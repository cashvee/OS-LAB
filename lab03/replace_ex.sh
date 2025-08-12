#!/bin/sh
# Replace 'ex:' with 'Example:' at start of line or after a period in all files in current folder

for file in *; do
  # Check if it is a regular file (ignore directories)
  if [ -f "$file" ]; then
    # Use sed to replace:
    # ^ex:  --> ex: at start of line
    # \.Example: --> ex: after a period
    sed -i.bak -e 's/^ex:/Example:/g' -e 's/\.Example:/\.Example:/g' "$file"
    echo "Modified $file"
  fi
done
