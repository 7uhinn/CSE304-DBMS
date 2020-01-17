#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Student
{
    int rollno;
    char name[20];
    int age;
    char branch[4];
};

void exsort(FILE **fp)
{
    struct Student stud[2];
    int flag1 = 0, flag2 = 0;

    fread(&stud[0], sizeof(struct Student), 1, fp[0]);
    fread(&stud[1], sizeof(struct Student), 1, fp[1]);

    while (!flag1 && !flag2)
    {
        if (stud[0].rollno <= stud[1].rollno)
        {
            fwrite(&stud[0], sizeof(struct Student), 1, fp[2]);
            fread(&stud[0], sizeof(struct Student), 1, fp[0]);
            flag1 = feof(fp[0]);
        }

        else
        {
            fwrite(&stud[1], sizeof(struct Student), 1, fp[2]);
            fread(&stud[1], sizeof(struct Student), 1, fp[1]);
            flag2 = feof(fp[1]);
        }
    }

    if (flag1)
    {
        while (!feof(fp[1]))
        {
            fread(&stud[1], sizeof(struct Student), 1, fp[1]);
            fwrite(&stud[1], sizeof(struct Student), 1, fp[2]);
        }
    }

    if (flag2)
    {
        while (!feof(fp[0]))
        {
            fread(&stud[0], sizeof(struct Student), 1, fp[0]);
            fwrite(&stud[0], sizeof(struct Student), 1, fp[2]);
        }
    }

    free(fp);
}

int main()
{
    FILE **fp = malloc(sizeof(FILE *) * (3));

    fp[0] = fopen("f1s.txt", "r");
    fp[1] = fopen("f2s.txt", "r");
    fp[2] = fopen("f3s.txt", "w");

    clock_t begin = clock();

    exsort(fp);

    clock_t end = clock();

    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Time elpased is %f seconds", time_spent);
}