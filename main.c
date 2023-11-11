#include <stdio.h>
#include <stdlib.h>

#include "excelbeolvas.h"

// Function to print questions
void printQuestions(Questions *head) {
    Questions *current = head;

    while (current != NULL) {
        printf("Difficulty: %d\n", current->difficulty);
        printf("Question: %s\n", current->question);
        printf("A: %s\n", current->optionA);
        printf("B: %s\n", current->optionB);
        printf("C: %s\n", current->optionC);
        printf("D: %s\n", current->optionD);
        printf("Answer: %c\n", current->answer);
        printf("Category: %s\n", current->category);

        current = current->next;

        printf("\n");
    }
}

int main() {
    Questions *head = NULL;
    const char *csvFilename = "C:\\Users\\Zephyrus\\Desktop\\kerdes.csv";  // Adjust the path accordingly
    readCSV(csvFilename, &head);
    printQuestions(head);
    freeQuestions(head);

    return 0;
}
