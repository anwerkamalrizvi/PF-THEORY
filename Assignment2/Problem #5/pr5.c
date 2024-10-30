/*
* Name: Syed Anwer
* Section: BAI-1A
* Roll #:24K-0033
* Subject: Programming Fundamentals Assignment #2
You are tasked with creating a program that generates a histogram based on user input. The user will
....................................................................................................
3 5 1 4*/
#include <stdio.h>
#include <string.h>

void storageOfStr(char str[20], int store[20], int *k);
void horizontalDisplay(int store[20], int k);
void verticalDisplay(int store[20], int k, int count);

int main() {
    char str[20];
    printf("Enter in format # # # #: ");
    fgets(str, sizeof(str), stdin);
    
    int store[20] = {0}; // Increase size for safety
    int k = 0; // Counter for valid digits
    int count = 9;
    storageOfStr(str, store, &k);
    horizontalDisplay(store, k);
    verticalDisplay(store ,k ,count);
    return 0;
}

void storageOfStr(char str[20], int store[20], int *k) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            store[*k] = str[i] - '0'; // Convert char to int
            printf("%d ", store[*k]);   // Checking if stored
            (*k)++;
        }
    }
}//end storageOfStr

void horizontalDisplay(int store[20], int k) {
    printf("\n\tHorizontal Display:\n");        //Nothing just a print
    for (int j = 0; j < k; j++) {               //k = length hence less than length
        printf("\nValue %d: ", j + 1);          //value 0, j+1= value 1
        for (int temp = 0; temp < store[j]; temp++) {
            printf("*");
        }
    }
}//end horizontalDisplay


void verticalDisplay(int store[20], int k, int count)
{
    printf("\n\tVertical Display:\n");  //nothing just a print
    for(int n=0;n<k;n++){           //where k = length  
        if(store[n]>=count){        //count = 9
            printf("*\t");
        }//end if
        else{
            printf("\t");
        }//end else
        if(n==k-1){
            n=-1;       //here n = -1 otherwise loop will increment 0 to 1 and store[0] will be skipped
            count--;    //compare for 9 then 8.... then to 0
            printf("\n");   //when all comparison is done, move to next line to display in a vertical format
        }//end if
        if(count==0){
            break;      //to prevent being infinite loop
        }//end if
        
    }//end for loop
    for(int print=0;print<k;print++){
        printf("%d\t",store[print]);
    }//end for
}//end verticalDisplay



