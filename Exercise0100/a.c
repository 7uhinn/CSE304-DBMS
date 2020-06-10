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
    int offset;
};

int generation(char *s, int len)
{
    char alphanum[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < len-1; ++i)
    {
        s[i] = alphanum[rand() % (sizeof(alphanum))];
    }

    s[len] = '\0';
}

int main()
{
    FILE *f1, *f2;
    struct Student stud;
    struct Index ind[10];
    int hash = 0, o = 0;

    f1 = fopen("data.txt", "w");
    f2 = fopen("index.txt", "w");

    int n = 10;

    printf("Generating file...\n");
    for (int i = 19; i > 9; i--)
    {
        generation(stud.name, 5);
        stud.age = (rand() % (50));
        strcpy(stud.branch, "CSE");
        stud.rollno = i;
        printf("Rollno = %d    Name = %s    Age = %d    Branch = %s\n", stud.rollno, stud.name, stud.age, stud.branch);
        fwrite(&stud, sizeof(struct Student), 1, f1);

        hash = i%10;

        ind[hash].rollno = i;
        ind[hash].offset = o;
        o++;
    }

    printf(".....................................................................\n");
    for (int i = 0; i < n; i++)
    {
        printf("Rollno = %d   Offset = %d\n", ind[i].rollno, ind[i].offset);
        fwrite(&ind[i], sizeof(struct Index), 1, f2);
    }
}
