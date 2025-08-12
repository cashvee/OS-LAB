

# Test Shell Script

## Usage

Run the script from the terminal by passing arguments as inputs. For example:

```bash
./demo.sh hello world
```

---

## Script Content (`demo.sh`)

```sh
#!/bin/sh
# to check shell family being used : echo $SHELL

echo "Script Name: $0"
echo "First Argument: $1"
echo "Shell family: $SHELL"
echo "Second argument: $2"
echo "Total Arguments: $#"
echo "All arguments: $*"
```

---

## Sample Output

When running the command:

```bash
./demo.sh hello world
```

The output will be:

```
Script Name: ./demo.sh
First Argument: hello
Shell family: /bin/bash
Second argument: world
Total Arguments: 2
All arguments: hello world
```

---

## Explanation

* **`$0`**: Name of the script.
* **`$1`**: First argument passed to the script (`hello` in this example).
* **`$SHELL`**: The current shell being used (e.g., `/bin/bash`).
* **`$2`**: Second argument passed to the script (`world` in this example).
* **`$#`**: Total number of arguments passed to the script (`2` here).
* **`$*`**: All arguments passed to the script as a single string (`hello world` here).

---

# Q1]
## Write a shell script to find whether a given file is the directory or regular file. 

## Command/Usage
```bash
#!/bin/sh
# Script to check if a file is a directory or regular file - COMMENT
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

```  

to make it executable - on the terminal run:
``` bash
chmod +x find.sh
```

```
./find.sh
```

```
Enter the file name:
demo.sh
demo.sh is a regular file.
```
---
# Q2]
## Write a shell script to list all files (only file names) containing the input pattern (string) in the folder entered by the user. 

## Command/Usage
```
nano pattern.sh 
```
content inside pattern.sh
```
#!/bin/sh

echo "Enter folder path:"
read folder

echo "Enter filename pattern:"
read pattern

# List files in folder matching the pattern in their names
ls "$folder" | grep "$pattern"
```
execute using:
```
chmod +x pattern.sh
```
running file: 
```
./pattern.sh
Enter folder path:
. //current path
Enter filename pattern:
yo      
you1.txt
you2.txt
```
---
# Q3]
## Write a shell script to replace all files with .txt extension with .text in the current directory. This has to be done recursively i.e if the current folder contains a folder “OS” with abe.txt then it has to be changed to abc.text ( Hint: use find, mv ) 

## Command/Usage
create file 
```
nano extension.sh
```
content of extension.sh
```
#!/bin/sh
# Script to rename all .txt files to .text recursively

find . -type f -name "*.txt" | while read file; do
  # Get the new filename by replacing .txt with .text
  newfile=$(echo "$file" | sed 's/\.txt$/.text/')
  
  # Rename the file
  mv "$file" "$newfile"
  
  echo "Renamed: $file -> $newfile"
done
```
making extension.sh executable
```
chmod +x extension.sh
```
running extension.sh
```
./extension.sh
Renamed: ./LAB03.txt -> ./LAB03.text
Renamed: ./you2.txt -> ./you2.text
Renamed: ./you1.txt -> ./you1.text
```
---
# Q4]
## Write a shell script to calculate the gross salary. GS=Basics + TA + 10% of Basics. Floating point calculations has to be performed. 

## Command/Usage
create file 
```
nano salary.sh
```
content of salary.sh
```
#!/bin/sh
# Script to calculate Gross Salary with floating point arithmetic

echo "Enter Basics salary:"
read basics

echo "Enter TA:"
read ta

# Calculate 10% of Basics
ten_percent=$(echo "scale=2; $basics * 0.10" | bc)

# Calculate Gross Salary
gs=$(echo "scale=2; $basics + $ta + $ten_percent" | bc)

echo "Gross Salary is: $gs"

```
making salary.sh executable
```
chmod +x salary.sh
```
running salary.sh
```
./salary.sh
Enter Basics salary:
2000
Enter TA:
10
Gross Salary is: 2210.00
```

---
# Q5]
## Write a program to copy all the files (having file extension input by the user) in the current folder to the new folder input by the user [Ex: user enter .text TEXT then all files with .text should be moved to TEXT folder. This should be done only at single level. i.e if the current folder contains a folder name ABC which has .txt files then these files should not be copied to TEXT.]

## Command/Usage
create file 
```
nano copy.sh
```
content of copy.sh
```
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

```
making copy.sh executable
```
chmod +x copy.sh
```
running copy.sh
```
/copy.sh
Enter the file extension (with dot), e.g., .text:
.text
Enter the destination folder name:
files_text
Copied alpha.text to files_text/
Copied beta.text to files_text/

```

---
# Q6]
## Write a shell script to modify all occurrences of “ex:” with “Example:” in all the files present in current folder only if “ex:” occurs at the start of the line or after a period (.). Example: if a file contains a line: “ex: this is first occurrence so should be replaced” and “second ex: should not be replaced as it occurs in the middle of the sentence.” 

## Command/Usage
create file 
```
nano replace_ex.sh
```
content of replace_ex.sh
```
#!/bin/sh
# Replace 'ex:' with 'Example:' at start of line or after a period in all>

for file in *; do
  # Check if it is a regular file (ignore directories)
  if [ -f "$file" ]; then
    # Use sed to replace:
    # ^ex:  --> ex: at start of line
    # \.Example: --> ex: after a period
    sed -i.bak -e 's/^ex:/Example:/g' -e 's/\.Example:/\.Example:/g' "$fi>
    echo "Modified $file"
  fi
done
```
making replace_ex.sh executable
```
chmod +x replace_ex.sh
```
running replace_ex.sh
```
./replace_ex.sh
Modified LAB03.txt
Modified alpha.text
Modified beta.text
Modified copy.sh
Modified demo.sh
Modified extension.sh
Modified find.sh
Modified pattern.sh
Modified replace_ex.sh
Modified salary.sh
Modified yo2
Modified you1.txt
Modified you2.txt
```

# Q7]
## Write a shell script which deletes all the even numbered lines in a text file. 

## Command/Usage
create file 
```
nano even.sh
```
content of even.sh
```
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

```
making even.sh executable
```
chmod +x even.sh
```

even_demo.txt contains:  
```
1. line 1
2. line 2 
3. line 3 
4. line 4
5. line 5
```
running even.sh (executing):
```
./even.sh
Enter the filename:
even_demo.txt
1. line 1
3. line 3 
5. line 5

```
