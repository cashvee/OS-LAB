#!/bin/sh

echo "Enter folder path:"
read folder

echo "Enter filename pattern:"
read pattern

# List files in folder matching the pattern in their names
ls "$folder" | grep "$pattern"
