#include <stdio.h>

int first_pick(int sticks) {
    // If the total number of sticks is a multiple of 5, no guaranteed winning strategy
    if (sticks % 5 == 0) {
        return -1; 
    }
    // Otherwise, return the number of sticks to pick for a guaranteed win
    return sticks % 5;
}

int main() {
    int sticks;
    
    // Prompt user for the total number of matchsticks
    printf("Enter the total number of matchsticks: ");
    scanf("%d", &sticks);

    // Call the function to determine the optimal first move
    int move = first_pick(sticks);

    // Display the result
    if (move == -1) {
        printf("No guaranteed winning strategy exists for Player A.\n");
    } else {
        printf("Player A should pick %d matchstick(s) on their first turn to guarantee a win.\n", move);
    }

    return 0;
}
