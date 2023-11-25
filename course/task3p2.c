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

int main() {
    
    
    int buffer_size = 269; // The buffer temporarily holds the data from the file before it is needed
    char line[buffer_size];
    int counter = 0; // Keeps track of the loops in the file

    
    char FitnessData_2023[100];
    printf("Enter the file name ? \n");
    fgets(FitnessData_2023, sizeof(FitnessData_2023), stdin);
    FitnessData_2023[strcspn(FitnessData_2023 , "\n")] = '0';


FILE *input = fopen("FitnessData_2023.csv", "r"); // Fopen it opens the csv file 
//And it is set to 'r' which means that it will only read

if (input == NULL) {
    printf("There was a error when printing.\n"); // If theres no file found it will print this 
    //Stating that is there is no file in that name
    return 1;

}





 FITNESS_DATA *fit = malloc(120 * sizeof(fit)); // Is here to allocate the memory dynamically


char date[120]; // Setting variables for the date, time and steps and the size of the array it can hold
char time[120];
int steps;


 while (fgets(line, buffer_size, input) != NULL) // Fgets is a pointer to an array of charchters where the string 
 //Read will be stored. 
 //Buffer_size is the maximum amount of of charchers its reading
    {// Input is the file pointer which will find the file and it will read the file
    tokeniseRecord(line, ",", date, time, &steps);
    fit = realloc(fit, (counter + 1) * sizeof(FITNESS_DATA));
    strcpy(fit[counter].date, date);
    strcpy(fit[counter].time, time);
    



    char stepsgone[40]; // Assuming a maximum of 40 characters for the steps value
    snprintf(stepsgone, sizeof(stepsgone), "%d", steps);
    fit[counter].steps = atoi(stepsgone); // Atoi means it coverts ascii to an integer
    counter++;
    }

    qsort(fit, counter. sizeof(FitnessData), compareSteps);


      for (int i = 0; i < 3 && i < counter; i++){ // Change the loop to print out as many times as you want we are 
    //We are desiding for 3 times. This can be changed to any number you want so you can print out all 59
      
    printf("%s/%s/%d\n", fit[i].date, fit[i].time, fit[i].steps); // Split it up into this format %s prints the strings 
        //Which are date and time and %d prints the intger which is the steps
    }
    free(fit);

    fclose(input);
    return 0;
}
      
    
