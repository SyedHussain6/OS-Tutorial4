// GROUP MEMBERS - ROHAN RADADIYA (100704614), SIBI SABESAN (100750081), SYED AIRAJ HUSSAIN (100789134)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>
#include "questions.h"
#include "players.h"
#include "jeopardy.h"

// Define macros or constants
#define BUFFER_LEN 256
#define NUM_PLAYERS 4

// Function to tokenize user's answer
void tokenize(char *input, char **tokens);

// Function to display game results
void show_results(player *players, int num_players);

// Main function where the game logic is implemented
int main(void)
{
    // Array to store player information
    player players[NUM_PLAYERS];

    // Display the game introduction and initialize questions
    initialize_game();

    // Display welcome message for players
    printf("Welcome to OS Jeopardy!\n");

    // Initialize each player's score and prompt for their names
    for(int x = 0; x < NUM_PLAYERS; x++) {
        players[x].total_score = 0;

        printf("Please enter player's name: ");
        scanf("%s", (char *) &players[x].name);
    }

    // Continue the game until all questions are answered
    while(!hasitbeenanswered())
    {
        // Clear the screen for a clean interface
        system("clear");

        // Variables to store user inputs
        char currentplayer[MAX_LEN] = "";
        char currentcategory[MAX_LEN] = "";
        int currentvall = 0;

        // Prompt for player's name until a valid one is entered
        do {
            char message[MAX_LEN] = "";
            if(strcmp(currentplayer, "") != 0){
                strcat(message, "Player ");
                strcat(message, currentplayer);
                strcat(message, " not found\n");
                printf("%s", message);
            }
            printf("Enter player's name: ");
            scanf("%s", (char *) &currentplayer);
        } while(!realplayer(players, NUM_PLAYERS, currentplayer));

        // Prompt for category and value of the question until a valid combination is entered
        do {
            if(currentvall != 0) {
                printf("Wrong Option!!\n");
            }
            printf("Please choose a category (programming, algorithms, databases): ");
            getchar();
            fgets((char *) currentcategory, MAX_LEN, stdin);
            strtok(currentcategory, "\n");

            printf("Choose the value of the question (200, 400, 600): ");
            scanf("%d", &currentvall);
        } while(already_answered(currentcategory, currentvall));

        // Display the question for the selected category and value

        display_question(currentcategory, currentvall);

        // Get and tokenize the user's answer
        char answer[MAX_LEN] = "";
        getchar();
        fgets(answer, MAX_LEN, stdin);

        char *tokenize_answer;
        tokenize(answer, &tokenize_answer);

        // Validate the user's answer and update player's score
        if(tokenize_answer == NULL)
            printf("Go again \n");
        else if(valid_answer(currentcategory, currentvall, tokenize_answer)) {
            printf("The CORRECT ANSWER: \n");
            printf("%s gains %d points \n", currentplayer, currentvall);
            update_score(players, NUM_PLAYERS, currentplayer, currentvall);
        } else {
            printf("INCORRECT ANSWER!: \n");
            int num = qnum(currentcategory, currentvall);
            printf("CORRECT ANSWER: %s\n", questions[num].answer);
        }

        viewanswer(currentcategory, currentvall);
    }

    // Display final results and declare the winner
    show_results(players, NUM_PLAYERS);
    getchar();

    return EXIT_SUCCESS;
}

// Function to tokenize user's answer
void tokenize(char *input, char **tokens) {
    char *str;

    // Tokenize the answer if it starts with "who" or "what" followed by "is"
    if((str = strtok(input, " ")) != NULL)
        if(strcmp(str, "WHO") != 0 && strcmp(str, "WHA") != 0)
            return;

    if((str = strtok(NULL, " ")) != NULL)
        if(strcmp(str, "IS") != 0)
            return;

    *tokens = strtok(NULL, "\n");
}

// Function to display game results
void show_results(player *players, int num_players) {
    int max_name_length = 0;
    int max_score = 0;
    int winner_index = 0;

    // Find the maximum length of player names and the winner's score
    for(int x= 0; x < num_players; x++) {
        if((int) strlen(players[x].name) > max_name_length)
            max_name_length = strlen(players[x].name);

        if(players[x].total_score > max_score) {
            max_score = players[x].total_score;
            winner_index = x;
        }
    }

    // Display the scores and declare the winner
    printf("Total Scores:\n");
    for(int x = 0; x < num_players; x++)
        printf("%*s: %d\n", max_name_length + 1, players[x].name, players[x].total_score);

    printf("The winner is: %s\n", players[winner_index].name);
}
