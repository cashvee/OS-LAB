# RANDOM  

### command  
./demo.sh hello world   

### code in demo.sh  
#!/bin/sh  
# to check shell family being used : echo $SHELL   

echo "Script Name: $0"  
echo "First Argument: $1"  
echo "Shell family: $SHELL"  
echo "Second argument: $2"  
echo "Total Arguments: $#"  
echo "All arguments: $*"  

### output  
Script Name: ./demo.sh   
First Argument: hello  
Shell family: /bin/bash  
Second argument: world  
Total Arguments: 2  
All arguments: hello world  

