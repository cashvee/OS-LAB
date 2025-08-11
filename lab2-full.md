# RANDOM
grep ^..$ random.txt --> exactly 2 characters   
grep ^.. random.txt --> minimum 2 characters

uppercase/lowercase
starting with uppercase: grep ^[A-Z] random.txt
ending with uppercase: grep [A-Z]$ random.txt

ending with '.' (period) : grep [.]$ random.txt

to select lines in a file that has one or more blank spaces: grep " " random.txt

START & END BOTH UPPER CASE: 
grep '^[A-Z].*[A-Z]$' filename
Explanation:
^ — start of line
[A-Z] — first character is uppercase letter
.* — zero or more characters in the middle
[A-Z] — last character is uppercase letter
$ — end of line
*/ RANDOM

# Q1] Execute all the commands explained in this section and write the output.

# Quick Reference: Commands to Extract, Sort, Filter, and Process Data

This table lists common Unix/Linux commands for searching, filtering, sorting, and processing data, along with example commands and sample outputs.

| No. | Command / Tool | Short Definition | Command Example | Output |
|-----|----------------|------------------|-----------------|--------|
| 1   | grep | Search lines matching pattern (exactly 2 characters) | ```grep ^..$ random.txt``` | `an`<br>`is` |
| 2   | grep | Lines starting with uppercase | ```grep ^[A-Z] random.txt``` | `Apple`<br>`Banana` |
| 3   | grep | Lines ending with period | ```grep '[.]$' random.txt``` | `This is a sentence.` |
| 4   | grep | Lines containing blank spaces | ```grep " " random.txt``` | `apple pie`<br>`banana split` |
| 5   | grep | Lines containing digits, output to file | ```grep '[0-9]' random.txt > output.txt``` | *(No terminal output — matches written to `output.txt`)* |
| 6   | grep | Search for a word in a file | ```grep apple fruitlist.txt``` | `apple`<br>`pineapple` |
| 7   | grep | Match whole line exactly | ```grep -x apple fruitlist.txt``` | `apple` |
| 8   | grep | Lines containing "p" | ```grep "p" fruitlist.txt``` | `apple`<br>`grape`<br>`pineapple` |
| 9   | grep | Lines NOT containing "apple" | ```grep -v apple fruitlist.txt``` | `banana`<br>`orange` |
| 10  | sort | Sort lines alphabetically | ```sort filename``` | `apple`<br>`banana`<br>`grape`<br>`orange` |
| 11  | sort | Sort lines reverse order | ```sort -r filename``` | `orange`<br>`grape`<br>`banana`<br>`apple` |
| 12  | sort | Sort numbers numerically | ```sort -n filename``` | `1`<br>`5`<br>`12`<br>`25` |
| 13  | wc | Word count of a file | ```wc filename``` | `12  15  85 filename` *(lines, words, bytes)* |
| 14  | cut | Extract specific characters | ```cut -c 1-3 filename``` | `app`<br>`ban`<br>`gra` |
| 15  | cut | Extract tab-separated fields | ```cut -f 1,4,7 filename``` | `field1	field4	field7` |
| 16  | sed | Search & replace in file | ```sed -e 's/input/output/g' my_file``` | *(Replaces “input” with “output” in printed text)* |
| 17  | sed | Delete lines starting with '#' | ```sed -e '/^#/d' my_file``` | *(Same file contents without lines starting with `#`)* |
| 18  | tr | Translate lowercase to uppercase | ```tr '[a-z]' '[A-Z]' < filename``` | `APPLE`<br>`BANANA` |
| 19  | ps | List running processes | ```ps``` | `PID   TTY   TIME  CMD`<br>`1234 pts/0 00:00 bash`<br>`1250 pts/0 00:02 vim` |
| 20  | kill | Terminate process by PID | ```kill 1234``` | *(No output if successful)* |
| 21  | chmod | Change file permissions | ```chmod 664 filename``` | *(No output if successful)* |
| 22  | echo | Print text to stdout | ```echo "Hello World"``` | `Hello World` |
| 23  | bc | Basic calculator | Run `bc` then enter `5+2` | `7` |

