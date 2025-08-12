#!/bin/sh
# Script to check if a file is a directory or regular file

echo "Enter the file name:"
read filename

if [ -d "$filename" ]; then
  echo "$filename is a directory."
elif [ -f "$filename" ]; then
  echo "$filename is a regular file."
else
  echo "$filename is neither a regular file nor a directory."
fi 
# fi ends the if block

