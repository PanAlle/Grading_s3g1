#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMBER_OF_ASSIGNMENT 4

typedef struct {
    char *FirstName;
    char *LastName;
    int PointOfAssignement[4];
    char *EmailAddress;
} Student;


void ReadFile(Student *Student) {
    FILE *fp;
    fp = fopen("C:\\Users\\utente\\CLionProjects\\Grading_s3g1\\Student_list.txt", "r");
    int i = 0;
    if (fp == NULL) {
        printf("Can't find the file");
    }
    char *buf = (char *) malloc(256);
    char *tmp;

    while (fgets(buf, 255, fp) != NULL) {
        //First strtok require tyo pass the string to be reduced in token
        tmp = strtok(buf, ",");
        Student[i].FirstName = strdup(tmp);

        //Following call of strtok require NULL as argument, that say to the string to continue tokenize the string previously passed
        tmp = strtok(NULL, ",");
        Student[i].LastName = strdup(tmp);
        //Remove the first charcter since it is a space
        memmove(Student[i].LastName, Student[i].LastName + 1, strlen(Student[i].LastName));


        for (int j = 0; j < NUMBER_OF_ASSIGNMENT; ++j) {
            tmp = strtok(NULL, ",");
            Student[i].PointOfAssignement[j] = atoi(tmp);
        }

        tmp = strtok(NULL, ",");
        Student[i].EmailAddress = strdup(tmp);
        memmove(Student[i].EmailAddress, Student[i].EmailAddress + 1, strlen(Student[i].EmailAddress));
        //Delete the last value, that is a /n new line command. This apply to all line but the last, that's why we need a if statement
        if (Student[i].EmailAddress[strlen(Student[i].EmailAddress) - 1] == '\n') {
            Student[i].EmailAddress[strlen(Student[i].EmailAddress) - 1] = 0;
        }
        //Iterate throught the struct
        i++;
    }

    fclose(fp);

}


void WriteFile(Student *Student) {
    FILE *fw;
    fw = fopen("C:\\Users\\utente\\CLionProjects\\Grading_s3g1\\Destination_list.txt", "w");
    if (fw == NULL) {
        printf("Can't find the file");
    }
    int i = 0;
    float Points = 0;
    for (int j = 0; j < NUMBER_OF_ASSIGNMENT; j++) {
        Points += Student[i].PointOfAssignement[j];
    }
    float Grade = 0;
    if (Points >= 0.0 && Points <= 50) Grade = 5.0;
    else if (Points >= 50 && Points <= 55.5) Grade = 4.0;
    else if (Points >= 55.5 && Points <= 60.5) Grade = 3.7;
    else if (Points >= 60.5 && Points <= 65.5) Grade = 3.3;
    else if (Points >= 65.5 && Points <= 70.5) Grade = 3.0;
    else if (Points >= 70.5 && Points <= 75.5) Grade = 2.7;
    else if (Points >= 75.5 && Points <= 81) Grade = 2.3;
    else if (Points >= 81 && Points <= 86) Grade = 2.0;
    else if (Points >= 86 && Points <= 91) Grade = 1.7;
    else if (Points >= 91 && Points <= 96) Grade = 1.3;
    else if (Points >= 96 && Points <= 100) Grade = 1.0;

    for (int k = 0; k < 2; ++k) {
        fprintf(fw, "%s %s <%s>: %1.1f\n", Student[i].FirstName, Student[i].LastName, Student[i].EmailAddress, Grade);
        i++;
    }
    fclose(fw);

}

int main() {
    Student Student[100];
    ReadFile(Student);
    printf("Counter in main loop %d\n", sizeof(Student) / sizeof(Student[0]));
    WriteFile(Student);


}
