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

| No. | Command / Tool | Short Definition                 | Command Example                     | Output                                  |
| --- | -------------- | -------------------------------- | ----------------------------------- | --------------------------------------- |
| 1   | `grep`         | Lines containing `"a"`           | `grep "a" students.txt`             | Alice<br>Charlie<br>David               |
| 2   | `grep`         | Lines **NOT** containing `"cat"` | `grep -v cat random.txt`            | dog<br>bat<br>rat<br>ok<br>hi           |
| 3   | `grep`         | Match whole line exactly         | `grep -x Alice students.txt`        | Alice                                   |
| 4   | `grep`         | Lines containing `"o"`           | `grep "o" students.txt`             | Bob                                     |
| 5   | `sort`         | Sort lines alphabetically        | `sort students.txt`                 | Alice<br>Bob<br>Charlie<br>David<br>Eve |
| 6   | `sort`         | Sort lines reverse order         | `sort -r students.txt`              | Eve<br>David<br>Charlie<br>Bob<br>Alice |
| 7   | `wc`           | Count lines, words, chars        | `wc students.txt`                   | 5 5 32 students.txt                     |
| 8   | `cut`          | Extract first 3 chars            | `cut -c 1-3 students.txt`           | Ali<br>Bob<br>Cha<br>Dav<br>Eve         |
| 9   | `sed`          | Search & replace                 | `sed 's/cat/dog/g' random.txt`      | *(cat → dog replaced)*                  |
| 10  | `sed`          | Delete lines starting with `"c"` | `sed '/^c/d' random.txt`            | dog<br>bat<br>rat<br>ok<br>hi           |
| 11  | `tr`           | Lowercase → Uppercase            | `tr '[a-z]' '[A-Z]' < students.txt` | ALICE<br>BOB<br>CHARLIE<br>DAVID<br>EVE |
| 12  | `ps`           | List running processes           | `ps`                                | *(lists processes)*                     |
| 13  | `kill`         | Terminate process by PID         | `kill 1234`                         | *(no output if success)*                |
| 14  | `chmod`        | Change file permissions          | `chmod 664 file.txt`                | *(no output)*                           |
| 15  | `echo`         | Print text                       | `echo "Hello World"`                | Hello World                             |
| 16  | `bc`           | Calculator                       | Run `bc`, then `5+2`                | 7                                       |

---  
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












