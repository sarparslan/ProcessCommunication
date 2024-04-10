# Process Communication


This C program demonstrates the use of Unix pipes for inter-process communication (IPC) and explores prime number identification and digit analysis of numbers read from a file. It features a parent process that reads numbers from a file and sends these numbers to two child processes via pipes. One child process determines the number of digits in each number, while the other identifies prime numbers. The results are then communicated back to the parent process, which displays the findings.

## Introduction

The program executes in a Unix environment, where it leverages forked processes and IPC through pipes to accomplish its tasks. Specifically, it reads numbers from a given file, categorizes them based on the number of digits, identifies prime numbers, and calculates the count of prime and non-prime numbers. This method of process communication and data analysis showcases the power and flexibility of Unix pipes and process management.

## Features

- Utilizes Unix pipes for inter-process communication between parent and child processes.
- Forks two child processes: one for digit analysis and another for prime number identification.
- Reads input numbers from a file specified as a command-line argument.
- Categorizes numbers based on their digit count.
- Identifies and counts prime and non-prime numbers.
- Demonstrates process synchronization and communication in a Unix environment.

## Getting Started

- Ensure you have a Unix-like environment to compile and run C programs.
- Save the provided C code to a file (e.g., main.c).
- Compile the program using a C compiler, such as gcc. Example command: gcc -o ipc_prime_finder main.c.
- Prepare an input file containing integers, one per line.

## Usage

To use this program, follow these steps:

1) Run the compiled program from the terminal, passing the path to the input file as an argument. Example: ./ipc_prime_finder input.txt.
The program reads the input file, processes the numbers, and then prints the results to the console.
2) It displays the count of numbers with 1 to 5 digits.
3) It reports the total count of prime and non-prime numbers found.

## Input Format

The input should be a text file with one integer per line. For example:

123
4567
89
1011
121314


## Output Format

The output is displayed on the console and includes:

The count of numbers categorized by the number of digits.
The count of prime numbers.
The count of non-prime numbers.
Example output for a given input file:

Input file: input.txt
1 digit - 0
2 digits - 1
3 digits - 1
4 digits - 1
5 digits - 2
Primes - X
Nonprimes - Y


