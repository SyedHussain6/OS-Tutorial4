//GROUP MEMBERS - ROHAN RADADIYA (100704614), SIBI SABESAN (100750081), SYED AIRAJ HUSSAIN (100789134)
#ifndef QUESTIONS_H
#define QUESTIONS_H

#include <stdbool.h>

#define MAX_QUESTION_LENGTH 256
#define NUM_CATEGORIES 3
#define NUM_QUESTIONS 12

// Questions struct for each question
typedef struct {
    char category[MAX_QUESTION_LENGTH];
    char question[MAX_QUESTION_LENGTH];
    char answer[MAX_QUESTION_LENGTH];
    int value;
    bool answered;
} question;

// An array of 12 questions (4 for each category), initialized in initialize_game
// this may need to be a pointer if you want it set dynamically

extern question questions[NUM_QUESTIONS];

// Initializes the array of questions for the game
extern void initialize_game(void);

// Displays each of the remaining categories and question dollar values that have not been answered
extern void display_categories(void);

// Displays the question for the category and dollar value
extern void display_question(char *category, int value);

// Returns true if the answer is correct for the question for that category and dollar value
extern bool valid_answer(char *category, int value, char *answer);

// Returns true if the question has already been answered
extern bool already_answered(char *category, int value);


// Track if a question has been answered
extern void viewanswer(char *category, int value);

// Check if a question has been answered
extern bool hasitbeenanswered(void);

// Get the index of a question in the array based on category and value
extern int qnum(char *category, int value);




#endif /* QUESTIONS_H */
