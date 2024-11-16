#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define n 5
int run2=1;
// Function to generate and display the grid
int strGridGame(char arr[6][n], char seed, char str[20]) {
    int counter = 0, random, count = 0;
    printf("Recommended: Last digit should not be zero\nWrite any seed in number digits:(0 to exit) ");
    scanf("%d", &random);
    
    if(random ==0 ){
        run2=0;    
    }
    srand(random);

    // Generate random characters for the 6x5 grid
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = 'A' + (rand() % 26); // Random uppercase letters
        }
    }

    // Populate the last row with the student ID's last four digits
    int studentID[] = {0, 0, 3, 3}; // Replace this with the actual digits of your ID
    for (int i = 0; i < 4; i++) {
        arr[4][i] = '0' + studentID[i];
    }
    //arr[4][4]= 'A' + (rand() % 26);    

    // Print the generated grid
    printf("Generated Grid:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
    return 2;
}

// Function to search for the string in the grid
int searchFor(char arr[6][n], char seed, char str[20]) {
    int score = 0;
    int run = 1;
    while (run == run2) {
        printf("\nSearch (provide at least 2 letters, enter END to quit): ");
        scanf(" %s", str);
        if (strcmp(str, "END") == 0 || strcmp(str, "end") == 0) {
            run = 0;
            break;
        }

        int len = strlen(str);
        int found = 0;

        // Search the string horizontally (left to right) and vertically (top to bottom)
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < n; j++) {
                // Check horizontal match
                if (j + len <= n) {
                    int match = 1;
                    for (int k = 0; k < len; k++) {
                        if (arr[i][j + k] != str[k]) {
                            match = 0;
                            break;
                        }
                    }
                    if (match) {
                        found = 1;
                    }
                }

                // Check vertical match
                if (i + len <= 6) {
                    int match = 1;
                    for (int k = 0; k < len; k++) {
                        if (arr[i + k][j] != str[k]) {
                            match = 0;
                            break;
                        }
                    }
                    if (match) {
                        found = 1;
                    }
                }
            }
        }

        // Update the score based on the result
        if (found) {
            score++;
            printf("%s is present. Score: %d\n", str, score);
        } else {
            score--;
            printf("%s is not present. Score: %d\n", str, score);
        }
    }
    return 1;
}

// Main function
int main() {
    char str[20];
    char arr[6][n];
    char seed = 'a';

    while (run2==1) {
        strGridGame(arr, seed, str);
        searchFor(arr, seed, str);
    }
    if(run2!=1){
        printf("\nThanks for playing our Grid Game!!\nBy: Syed Anwer\nRoll no: 24k-0033");
    }
    return 0;
}
