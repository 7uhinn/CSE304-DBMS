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

void fileGen(FILE *fp, FILE **files, char *p[])
{
    int t = 1000000;
    int w = t / 1;
    int i = 0, j = 0;

    struct Student student;

    for (int k = 0; k < 10; k++)
    {
        files[k] = fopen(p[k], "w");
    }

    while (i < 10)
    {
        for (j = i * w; j < w * (i + 1); j++)
        {
            fread(&student, sizeof(struct Student), 1, fp);
            fwrite(&student, sizeof(struct Student), 1, files[i]);
        }
        fclose(files[i]);
        i++;
    }
}

int compare(const void *a, const void *b)
{

    struct Student *stud1 = (struct Student *)a;
    struct Student *stud2 = (struct Student *)b;

    return (stud1->rollno - stud2->rollno);
}

void merge(FILE **files, char *p[])
{
    for (int k = 1; k < 10; k++)
    {
        files[k] = fopen(p[k], "r");
    }

    struct Student stud[2];
    int flag1 = 0, flag2 = 0;

    FILE **temp = malloc(sizeof(FILE *) * (9));
    char *q[10] = {"1.txt", "s.txt", "s3.txt", "s4.txt", "s5.txt", "s6.txt", "s7.txt", "s8.txt", "s9.txt", "f1s.txt"};

    for (int i = 1; i < 10; i++)
    {
        temp[i - 1] = fopen(q[i - 1], "r");
        temp[i] = fopen(q[i], "w");

        fread(&stud[0], sizeof(struct Student), 1, temp[i - 1]);
        fread(&stud[1], sizeof(struct Student), 1, files[i]);

        while (!flag1 && !flag2)
        {
            if (stud[0].rollno <= stud[1].rollno)
            {
                fwrite(&stud[0], sizeof(struct Student), 1, temp[i]);
                fread(&stud[0], sizeof(struct Student), 1, temp[i - 1]);
                flag1 = feof(temp[i - 1]);
            }

            else
            {
                fwrite(&stud[1], sizeof(struct Student), 1, temp[i]);
                fread(&stud[1], sizeof(struct Student), 1, files[i]);
                flag2 = feof(files[i]);
            }
        }

        if (flag1)
        {
            while (!feof(files[i]))
            {
                fread(&stud[1], sizeof(struct Student), 1, files[i]);
                fwrite(&stud[1], sizeof(struct Student), 1, temp[i]);
                flag1 = 0;
            }
        }

        if (flag2)
        {
            while (!feof(temp[i - 1]))
            {
                fread(&stud[0], sizeof(struct Student), 1, temp[i - 1]);
                fwrite(&stud[0], sizeof(struct Student), 1, temp[i]);
                flag2 = 0;
            }
        }

        fclose(temp[i]);
        fclose(temp[i - 1]);
        fclose(files[i]);
        remove(q[i - 1]);
        remove(p[i]);
    }
}

void fileSorter(FILE **files, char *p[])
{
    struct Student stud[100000];

    for (int k = 0; k < 10; k++)
    {
        files[k] = fopen(p[k], "r");

        for (int i = 0; i < 100000; i++)
        {
            fread(&stud[i], sizeof(struct Student), 1, files[k]);
        }

        fclose(files[k]);

        qsort(&stud[0], 100000, sizeof(stud[0]), compare);

        files[k] = fopen(p[k], "w");

        for (int i = 0; i < 100000; i++)
        {
            fwrite(&stud[i], sizeof(struct Student), 1, files[k]);
        }

        fclose(files[k]);
    }

    merge(files, p);
}

int main()
{
    FILE *fp;
    FILE **files = malloc(sizeof(FILE *) * (10));

    char *p[10] = {"1.txt", "2.txt", "3.txt", "4.txt", "5.txt", "6.txt", "7.txt", "8.txt", "9.txt", "10.txt"};

    fp = fopen("f1.txt", "r");

    clock_t begin = clock();

    fileGen(fp, files, p);

    fileSorter(files, p);

    clock_t end = clock();

    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Time elpased is %f seconds", time_spent);
}
