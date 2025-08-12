#!/bin/sh
# Script to copy files with a given extension to a given folder (single level)

echo "Enter the file extension (with dot), e.g., .text:"
read ext

echo "Enter the destination folder name:"
read dest_folder

# Create destination folder if it doesn't exist
if [ ! -d "$dest_folder" ]; then
  mkdir "$dest_folder"
fi

# Loop through files in current directory with the given extension
for file in *"$ext"; do
  # Check if it's a regular file (not a directory or something else)
  if [ -f "$file" ]; then
    cp "$file" "$dest_folder/"
    echo "Copied $file to $dest_folder/"
  fi
done
