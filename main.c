#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMBER_OF_ASSIGNMENT 4

typedef struct {
    char *FirstName;
    char *LastName;
    int  PointOfAssignement[4];
    char *EmailAddress;
}Student;


void ReadFile(Student *Student) {
    FILE *fp;
    fp = fopen("C:\\Users\\utente\\CLionProjects\\Grading_s3g1\\Student_list.txt", "r");
    int i = 0;
    if (fp  == NULL)
    {
        printf("Can't find the file");
    }
    char *buf = (char*)malloc(256);
    char *tmp;

    while (fgets(buf, 255, fp) != NULL){
        //First strtok require tyo pass the string to be reduced in token
        tmp = strtok(buf, ",");
        Student[i].FirstName = malloc(sizeof(tmp)+1);
        strcpy(Student[i].FirstName, tmp);

        //Following call of strtok require NULL as argument, that say to the string to continue tokenize the string previously passed
        tmp = strtok(NULL, ",");
        Student[i].LastName = malloc(sizeof(tmp)+1);
        strcpy(Student[i].LastName, tmp);

        for (int j = 0; j < NUMBER_OF_ASSIGNMENT; ++j) {
        tmp = strtok(NULL, ",");
        Student[i].PointOfAssignement[j] = atoi(tmp);

        }

        tmp = strtok(NULL, ",");
        Student[i].EmailAddress = malloc(sizeof(tmp)+1);
        strcpy(Student[i].EmailAddress, tmp);
    }

    fclose(fp);

}


int main() {
    Student Student[100];
    ReadFile(Student);


}
