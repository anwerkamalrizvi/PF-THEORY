/*
Question 03
Create a program to validate an email address based on a few basic criteria. The program will
prompt the user to enter an email address and will dynamically allocate memory to store and
process the input.
Define the following function:
1. int validateEmail(char* email): This function validates the email based on the following
criteria:
○ Contains exactly one @ symbol.
○ Contains at least one dot (.) after the @ symbol.
○ Is non-empty.
○ Returns 1 if the email is valid, and 0 if invalid.

Steps:
1. User Input: Prompt the user to enter an email address. Allocate memory dynamically for the
email, ensuring the memory size is based on the input length.
2. Validation Process:
○ Call the validateEmail function to check if the email meets the criteria.
3. Display Results:
○ Print "Valid Email" if the email meets the criteria.
○ Print "Invalid Email" if the email does not meet the criteria.
4. Memory Cleanup:
○ Free the dynamically allocated memory after validation to prevent memory leaks.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validateEmail(char* email){
    int tmp =0, tmp2=0,tmp3=0;
    for (int i = 0; i < strlen(email); i++)
    {
        if(email[i] == '@'){
            tmp++;
        }
        if(tmp==1){
            if(email[i] == '.'){
            tmp2++;
            }
        }
    }
    if(tmp==1&&tmp2==1&&email[0]!='\0'){
        return 1;
    }else{
        return 0;
    }
    
}
int main() {
    
    int n;
    printf("\nEnter length: ");
    scanf("%d",&n);
    char* ptr = (char*)malloc(sizeof(char)*(n+1));  //+1 for null 
    if(ptr==NULL){
        printf("DMA failed");
        return 1;
    }
    printf("\nEnter email: ");
    scanf("%s",ptr);
    validateEmail(ptr);
    if(validateEmail(ptr)== 1){
        printf("Email is valid");
    }else{
        printf("Email not valid");
    }
    free(ptr);
    return 0;
}