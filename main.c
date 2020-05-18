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


void ReadFile(Student *Student, int *counter, char *ReadFileName) {
    FILE *fp;
    fp = fopen( ReadFileName, "r");
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
        *counter = i;
        i++;
    }

    fclose(fp);

}


void WriteFile(Student *Student, int* counter, char* WriteFileName) {
    FILE *fw;
    fw = fopen(WriteFileName, "w");
    if (fw == NULL) {
        printf("Can't find the file");
    }

    for (int k = 0; k <= *counter; ++k) {
    float Points = 0;
    for (int j = 0; j < NUMBER_OF_ASSIGNMENT; j++) {
        Points += Student[k].PointOfAssignement[j];
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

    fprintf(fw, "%s %s <%s>: %1.1f\n", Student[k].FirstName, Student[k].LastName, Student[k].EmailAddress, Grade);

    }
    fclose(fw);

}

void HighScore(Student *Student, int* counter){
    float high_score = 0;
    float max_grade = 0;
    int  ID = 0;

    for (int k = 0; k <= *counter; ++k) {
        float current_score = 0;
    for (int i = 0; i < NUMBER_OF_ASSIGNMENT; ++i) {
        current_score += Student[k].PointOfAssignement[i];
    }
    if (current_score > high_score){
        high_score = current_score;
        ID = k;
    }
        if (high_score >= 0.0 && high_score <= 50) max_grade = 5.0;
        else if (high_score >= 50 && high_score <= 55.5) max_grade = 4.0;
        else if (high_score >= 55.5 && high_score <= 60.5) max_grade = 3.7;
        else if (high_score >= 60.5 && high_score <= 65.5) max_grade = 3.3;
        else if (high_score >= 65.5 && high_score <= 70.5) max_grade = 3.0;
        else if (high_score >= 70.5 && high_score <= 75.5) max_grade = 2.7;
        else if (high_score >= 75.5 && high_score <= 81) max_grade = 2.3;
        else if (high_score >= 81 && high_score <= 86) max_grade = 2.0;
        else if (high_score >= 86 && high_score <= 91) max_grade = 1.7;
        else if (high_score >= 91 && high_score <= 96) max_grade = 1.3;
        else if (high_score >= 96 && high_score <= 100) max_grade = 1.0;
    }
    printf("%s %s <%s>: %1.1f\n", Student[ID].FirstName, Student[ID].LastName, Student[ID].EmailAddress, max_grade);

}

int main() {
    //char ptr to the read and write file destination
    char *ReadFileName = "C:\\Users\\utente\\CLionProjects\\Grading_s3g1\\Student_list.txt";
    char *WriteFileName = "C:\\Users\\utente\\CLionProjects\\Grading_s3g1\\Destination_list.txt";
    //Initialize a counter for the number of Student instaces are present in the Read File
    int counter = 0;
    Student Student[100];
    ReadFile(Student,  &counter, ReadFileName);
    WriteFile(Student, &counter, WriteFileName);
    HighScore(Student, &counter);


}
