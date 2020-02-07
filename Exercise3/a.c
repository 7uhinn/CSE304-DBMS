#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Student
{
    int rollno;
    char name[20];
    int age;
    char branch[4];
};

struct Index
{
    int rollno;
    int lc;
    int rc;
    int offset;
};

int generation(char *s, int len)
{
    char alphanum[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < len; ++i)
    {
        s[i] = alphanum[rand() % (sizeof(alphanum))];
    }

    s[len] = '\0';
}

int main()
{
    FILE *f1;
    struct Student stud1;

    f1 = fopen("data.txt", "w");

    int n = 1000000;

    printf("Generating file...");
    for (int i = 0; i < n; i++)
    {
        generation(stud1.name, 5);
        stud1.rollno = (rand() % (1000000));
        stud1.age = (rand() % (50));
        strcpy(stud1.branch, "CSE");
        fwrite(&stud1, sizeof(struct Student), 1, f1);
    }
}
