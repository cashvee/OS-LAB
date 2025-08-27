
## Q1] Write a shell script to make a duplicate copy of a specified file through command line.

### Command/Usage

```bash 
#!/bin/bash
# Script to make a duplicate copy of a specified file through command line

if [ $# -ne 2 ]; then
    echo "Usage: $0 <source_file> <duplicate_file>"
    exit 1
fi

src=$1
dest=$2

if [ ! -f "$src" ]; then
    echo "Error: Source file '$src' does not exist."
    exit 2
fi

cp "$src" "$dest"

if [ $? -eq 0 ]; then
    echo "File '$src' successfully copied to '$dest'."
else
    echo "Error: Failed to copy file."
fi
# fi ends the if block
```

### To make it executable – on the terminal run:

```bash
chmod +x duplicate.sh
```

Run the script with:

```bash
./duplicate.sh test.txt copy.txt
```

### Example Output

```
File 'test.txt' successfully copied to 'copy.txt'.
```

 

## Q2] Write a shell script to remove all files that are passed as command line arguments interactively. 

### Command/Usage - in remove_files.sh

```bash 
#!/bin/bash
# Script to remove all files passed as command line arguments interactively

if [ $# -eq 0 ]; then
    echo "Usage: $0 <file1> <file2> ... <fileN>"
    exit 1
fi

for file in "$@"
do
    if [ -f "$file" ]; then
        echo "Do you want to delete '$file'? (y/n): "
        read choice
        if [ "$choice" = "y" ] || [ "$choice" = "Y" ]; then
            rm "$file"
            echo "'$file' deleted."
        else
            echo "'$file' not deleted."
        fi
    else
        echo "'$file' does not exist or is not a regular file."
    fi
done
# for loop ends here

```

### To make it executable – on the terminal run:

```bash
chmod +x remove_files.sh
```

### Run the script with:

```bash
./remove_files.sh file1.txt file2.txt
```

### Example Output

```
Do you want to delete 'file1.txt'? (y/n): y
'file1.txt' deleted.
Do you want to delete 'file2.txt'? (y/n): n
'file2.txt' not deleted.

```

## Q3] Write a program to sort the strings that are passed as a command line arguments 
 [ex: Jscript.sh “OS Lab” “Quoted strings™” “Command Line” “Sort It”. The output should be “Command Line” “OS Lab” “Quoted strings” “Sort It”. ( make use of usrdefined sort function)]

### Command/Usage - in sort_strings.sh

```bash 
#!/bin/bash
# Script to sort strings passed as command line arguments using user-defined function

# Function to sort an array of strings
sort_strings() {
    arr=("$@")
    n=${#arr[@]}

    for ((i=0; i<n; i++))
    do
        for ((j=i+1; j<n; j++))
        do
            if [[ "${arr[i]}" > "${arr[j]}" ]]; then
                temp="${arr[i]}"
                arr[i]="${arr[j]}"
                arr[j]="$temp"
            fi
        done
    done

    echo "Sorted Strings:"
    for str in "${arr[@]}"
    do
        echo "\"$str\""
    done
}

# Main program starts here
if [ $# -eq 0 ]; then
    echo "Usage: $0 <string1> <string2> ... <stringN>"
    exit 1
fi

sort_strings "$@"


```

### To make it executable – on the terminal run:

```bash
chmod +x sort_strings.sh
```

### Run the script with:

```bash
./sort_strings.sh "OS Lab" "Quoted strings" "Command Line" "Sort It"
```

### Example Output

```
Sorted Strings:
"Command Line"  
"OS Lab"  
"Quoted strings"
"Sort It"

```

 ## Q4] Implement wordcount script that takes -linecount, -wordcount, -charcount options and performs accordingly, on the input file that is passed as command line argument (use case statement) 

### Command/Usage

```bash 
#!/bin/bash
# Script to perform line, word, or character count on a file using options

if [ $# -ne 2 ]; then
    echo "Usage: $0 {-linecount|-wordcount|-charcount} <filename>"
    exit 1
fi

option=$1
file=$2

if [ ! -f "$file" ]; then
    echo "Error: File '$file' not found."
    exit 2
fi

case $option in
    -linecount)
        count=$(wc -l < "$file")
        echo "Line Count: $count"
        ;;
    -wordcount)
        count=$(wc -w < "$file")
        echo "Word Count: $count"
        ;;
    -charcount)
        count=$(wc -m < "$file")
        echo "Character Count: $count"
        ;;
    *)
        echo "Invalid option. Use -linecount, -wordcount, or -charcount."
        exit 3
        ;;
esac
# case ends here

```

### To make it executable – on the terminal run:

```bash
chmod +x wordcount.sh
```

Run the script with:

```bash
./wordcount.sh -linecount sample.txt
./wordcount.sh -wordcount sample.txt
./wordcount.sh -charcount sample.txt

```

### Example Output

```
$ ./wordcount.sh -linecount sample.txt
Line Count: 5

$ ./wordcount.sh -wordcount sample.txt
Word Count: 20

$ ./wordcount.sh -charcount sample.txt
Character Count: 112
```
## Q5] Write a menu driven shell script to read list of patterns as command line arguments and perform following operations: 
## a. Search the patterns in the given input file. Display all lines containing the patten in the given input file.  
## b. Delete all occurances of the pattern in the given input file.  
## c. Exit from the shell script.

### Command/Usage

```bash 
#!/bin/bash
# Menu driven script to search or delete patterns in a given file

if [ $# -lt 2 ]; then
    echo "Usage: $0 <input_file> <pattern1> <pattern2> ... <patternN>"
    exit 1
fi

file=$1
shift   # Shift arguments so that only patterns remain in $@

if [ ! -f "$file" ]; then
    echo "Error: File '$file' not found."
    exit 2
fi

while true
do
    echo "==============================="
    echo " MENU "
    echo "1. Search patterns in file"
    echo "2. Delete patterns from file"
    echo "3. Exit"
    echo "==============================="
    echo -n "Enter your choice: "
    read choice

    case $choice in
        1)
            echo "Searching for patterns..."
            for pat in "$@"
            do
                echo "---- Pattern: $pat ----"
                grep --color=always "$pat" "$file" || echo "No match found for '$pat'"
            done
            ;;
        2)
            echo "Deleting patterns..."
            for pat in "$@"
            do
                sed -i "s/$pat//g" "$file"
                echo "Deleted all occurrences of '$pat'."
            done
            ;;
        3)
            echo "Exiting script."
            exit 0
            ;;
        *)
            echo "Invalid choice. Please select 1, 2, or 3."
            ;;
    esac
done
# while loop ends here

```

### To make it executable – on the terminal run:

```bash
chmod +x pattern_menu.sh
```

Run the script with:

```bash
./pattern_menu.sh input.txt "OS" "Lab"
```

### Example Output

```
===============================
 MENU 
1. Search patterns in file
2. Delete patterns from file
3. Exit
===============================
Enter your choice: 1
Searching for patterns...
---- Pattern: OS ----
OS Lab is interesting
---- Pattern: Lab ----
OS Lab is interesting
This Lab is important

===============================
 MENU 
1. Search patterns in file
2. Delete patterns from file
3. Exit
===============================
Enter your choice: 2
Deleting patterns...
Deleted all occurrences of 'OS'.
Deleted all occurrences of 'Lab'.

===============================
 MENU 
1. Search patterns in file
2. Delete patterns from file
3. Exit
===============================
Enter your choice: 3
Exiting script.

```

 
 
