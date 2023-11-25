#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

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

int compare(const void *a, const void *b ){
    return ((FitnessData *)b)->steps - ((FitnessData *)a)->steps;

}
int main(){
    const char fit[] = "FitnessData_2023.csv";

    File *file = fopen(fit, "r");

    if (fit == NULL){
        printf("Error opening file: %d\n", fit);
        return 1;
    }


    int count = 0;
    char line[100];
    while (fgets(line, sizeof(line), fit) != NULL)|{
        count++;


    }

    FitnessData *record = (FitnessData *)malloc(count * sizeof(FitnessData));
    if (data == NULL){

        printf("getting data\n");
        fclose(fit);
        return 1;
    }
    rewind(fit);


    int i = 0;
    while (fgets(line, sizeof(line,), fit) != NULL){
        tokeniseRecord(line, ',' data[i].date, data[i].time, &data[i].steps);
         i++;
    }

    fclose(fit);

    qsort(data, record, sizeof(FitnessData), compareSteps);


    free(data)

    return 0;

}