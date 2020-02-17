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
    struct Index ind[30];
    int roll[30];
    int temp;
    int f = 0, k = 0, s = 0, m = 0, z = 0;

    f1 = fopen("data.txt", "w");
    f2 = fopen("index.txt", "w");

    int n = 30;

    printf("Generating file...\n");
    for (int i = 0; i < n; i++)
    {
        generation(stud.name, 5);
        stud.age = (rand() % (50));
        strcpy(stud.branch, "CSE");

        while (s == 0)
        {
            temp = (rand() % (1000));
            for (int j = 0; j < sizeof(roll); j++)
            {
                if (temp == roll[j])
                {
                    f = 1;
                    break;
                }
            }
            if (f == 0)
            {
                roll[k] = temp;
                stud.rollno = temp;
                k++;
                s = 1;
            }
            f = 0;
        }
        printf("Rollno = %d    Name = %s    Age = %d    Branch = %s\n", stud.rollno, stud.name, stud.age, stud.branch);
        fwrite(&stud, sizeof(struct Student), 1, f1);
        s = 0;

        if (i == 0)
        {
            ind[0].rollno = stud.rollno;
            ind[0].lc = -1;
            ind[0].rc = -1;
            ind[0].offset = i;
        }

        else
        {
            z = 0;
            m = 0;
            while (m == 0)
            {
                if (stud.rollno < ind[z].rollno)
                {
                    if (ind[z].lc == -1)
                    {
                        ind[z].lc = i;
                        m = 1;
                    }
                    else
                    {
                        z = ind[z].lc;
                    }
                }
                else
                {
                    if (stud.rollno > ind[z].rollno)
                    {
                        if (ind[z].rc == -1)
                        {
                            ind[z].rc = i;
                            m = 1;
                        }
                        else
                        {
                            z = ind[z].rc;
                        }
                    }
                }
            }

            ind[i].rollno = stud.rollno;
            ind[i].lc = -1;
            ind[i].rc = -1;
            ind[i].offset = i;
        }
    }
    printf(".....................................................................\n");
    for (int i = 0; i < n; i++)
    {
        printf("Rollno = %d    LC = %d    RC = %d    Offset = %d\n", ind[i].rollno, ind[i].lc, ind[i].rc, ind[i].offset);
        fwrite(&ind[i], sizeof(struct Index), 1, f2);
    }
}
