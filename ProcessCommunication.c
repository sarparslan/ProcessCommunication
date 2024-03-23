//
//  main.c
//  hw1
//
//  Created by Sarp Arslan on 23.03.2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdbool.h>
bool isPrime(int number);
int nrDigits(int number);
int getDigitCount(int number);

int main(int argc, char *argv[]) {

    int p1_to_p2[2];
    int p2_to_p1[2];
    int p1_to_p3[2];
    int p3_to_p1[2];
    
    pipe(p1_to_p2);
    pipe(p2_to_p1);
    pipe(p1_to_p3);
    pipe(p3_to_p1);
    
    pid_t pid1;
    pid_t pid2;
    
    pid1 = fork();
    
    if(pid1 == -1){
        printf("Error occurs while creating the fork for pid1");
    }
    else if(pid1 == 0){//Child Process P2
        close(p1_to_p2[1]); //Closing 'write end' since we will use 'read end' for that Pipe
        close(p2_to_p1[0]); //Closing 'read end' since we will use 'write end' for that Pipe
        close(p1_to_p3[0]); close(p1_to_p3[1]); //We do not need that pipe
        close(p3_to_p1[0]); close(p3_to_p1[1]); //We do not need that pipe as well
        
        int num;
        int counts[5] = {0}; //Starting all array elements from 0, Make room for 5 elements since the range is between 0-99999
        while(read(p1_to_p2[0], &num, sizeof(int)) > 0) {
            int digits = nrDigits(num);
            counts[digits - 1]++;
        }
        
        //Sending counts array to P1 parent process
        write(p2_to_p1[1], counts, sizeof(counts));
        
        //We are done with 2 pipes, closing the corresponding parts.
        close(p1_to_p2[0]);
        close(p2_to_p1[1]);
        
        exit(0);
    }
    
    pid2 = fork();
    if(pid2 == -1){
        printf("Error occurs while creating the fork for pid2");
    }
    else if(pid2 == 0){//Child Process P3
        close(p1_to_p3[1]); //Closing 'write end' since we will use 'read end' for that Pipe
        close(p3_to_p1[0]); //Closing 'read end' since we will use 'write end' for that Pipe
        close(p1_to_p2[0]); close(p1_to_p2[1]);  //We do not need that pipe
        close(p2_to_p1[0]); close(p2_to_p1[1]);  //We do not need that pipe as well
        
        int num2;
        int primes = 0;
        int totalNumbers = 0;
        while (read(p1_to_p3[0], &num2, sizeof(int)) > 0) {
            totalNumbers++;
            if (isPrime(num2)){
                primes++;
            }
         }
        int nonPrimes = totalNumbers - primes;
        int results[2] = {primes, nonPrimes};
        
        //Sending results to P1 parent process
        write(p3_to_p1[1], &results, sizeof(results));
        
        //We are done with 2 pipes, closing the corresponding parts.
        close(p1_to_p3[0]);
        close(p3_to_p1[1]);
        exit(0);
    }
    
    //Parent Process
    
    close(p1_to_p2[0]); close(p2_to_p1[1]);
    close(p1_to_p3[0]); close(p3_to_p1[1]);
    
    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Failed to open file");
        exit(1);
    }
    
    int num;
    while (fscanf(file, "%d", &num) == 1) {
        write(p1_to_p2[1], &num, sizeof(num));
        write(p1_to_p3[1], &num, sizeof(num));
    }
    

    close(p1_to_p2[1]);
    close(p1_to_p3[1]);

    int counts[5] = {0}, primes = 0;
    
    // Wait for P2 to finish and read the data
    waitpid(pid1, NULL, 0);
    
    read(p2_to_p1[0], counts, sizeof(counts));

    int results[2]; // To receive primes and non-primes
    
    // Wait for P3 to finish and read the data
    waitpid(pid2, NULL, 0);
    
    read(p3_to_p1[0], &results, sizeof(results));
    primes = results[0];
    int nonPrimes = results[1];

    close(p2_to_p1[0]);
    close(p3_to_p1[0]);
    
    printf("Input file: %s\n", argv[1]);
    for (int i = 0; i < 5; i++) {
        printf("%d digits - %d\n", i + 1, counts[i]);
    }
    printf("Primes - %d\n", primes);
    printf("Nonprimes - %d\n", nonPrimes);
    fclose(file);
    
    return 0;
}

bool isPrime(int number){
    if(number <= 1){
        return false;
    }
    for(int i = 2;i*i<=number;i++){
        if(number % i == 0){
            return false;
        }
    }
    return true;
}

int nrDigits(int n) {
    int count = 0;
    do {
        n /= 10;
        count++;
    } while(n != 0);
    return count;
}


int getDigitCount(int number){
    int result = 0;
    while(number > 10){
        number /= 10;
        result++;
    }
    return result+1;
}


