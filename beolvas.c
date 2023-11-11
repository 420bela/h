#include "beolvas.h"
#include <stdio.h>
#include <stdlib.h>

// Function to create a new question
Questions *createQuestion(int difficulty, char *question, char *optionA, char *optionB, char *optionC, char *optionD, char answer, char *category) {
    // Allocate memory for a new question
    Questions *newElement = (Questions *)malloc(sizeof(Questions));

    // Initialize the fields of the new question
    sprintf(newElement->question, "%s", question);
    sprintf(newElement->optionA, "%s", optionA);
    sprintf(newElement->optionB, "%s", optionB);
    sprintf(newElement->optionC, "%s", optionC);
    sprintf(newElement->optionD, "%s", optionD);
    sprintf(newElement->category, "%s", category);
    newElement->answer = answer;
    newElement->difficulty = difficulty;
    newElement->next = NULL;

    return newElement;
}

// Function to append a question to the end of the list
void appendQuestion(Questions *head, Questions *newQuestion) {
    Questions *current = head;

    // Traverse the list to find the last element
    while (current->next != NULL) {
        current = current->next;
    }

    // Append the new question to the end of the list
    current->next = newQuestion;
}

// Function to free the memory allocated for the list of questions
void freeQuestions(Questions *head) {
    Questions *current = head;
    Questions *next = head->next;

    // Traverse the list and free each element
    while (current != NULL) {
        free(current);
        current = next;

        // Move to the next element if it exists
        if (next != NULL) {
            next = next->next;
        }
    }
}