---





*Note: Replace "add" in the Output column with actual output after running the commands.*


# Q2] Write grep commands to do the following activities:

## CONTENT IN random.txt file:
Hi, My name is cat 
im small12.
Not a doG
I am a cat.
Meow yes
OK
yaY

### 1] To select the lines from a file that have exactly two characters:
#### COMMAND: `grep ^..$ random.txt`  
#### OUTPUT: 
OK

### 2] To select the lines from a file that start with the upper case letter.
#### COMMAND: `grep ^[A-Z] random.txt`  
#### OUTPUT:   
Hi, My name is cat   
Not a doG  
I am a cat.  
Meow yes  
OK

### 3] To select the lines from a file that end with a period.
#### COMMAND: `grep [.]$ random.txt`
#### OUTPUT: 
im small12.  
I am a cat.


### 4] To select the lines in a file that has one or more blank spaces.
#### COMMAND: `grep " " random.txt`
#### OUTPUT:  
Hi, My name is cat  
im small12.  
Not a doG  
I am a cat.  
Meow yes

### 5] To select the lines in a file and direct them to another file which has digits as one of the characters in that line. 
#### COMMAND: `grep '[0-9]' random.txt > output.txt`
#### OUTPUT: 
CREATED FILE output.txt which has content: 
im small12.


# Q3] 
`cat > studentInformation.txt`  
1234:XYZ:ICT:CCE:A:80:60:70  
2345:ABC:IT:CCE:B:75:65:55  
3456:PQR:ICT:IT:A:90:85:80  
4567:LMN:ECE:IT:C:70:75:80  
5678:DEF:ICT:CCE:A:60:65:70  
6789:GHI:IT:CCE:B:85:80:75  
7890:JKL:ICT:IT:A:90:95:85  
8901:MNO:ECE:CCE:C:70:65:60  
9012:PST:ICT:IT:B:88:92:78  
0123:QWE:IT:CCE:A:80:85:88


### 1) Count students in ICT department:

`grep ':ICT:' studentInformation.txt | wc -l ` 

#### `grep ':ICT:' studentInformation.txt ` : This finds all lines in studentInformation.txt that contain the text :ICT:.

#### `| (pipe) ` : Takes the output of the command on the left (grep in this case) and sends it as input to the command on the right.

#### `wc -l  `: wc stands for word count, but with -l it counts lines only.

 
#### output: 5


### 2) Replace all occurrences of IT branch with "Information Technology" and save:
#### `sed 's/:IT:/:Information Technology:/g' studentInformation.txt > ITStudents.txt`

#### New file created called ITStudents.txt with content:   
1234:XYZ:ICT:CCE:A:80:60:70  
2345:ABC:Information Technology:CCE:B:75:65:55    
3456:PQR:ICT:Information Technology:A:90:85:80   
4567:LMN:ECE:Information Technology:C:70:75:80    
5678:DEF:ICT:CCE:A:60:65:70    
6789:GHI:Information Technology:CCE:B:85:80:75    
7890:JKL:ICT:Information Technology:A:90:95:85  
8901:MNO:ECE:CCE:C:70:65:60  
9012:PST:ICT:Information Technology:B:88:92:78  
0123:QWE:Information Technology:CCE:A:80:85:88  

### 3) Calculate average marks of student with RegistrationNo "1234":
#### Command: `grep '^1234:' studentInformation.txt | awk -F: '{ avg = ($6 + $7 + $8) / 3; print "Average marks of student 1234: " avg }'`
#### output
Average marks of student 1234: 70

### 4) Display the title row in uppercase, remaining lines unchanged.

#### ~to add a header line in uppercase followed by unchanged lines, use:
 `(echo "REGISTRATIONNO:NAME:DEPARTMENT:BRANCH:SECTION:MARK1:MARK2:MARK3" | tr '[:lower:]' '[:upper:]'; cat studentInformation.txt)`

