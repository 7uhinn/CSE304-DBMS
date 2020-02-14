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
    FILE *f1, *f2;
    struct Student stud;
    struct Index ind;
    int roll[20];
    int temp;
    int f = 0, k = 0, s = 0;

    f1 = fopen("data.txt", "w");
    f2 = fopen("index.txt", "w");

    int n = 20;

    printf("Generating file...");
    for (int i = 0; i < n; i++)
    {
        generation(stud.name, 5);
        stud.age = (rand() % (50));
        strcpy(stud.branch, "CSE");

        while (s == 0)
        {
            temp = (rand() % (100));
            for (int j = 0; j < sizeof(roll); j++)
            {
                if (temp == roll[j])
                {
                    f = 1;
                    break;
                }
            }
            if (f==0)
            {
                roll[k] = temp;
                stud.rollno = temp;
                k++;
                s = 1;
            }
            f = 0;
        }

        fwrite(&stud, sizeof(struct Student), 1, f1);
        s = 0;
    }
}
