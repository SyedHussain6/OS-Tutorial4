//GROUP MEMBERS - ROHAN RADADIYA (100704614), SIBI SABESAN (100750081), SYED AIRAJ HUSSAIN (100789134)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "players.h"

// Checks if a player with the given name exists in the player list
bool realplayer(player *players, int num_players, char *name) {
    for (int x = 0; x < num_players; x++) {
        if (strcmp(players[x].name, name) == 0)
            return true;
    }
    return false;
}

void update_score(player *players, int num_players, char *name, int total_score) {
    for (int x = 0; x < num_players; x++) {
        if (strcmp(players[x].name, name) == 0)
            players[x].total_score += total_score;
    }
}

// Update the score of a player with the given name
void modify_player_score(player *players, int num_players, char *name, int total_score)
{
    // Iterate through the list of players
    for (int x = 0; x < num_players; x++) {
        // Check if the player's name matches the given name
        if (strcmp(players[x].name, name) == 0) 
            players[x].total_score += total_score; // Update the player's score
    }
}
