/*Write a program that organizes a digital cricket match, "Cricket Showdown," where two players,
Player 1 and Player 2, compete over 12 balls. Each player takes turns to score runs on each ball.
Players can enter scores between 0 and 6 for each ball, and if a score outside this range is entered,
it will be disregarded, but the ball will still be marked.
1. Define a structure Player with the following members:
a. ballScores[12]: An array to store the score for each ball.
b. playerName: A string to hold the player's name.
c. totalScore: An integer to store the total score for each player.
2. Define functions:
a. playGame(struct Player player): This function prompts each player to enter their
score for each of the 12 balls.
b. validateScore(int score): This function checks if the score is between 0 and 6
(inclusive). If it’s not, the score is disregarded, but the ball is still marked.
c. findWinner(struct Player player1,struct Player player2): Determines the winner based
on the total score.
d. displayMatchScoreboard(struct Player player1,struct Player player2): Displays a
summary of each player’s performance, including each ball’s score, the average
score, and total score.*/

#include <stdio.h>
#include <windows.h>

typedef struct totalPlayers{
    int ballScores[12];
    char playerName[20];
    int totalScore;
}totalPlayers;

typedef struct Player{
    totalPlayers player1;
    totalPlayers player2;
}Player;



void playGame(Player player);
int validateScore(int score);
char* findWinner(Player player);
void displayMatchScoreBoard(Player player);

int main() 
{
    Player player;
    int choice;
    player.player1.totalScore = 0;      //initializing total scores to 0
    player.player2.totalScore = 0;
    while(choice!=2){

        printf("\n\t\tWelcome to Cricket Showdown!\n\n");
        Sleep(1000);
        printf("Enter:\n1. Play Game\n2. Exit Game\nYour choice: ");
        scanf("%d",&choice);
        switch(choice){

            case 1:
            playGame(player);
            break
;
            case 2:
            printf("\nGame Exiting..\n");
            Sleep(1000); 
            printf("Suceed.\n ");
            break;
        }

    }
    
    return 0;
}

void playGame(Player player){
    for(int i=0; i<12;i++){
        printf("\nRound %d!",i+1);
        printf("\nEnter score for player 1: ");
        scanf("%d",&player.player1.ballScores[i]);
        player.player1.ballScores[i] = validateScore(player.player1.ballScores[i]);
        player.player1.totalScore += player.player1.ballScores[i];
 
        printf("\nEnter score for player 2: ");
        scanf("%d",&player.player2.ballScores[i]);
        player.player2.ballScores[i] = validateScore(player.player2.ballScores[i]);
        player.player2.totalScore += player.player2.ballScores[i];
    }
    printf("\nCalculating Results...\n");
    Sleep(1000);
    displayMatchScoreBoard(player);
}
int validateScore(int score){
    if(!(score>=0&&score<=6))
    {
            printf("\nIncorrect score entered!\nScore for this ball is set to 0 default!\n ");
            score = 0;
            return score;
    }else{
        return score;
    }
}
char* findWinner(Player player){
    if(player.player1.totalScore>player.player2.totalScore){
        return "Player 1 wins";
    }else if(player.player2.totalScore>player.player1.totalScore){
        return "Player 2 wins";
    }else{
        return "Game is Draw";
    }
}

void displayMatchScoreBoard(Player player){
        printf("\nEnter your name(Player 1):");
        scanf("%s",player.player1.playerName);
        printf("\nEnter your name(Player 2):");
        scanf("%s",player.player2.playerName);
        Sleep(500);
        system("cls");
        float avg = 0;
        printf("\nSummary of %s: ",player.player1.playerName);
        for(int j=0;j<12;j++){
            printf("\nScore on Round %d: %d",j+1,player.player1.ballScores[j]);
        }
     avg = (float)(player.player1.totalScore/12.0);
        printf("\nTotal score of %s is: %d",player.player1.playerName,player.player1.totalScore);
        printf("\nThe total average of %s is: %.2f",player.player1.playerName,avg);
        printf("\n");
        printf("\nSummary of %s: ",player.player2.playerName);
        for(int j=0;j<12;j++){
            printf("\nScore on Round %d: %d",j+1,player.player2.ballScores[j]);
        }
        avg = (float)(player.player2.totalScore/12.0);
        printf("\nTotal score of %s is: %d",player.player2.playerName,player.player2.totalScore);
        printf("\nThe total average of %s is: %.2f",player.player2.playerName,avg);
        char *str = findWinner(player);
        printf("\n%s ",str);
}
