//GROUP MEMBERS - ROHAN RADADIYA (100704614), SIBI SABESAN (100750081), SYED AIRAJ HUSSAIN (100789134)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "questions.h"


question questions[NUM_QUESTIONS]; 
// Initializes the array of questions for the game
void initialize_game(void)
{
    // Initialize each question struct and assign it to the questions array
	const char *categories[] = {"programming" , "algorithms" , "databases"};
	
    for (int x = 0; x < 12; x++) {
    	strcpy(questions[x].category, categories[x % 3]);
    	questions[x].answered = false;
    	strcpy(questions[x].question, "The question is : ");
    	strcpy(questions[x].answer, "The answer is : ");
    }

	// questions for programming 200- 600 
    questions[0].value = 200;
    strcpy(questions[0].question, "What type of key uniquely identifies each record in a table?");
    strcpy(questions[0].answer, "Primary");

    questions[1].value = 400;
    strcpy(questions[1].question, "What type of database organizes data in tables with rows and columns? ");
    strcpy(questions[1].answer, "Relational");

    questions[2].value = 600;
    strcpy(questions[2].question, "What is the process of breaking down a large database into smaller, manageable parts called?");
    strcpy(questions[2].answer, "Sharding");
	
	// questions for algorithms 200- 600 
    questions[3].value = 200;
    strcpy(questions[3].question, "What sorting algorithm has a time complexity of O(n log n) on average?");
    strcpy(questions[3].answer, "QuickSort");

    questions[4].value = 400;
    strcpy(questions[4].question, "What algorithm is used to find the shortest path in a graph from one node to another?");
    strcpy(questions[4].answer, "Dijkstra");

    questions[5].value = 600;
    strcpy(questions[5].question, "What algorithmic paradigm is based on breaking a problem down into smaller subproblems and solving each of those subproblems?");
    strcpy(questions[5].answer, "Divide and Conquer");
	
	// questions for databases 200- 600 
    questions[6].value = 200;
    strcpy(questions[6].question, "What type of loop executes a block of code as long as a specified condition is true?");
    strcpy(questions[6].answer, "While");

    questions[7].value = 400;
    strcpy(questions[7].question, "What is a software design pattern that allows objects of different types to be treated as objects of the same type?");
    strcpy(questions[7].answer, "Polymorphism");

    questions[8].value = 600;
    strcpy(questions[8].question, "What is the process of combining multiple threads of execution to run simultaneously?");
    strcpy(questions[8].answer, "Multithreading");
}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    // print categories and dollar values for each unanswered question in questions array
    int length = 20;

    for (int x = 0; x < 3; ++x) {
		putchar('+');
		for (int y = 0; y < length; ++y)
			putchar('-');
	}
	printf("+\n");
	
	//creating categories for p,a,d
	const char *categories[] = {"programming" , "algorithms" , "databases"};
	for(int x = 0; x < 3; x++) 
		printf("| %-*s", length - 1, categories[x]);
	printf("|\n");

	for (int x = 0; x < 3; ++x) {
		putchar('+');
		for (int y = 0; y < length; ++y)
			putchar('-');
	}

	for(int x = 0; x < 12; x++) {
		if(questions[x].answered == false) {
			printf("| %-4d", questions[x].value);
		} else {
			printf("| %-*s", length - 2, " - ");
		}

		if(x % 3 == 2)
			printf("|\n");
	}

	for (int x = 0; x < 3; ++x) {
		putchar('+');
		for (int y = 0; y < length; ++y)
			putchar('-');
	}
}

// Displays the question for the category and dollar value
void display_question(char *category, int value)
{
	printf("Current Question (%s for $%d):\n", category, value);

	int num = qnum(category, value);
	if(num == -1)
		printf("the question %s doesn't exist %d\n", category, value);

	printf("\t%s\n", questions[num].question);
}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer)
{
	int num = qnum(category, value);
	if(num == -1)
		printf("the question %s doesn't exist , %d\n", category, value);

    // Look into string comparison functions
    return (strcmp(answer, questions[num].answer) == 0);
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
	for(int i = 0; i < 12; i++)
		if (questions[i].value == value && strcmp(questions[i].category, category) == 0)
			return questions[i].answered;

    // lookup the question and see if it's already been marked as answered
    return true;
}

void viewanswer(char *category, int value) {
	for(int i = 0; i < 12; i++) 
		if(questions[i].value == value && strcmp(questions[i].category, category) == 0)
			questions[i].answered = true;
}

bool hasitbeenanswered() {
	for(int i = 0; i < 12; i++)
		if(questions[i].answered == false)
			return false;

	return true;
}

int qnum(char *category, int value) {
	for(int i = 0; i < 12; i++)
		if(strcmp(questions[i].category, category) == 0 && questions[i].value == value)
			return i;


	return -1;
}
