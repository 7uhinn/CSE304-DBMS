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
    int f, l;
    int m;

    indf = fopen("indexs.txt", "r");
    data = fopen("data.txt", "r");

    while (1)
    {

        int key = 0, flag = 1, ex;
        printf("Press 1 to perform binary search\nPress 0 to exit\n");
        scanf("%d", &ex);

        if (ex)
        {

            printf("Enter the roll number you are looking for: ");
            scanf("%d", &key);

            clock_t begin = clock();

            f = 0;

            l = 1000000;

            while (f <= l)
            {
                m = (f + l) / 2;

                fseek(indf, m * sizeof(struct IndFile), SEEK_SET);
                fread(&ind, sizeof(struct IndFile), 1, indf);

                if (ind.rollno == key)
                {
                    fseek(data, ind.offset * sizeof(struct Student), SEEK_SET);
                    fread(&stud, sizeof(struct Student), 1, data);
                    printf("Rollno = %d    Name = %s    Age = %d    Branch = %s\n", stud.rollno, stud.name, stud.age, stud.branch);
                    flag = 0;
                    break;
                }

                else if (ind.rollno < key)
                {
                    f = m + 1;
                }

                else
                {
                    l = m - 1;
                }
            }

            if (flag)
            {
                printf("Not present \n");
            }

            clock_t end = clock();

            double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

            printf("Time elpased is %f seconds\n", time_spent);
        }

        if (ex == 0)
        {
            exit(0);
        }
    }
}