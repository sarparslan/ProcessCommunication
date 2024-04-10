# Process Communication


This C program demonstrates the use of Unix pipes for inter-process communication (IPC) and explores prime number identification and digit analysis of numbers read from a file. It features a parent process that reads numbers from a file and sends these numbers to two child processes via pipes. One child process determines the number of digits in each number, while the other identifies prime numbers. The results are then communicated back to the parent process, which displays the findings.

## Introduction

The program executes in a Unix environment, where it leverages forked processes and IPC through pipes to accomplish its tasks. Specifically, it reads numbers from a given file, categorizes them based on the number of digits, identifies prime numbers, and calculates the count of prime and non-prime numbers. This method of process communication and data analysis showcases the power and flexibility of Unix pipes and process management.

<img width="1154" alt="Screenshot 2024-04-10 at 12 43 14" src="https://github.com/sarparslan/ProcessCommunication/assets/96438389/44360e02-a0cf-47c4-aa4e-cb48cdc91c80">

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

<img width="476" alt="Screenshot 2024-04-10 at 12 47 02" src="https://github.com/sarparslan/ProcessCommunication/assets/96438389/8c2a79e7-19cb-4fec-8ce7-b2091a82d505">


## Output Format

The output is displayed on the console and includes:

The count of numbers categorized by the number of digits.
The count of prime numbers.
The count of non-prime numbers.
Example outputs :


<img width="1154" alt="Screenshot 2024-04-10 at 12 44 10" src="https://github.com/sarparslan/ProcessCommunication/assets/96438389/638920cc-1458-4a69-9f39-0f73a6b181b1">



