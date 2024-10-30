/*
* Name: Syed Anwer
* Section: BAI-1A
* Roll #:24K-0033
* Subject: Programming Fundamentals Assignment #2
You are working for a text-processing company that optimizes storage for large amounts of written
.................................................................................................
Input: words = [“booooook”, “coooool”, “heeeey”]
Output: [“bok”, “col”, “hey”]
*/
#include <stdio.h>
#include <string.h>
#define MAX_WORDS 20
#define MAX_LENGTH 100
// This nifty function squishes down a single word
void compressWord(const char *input, char *output, int *removedCount) {
    int length = strlen(input);
    *removedCount = 0; // Kickstart the count for missing letters

    if (length == 0) {
        output[0] = '\0'; // If nothing's there, just say so
        return;
    }

    // Grab the first character to start the party
    output[0] = input[0];
    int outputIndex = 1; // Pointer to where we put the next letter

    for (int i = 1; i < length; i++) {
        if (input[i] != input[i - 1]) {
            output[outputIndex++] = input[i]; // Add fresh character
        } else {
            (*removedCount)++; // Count the character that’s gone
        }
    }

    output[outputIndex] = '\0'; // Make sure to end the string properly
}
//This function handles the bunch of words, squeezing them all
void compressMultipleWords(char words[MAX_WORDS][MAX_LENGTH], int numWords, char output[MAX_WORDS][MAX_LENGTH], int removedCounts[MAX_WORDS]) {
    for (int i = 0; i < numWords; i++) {
        compressWord(words[i], output[i], &removedCounts[i]);
    }
}

int main() {
    char words[MAX_WORDS][MAX_LENGTH]; // Array for the incoming words
    char compressed[MAX_WORDS][MAX_LENGTH]; // Array for the squished words
    int removedCounts[MAX_WORDS]; // Array for counting how many got zapped
    int numWords;

    // Asking the user to enter words in a specific funky style
    printf("Enter words in the format [\"word1\", \"word2\", ...]: ");
    char input[MAX_WORDS * MAX_LENGTH]; // Buffer to hold the whole shebang
    fgets(input, sizeof(input), stdin);

    // Time to slice and dice the input
    char *token = strtok(input + 1, ","); // Skip the opening bracket
    numWords = 0;

    while (token != NULL && numWords < MAX_WORDS) {
        // Trim the flab around the words
        char *start = token;
        while (*start == ' ' || *start == '\"') start++;
        char *end = start + strlen(start) - 1;
        while (*end == ' ' || *end == '\"') end--;
        end[1] = '\0'; // End the string just right

        // Put the polished word into the words array
        strcpy(words[numWords], start);
        numWords++;
        
        // Move to the next piece
        token = strtok(NULL, ",");
    }

    // Let’s squash those words now
    compressMultipleWords(words, numWords, compressed, removedCounts);

    // Time to show off the results
    printf("Output: [");
    for (int i = 0; i < numWords; i++) {
        printf("\"%s\"", compressed[i]);
        if (i < numWords - 1) {
            printf(", ");
        }
    }
    //printf("]\n");

    return 0;
}
