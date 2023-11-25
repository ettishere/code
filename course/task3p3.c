#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

struct FitnessStruct{
    char csv[100];
};
// Function to tokenize a record
void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps) {
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL) {
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL) {
            strcpy(time, ptr);
            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL) {
                *steps = atoi(ptr);
            }
        }
    }
}

// Function to compare the steps for sorting
int compareSteps(const void *a, const void *b) {
    const FitnessData *fitnessDataA = a;
    const FitnessData *fitnessDataB = b;

    return fitnessDataB->steps - fitnessDataA->steps;
}

int main() {
    int buffer_size = 269;
    char line[buffer_size];
    int counter = 0;

    struct FitnessStruct FitnessData_2023;
    printf("Enter the file name?\n");
    fgets(FitnessData_2023.csv, sizeof(FitnessData_2023.csv), stdin);
    FitnessData_2023.csv[strcspn(FitnessData_2023.csv , "\n")] = '\0';

    FILE *input = fopen(FitnessData_2023.csv, "r");

    if (input == NULL) {
        printf("There was an error when opening the file.\n");
        return 1;
    }

    FitnessData *fit = malloc(120 * sizeof(FitnessData));

    char date[120];
    char time[120];
    int steps;

    while (fgets(line, buffer_size, input) != NULL) {
        tokeniseRecord(line, ',', date, time, &steps);
        fit = realloc(fit, (counter + 1) * sizeof(FitnessData));
        strcpy(fit[counter].date, date);
        strcpy(fit[counter].time, time);
        fit[counter].steps = steps;
        counter++;
    }

    qsort(fit, counter, sizeof(FitnessData), compareSteps);

    for (int i = 0; i < 3 && i < counter; i++) {
        printf("%s/%s/%d\n", fit[i].date, fit[i].time, fit[i].steps);
    }

    free(fit);
    fclose(input);
    return 0;
}