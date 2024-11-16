/*
* Name: Syed Anwer
* Section: BAI-1A
* Roll #:24K-0033
* Subject: Programming Fundamentals Assignment #2
* Question: 4
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// We will use DMA and structure algorithm in this problem.
// Helper function to sort a string
void sortString(char* sortWord) {
    int len = strlen(sortWord);
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (sortWord[j] > sortWord[j + 1]) {
                char store = sortWord[j];
                sortWord[j] = sortWord[j + 1];
                sortWord[j + 1] = store;
            }
        }
    }
}

// Structure for storing groups
typedef struct {
    char** group;     // Array of strings in the group
    int size;         // Current size of the group
    int capacity;     // Capacity of the group
} Group;

// Resize group dynamically
void addToGroup(Group* g, char* transaction) {
    if (g->size == g->capacity) {
        g->capacity *= 2;
        g->group = realloc(g->group, g->capacity * sizeof(char*));
    }
    g->group[g->size++] = transaction;
}

// Function to parse the input string into an array of words
int parseInput(char* input, char*** words) {
    // Remove "words = " part
    char* start = strchr(input, '[');
    if (!start) {
        printf("Invalid input format.\n");
        return 0;
    }
    start++; // Skip the '['

    // Remove trailing ']'
    char* end = strchr(start, ']');
    if (!end) {
        printf("Invalid input format.\n");
        return 0;
    }
    *end = '\0';

    // Count the number of words
    int count = 0;
    char* store = strdup(start);
    char* token = strtok(store, ",");
    while (token) {
        count++;
        token = strtok(NULL, ",");
    }
    free(store);

    // Allocate memory for words array
    *words = malloc(count * sizeof(char*));

    // Extract words and remove quotes
    token = strtok(start, ",");
    int i = 0;
    while (token) {
        while (*token == ' ' || *token == '"') token++; // Skip spaces and quotes
        char* wordEnd = strrchr(token, '"');
        if (wordEnd) *wordEnd = '\0';
        (*words)[i++] = strdup(token);
        token = strtok(NULL, ",");
    }
    return count;
}

// Main function to group scrambled transactions
void groupScrambledTransactions(char* transactions[], int n) {
    Group* groups = malloc(n * sizeof(Group)); // Array of groups
    char** sortedKeys = malloc(n * sizeof(char*)); // Array to store sorted keys
    int groupCount = 0;

    for (int i = 0; i < n; i++) {
        sortedKeys[i] = strdup(transactions[i]);
        sortString(sortedKeys[i]);

        // Check if the sorted key already exists in any group
        int found = 0;
        for (int j = 0; j < groupCount; j++) {
            if (strcmp(sortedKeys[i], sortedKeys[j]) == 0) {
                addToGroup(&groups[j], transactions[i]);
                found = 1;
                break;
            }
        }

        // If not found, create a new group
        if (!found) {
            groups[groupCount].group = malloc(n * sizeof(char*));
            groups[groupCount].size = 0;
            groups[groupCount].capacity = n;
            addToGroup(&groups[groupCount], transactions[i]);
            sortedKeys[groupCount] = sortedKeys[i];
            groupCount++;
        } else {
            free(sortedKeys[i]);
        }
    }

    // Print the groups
    printf("[");
    for (int i = 0; i < groupCount; i++) {
        printf("[");
        for (int j = 0; j < groups[i].size; j++) {
            printf("\'%s\'", groups[i].group[j]);
            if (j < groups[i].size - 1) {
                printf(", ");
            }
        }
        printf("],");
        free(groups[i].group);
    }
    printf("]");
    // Clean up
    free(groups);
    free(sortedKeys);
}

int main() {
    char input[1024];
    printf("Enter the transactions in the format words = [\"word1\", \"word2\", ...]:\n");
    fgets(input, sizeof(input), stdin);
    char** words;
    int count = parseInput(input, &words);

    if (count > 0) {
        // Group scrambled transactions
        groupScrambledTransactions(words, count);

        // Free allocated memory
        for (int i = 0; i < count; i++) {
            free(words[i]);
        }
        free(words);
    }

    return 0;
}
