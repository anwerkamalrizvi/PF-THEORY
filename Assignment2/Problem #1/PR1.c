/*
* Name: Syed Anwer
* Section: BAI-1A
* Roll #:24K-0033
* Subject: Programming Fundamentals Assignment #2
* Write a c program to find the second smallest element in an array.
Input 5 elements in the array (value must be <9999):
element - 0: 0
element - 1: 9
element - 2: 4
element - 3: 6
element - 4: 5
Expected Output:
The Second smallest element in the array is: 4
*/
#include <stdio.h>
int main() {
    int n;
    printf("Enter the length of the array: ");
    scanf("%d",&n);
    
    int arr[n];
    int i;
    for(i=0;i<n;i++){
        printf("Enter Element[%d]: ",i+1);
        scanf("%d",&arr[i]);
        
        while (arr[i]>=9999){
            printf("\nOut of Range. Enter again.\n");
            printf("Enter Element[%d]: ",i+1);
            scanf("%d",&arr[i]);
        }
    }
    
    int target=9999;
    int catch = 9999;

    for(i=0;i<n;i++){
        if(arr[i]<target){
            catch = target;
            target = arr[i]; //target = arr[i];
        }
        else if(arr[i]<catch && arr[i]!=target){
                catch=arr[i];
            }
    }
    if(catch==9999){
        printf("No value is found to be smallest. ");
    }
    else{
        printf("The second smallest element is: %d",catch);
    }
        
    
    return 0;
}