#### ⭐️output: 
REGISTRATIONNO:NAME:DEPARTMENT:BRANCH:SECTION:MARK1:MARK2:MARK3  
1234:XYZ:ICT:CCE:A:80:60:70  
2345:ABC:IT:CCE:B:75:65:55  
3456:PQR:ICT:IT:A:90:85:80  
4567:LMN:ECE:IT:C:70:75:80  
5678:DEF:ICT:CCE:A:60:65:70  
6789:GHI:IT:CCE:B:85:80:75  
7890:JKL:ICT:IT:A:90:95:85  
8901:MNO:ECE:CCE:C:70:65:60  
9012:PST:ICT:IT:B:88:92:78  
0123:QWE:IT:CCE:A:80:85:88  

#### ⭐️BEFORE: 
1234:xyz:ict:cce:a:80:60:70  
2345:ABC:IT:CCE:B:75:65:55  
3456:PQR:ICT:IT:A:90:85:80  
4567:LMN:ECE:IT:C:70:75:80  
5678:DEF:ICT:CCE:A:60:65:70  
6789:GHI:IT:CCE:B:85:80:75  
7890:JKL:ICT:IT:A:90:95:85  
8901:MNO:ECE:CCE:C:70:65:60  
9012:PST:ICT:IT:B:88:92:78  
0123:QWE:IT:CCE:A:80:85:88  

#### ⭐️AFTER:
#### COMMAND: `(head -n 1 studentInformation.txt | tr '[:lower:]' '[:upper:]'; tail -n +2 studentInformation.txt) ` 

1234:XYZ:ICT:CCE:A:80:60:70  
2345:ABC:IT:CCE:B:75:65:55  
3456:PQR:ICT:IT:A:90:85:80  
4567:LMN:ECE:IT:C:70:75:80  
5678:DEF:ICT:CCE:A:60:65:70  
6789:GHI:IT:CCE:B:85:80:75  
7890:JKL:ICT:IT:A:90:95:85  
8901:MNO:ECE:CCE:C:70:65:60  
9012:PST:ICT:IT:B:88:92:78  
0123:QWE:IT:CCE:A:80:85:88  

# Q4] List all the files containing “MIT” in the current folder. Also display the lines containing MIT being replaced with Manipal Institute of Technology. (Hint: use grep, cut & sed) 

#### COMMAND: `grep -l 'MIT' * | while read file; do   echo "File: $file";   grep 'MIT' "$file" | sed 's/MIT/Manipal Institute of Technology/g'; done`
#### OUTPUT
File: mit_file.txt
this file has `Manipal Institute of Technology` in it.   
If it works, the 3rd word will be manipal institute of technology instead of "`Manipal Institute of Technology`"


# Q5] Shell command to display number of lines, characters, words of files containing a digit in the name
#### COMMAND: `wc *[0-9]*`
#### OUTPUT
138  462 4373 lab2-comm.txt

# Q6] Run wc command in the background many times using wc &. Kill all the processes named wc. 

#### COMMAND: ` for i in {1..5}; do wc & done  `
[1] 11128  
[2] 11129  
[3] 11130  
[4] 11131  
[5] 11132  

#### COMMAND: ` pkill wc`

[1]   | Stopped |                wc

[2]   | Stopped |                wc

[3]   | Stopped |                wc

[4]-  | Stopped |            wc

[5]+  | Stopped |               wc


# ADDITIONAL: 
## 1) Write a sed command that deletes the character before the last character in each line in a file. 

### random.txt content: 
Hi, My name is cat  
im small  
Not a dog  
I am a cat  
Meow yes  
OK  
yaY

### command: 
`sed 's/^\(.\{0,\}\).\{1\}\(.\)$/\1\2/' random.txt`

### output: 
Hi, My name is ca   
im smal  
Not a dg  
I am a ct  
Meow ys  
K  
yY  


## 2) Write a shell command to count the number lines containing digits present in a file. 

### command:
`grep -c '[0-9]' filename`

### use case:
#### command: ` grep -c '[0-9]' random.txt  `  
output: 0

#### command: ` grep -c '[0-9]' studentInformation.txt  `  
output: 10












