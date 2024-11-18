#include <stdio.h>
#define SIZE 5

// Define a strut for the player's positon
typedef struct {
    int x; // X directin of player
    int y; //Y direction of  player
} Player;

//Function to Display grid
void display(char grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// the player position from grid
void find_player(char grid[SIZE][SIZE], Player *player) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] == 'P') {
                player->x = i;
                player->y = j;
                return;
            }
        }
    }
}

//Function for game logic
void gridGame(char grid[SIZE][SIZE], Player *player) {
    char direction;
    Player position;

    while (1) {
        //Display the grid
        display(grid);
        printf("Enter move (W: up, S: down, A: left, D: right, Q: quit): ");
        scanf(" %c", &direction);

        position.x = player->x;
        position.y = player->y;
        // direction
        if (direction == 'Q' || direction == 'q') {
            printf("Game Over! Thanks for playing.\nMade by Syed Anwer\nRoll No: 24K-0033");
            break;
        }

        switch (direction) {
            case 'W': case 'w': position.x--; break; // Move up
            case 'S': case 's': position.x++; break; // Move down
            case 'A': case 'a': position.y--; break; // Move left
            case 'D': case 'd': position.y++; break; // Move right
            default:
                printf("Invalid Input! Please enter W, A, S, D, or Q.\n");
                continue;
        }

        // Check boundaries
        if (position.x < 0 || position.x >= SIZE || position.y < 0 || position.y >= SIZE) {
            printf("Cannot move outside the grid! Try again.\n");
            continue;
        }

        // Check obstacles
        if (grid[position.x][position.y] == 'X') {
            printf("Obstacle encountered! Choose another direction.\n");
            continue;
        }

        // Handle item collection
        if (grid[position.x][position.y] == 'I') {
            printf("Item collected!\n");
        }

        // Update grid and player position
        grid[player->x][player->y] = ' ';           // Clear old position
        grid[position.x][position.y] = 'P'; // Set new position
        player->x = position.x;
        player->y = position.y;
    }
}

int main() {
    // Initialize the grid
    char grid[SIZE][SIZE] = {
        {' ', ' ', 'I', 'X', ' '},
        {' ', 'X', ' ', ' ', ' '},
        {'I', ' ', 'X', 'X', ' '},
        {' ', ' ', ' ', 'I', 'X'},
        {' ', 'X', ' ', ' ', 'P'}
    };

    // Create a Player struct and find the initial position
    Player player;
    find_player(grid, &player);

    // Start the game
    gridGame(grid, &player);

    return 0;
}
