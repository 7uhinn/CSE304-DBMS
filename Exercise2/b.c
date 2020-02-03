#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

struct Student
{
    int rollno;
    char name[20];
    int age;
    char branch[4];
};

struct IndFile
{
    int rollno;
    int offset;
};

int main()
{
    FILE *indf, *data;
    struct Student stud;
    struct IndFile ind;

    indf = fopen("index.txt", "r");
    data = fopen("data.txt", "r");

    int key = 0, flag = 1;
    printf("Enter the roll number you are looking for: ");
    scanf("%d", &key);

    clock_t begin = clock();
    int count = 0;
    while (fread(&ind, sizeof(struct IndFile), 1, indf))
    {
        if (ind.rollno == key)
        {
            fseek(data, ind.offset * sizeof(struct Student), SEEK_SET);
            fread(&stud, sizeof(struct Student), 1, data);
            printf("Rollno = %d    Name = %s    Age = %d    Branch = %s\n", stud.rollno, stud.name, stud.age, stud.branch);
            flag = 0;
            break;
        }
    }

    if (flag)
    {
        printf("Not present \n");
    }

    clock_t end = clock();

    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Time elpased is %f seconds", time_spent);
}