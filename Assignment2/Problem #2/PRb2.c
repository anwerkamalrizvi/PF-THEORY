/*
* Name: Syed Anwer
* Section: BAI-1A
* Roll #:24K-0033
* Subject: Programming Fundamentals Assignment #2
* A popular beverage company is looking to optimize their marketing campaigns by understanding the
. . . . . . . . . . .. . . . . . . . . . . . . . . . . . . . . . . . . .. . . . . . . . . . . . . . . 
● For "limited offer": {'l': 1, 'i': 1, 'm': 1, 't': 1, 'e': 2, 'd': 1, ' ': 1, 'o': 1, 'f': 1, 'r': 1}*/
#include <stdio.h>

#define MAX_CHARS 128
#define MAX_LENGTH 100

void AnalyzeFrequency(const char* slogan) { // Start AnalyzeFrequency
    int frequency[MAX_CHARS] = {0}; // Frequency array for characters
    int printed[MAX_CHARS] = {0}; // Array to track which characters have been printed

    int index = 0;
    // Count the frequency of each character in the slogan
    while (slogan[index] != '\0') {
        frequency[(unsigned char)slogan[index]]++;
        index++;
    }

    // Print the results in the desired format
    printf("For \"%s\": {", slogan);
    int isFirst = 1; // Flag to manage comma placement

    // Loop through the frequency array to print character counts
    for (index = 0; slogan[index] != '\0'; index++) {
        if (frequency[(unsigned char)slogan[index]] > 0 && printed[(unsigned char)slogan[index]] == 0) {
            if (!isFirst) {
                printf(", "); // Add a comma before subsequent items
            }
            printf("'%c': %d", slogan[index], frequency[(unsigned char)slogan[index]]);
            printed[(unsigned char)slogan[index]] = 1; // Mark this character as printed
            isFirst = 0; // Set flag to false after the first character
        }
    }
    printf("}\n"); // Close the output for the current slogan
} // End AnalyzeFrequency

int main() { // Start main
    int totalSlogans;

    printf("Enter the number of slogans: ");
    scanf("%d", &totalSlogans);
    getchar(); // Clear the newline character from input buffer

    char slogans[totalSlogans][MAX_LENGTH]; // Array to hold slogans

    // Input loop for slogans
    for (int i = 0; i < totalSlogans; i++) {
        printf("Enter slogan %d: ", i + 1);
        fgets(slogans[i], MAX_LENGTH, stdin);

        // Remove the newline character if it exists
        int length = 0;
        while (slogans[i][length] != '\0') {
            length++;
        }
        if (length > 0 && slogans[i][length - 1] == '\n') {
            slogans[i][length - 1] = '\0'; // Replace newline with null terminator
        }
    }

    // Analyze each slogan
    for (int i = 0; i < totalSlogans; i++) {
        AnalyzeFrequency(slogans[i]);
    }

    return 0; // End of main
} // End main
