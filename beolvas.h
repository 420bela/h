#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

#include <stdio.h>

// Structure definition for questions
typedef struct Questions {
    int difficulty;
    char question[100];
    char optionA[20];
    char optionB[20];
    char optionC[20];
    char optionD[20];
    char answer;
    char category[10];
    struct Questions *next;

} Questions;

// Function declarations
Questions *createQuestion(int difficulty, char *question, char *optionA, char *optionB, char *optionC, char *optionD, char answer, char *category);

void appendQuestion(Questions *head, Questions *newQuestion);

void freeQuestions(Questions *head);

#endif // INPUT_H_INCLUDED
