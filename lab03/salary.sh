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
