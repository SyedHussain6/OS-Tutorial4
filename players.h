//GROUP MEMBERS - ROHAN RADADIYA (100704614), SIBI SABESAN (100750081), SYED AIRAJ HUSSAIN (100789134)

#ifndef PLAYERS_H_
#define PLAYERS_H_

#include <stdbool.h>
#include "players.h"

#define MAX_NAME_LENGTH 256

// Player struct to represent each player
typedef struct {
    char name[MAX_NAME_LENGTH]; // Name of the player
    int total_score; // Total score of the player
} player;

//updating score 
extern void update_score(player *players, int num_players, char *name, int total_score);


// Update the score of a player with the given name
extern void modify_player_score(player *players, int num_players, char *name, int total_score);

#endif /* PLAYERS_H_ */
