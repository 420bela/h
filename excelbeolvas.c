#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "excelbeolvas.h"
#include "beolvas.h"

void readCSV(const char *filename, Questions **head) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Failed to open the file.\n");
        return;
    }

    // Skip the header row
    if (fscanf(file, "%*[^\n]\n") == EOF) {
        printf("Error: Failed to read the header row.\n");
        fclose(file);
        return;
    }

    Questions *last = NULL;  // Pointer to the last element
    while (fscanf(file, "%d,%99[^,],%19[^,],%19[^,],%19[^,],%19[^,],%c,%9[^,\n]\n",
                  &(last->difficulty), last->question, last->optionA, last->optionB, last->optionC, last->optionD, &(last->answer), last->category) == 8) {
        // Create a new question and append it to the list
        Questions *new_question = createQuestion(last->difficulty, last->question, last->optionA, last->optionB, last->optionC, last->optionD, last->answer, last->category);
        appendQuestion(*head, new_question);
        last = new_question;  // Update the pointer to the last element
    }

    fclose(file);
}
