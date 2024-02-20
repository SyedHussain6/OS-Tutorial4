//GROUP MEMBERS - ROHAN RADADIYA (100704614), SIBI SABESAN (100750081), SYED AIRAJ HUSSAIN (100789134)



#ifndef JEOPARDY_H_
#define JEOPARDY_H_

#define MAX_LEN 256

extern bool realplayer(player *players, int num_players, char *name);

// Function to process the user's answer and tokenize it to retrieve the answer.
extern void process_answer(char *input, char **tokens);

// Function to display the final results of the Jeopardy game for each player, including their name and score.
extern void display_results(player *players, int num_players);

#endif /* JEOPARDY_H_ */
