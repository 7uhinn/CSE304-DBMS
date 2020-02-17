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

struct Index
{
    int rollno;
    int lc;
    int rc;
    int offset;
};

int main()
{

    while (1)
    {
        FILE *f2, *f1;
        struct Student stud;
        struct Index idx;
        int m = 0, o = 0, ex = 0, z = 0;
        int key = 0, flag = 1;
        printf("Press 1 to perform search\nPress 2 to perform addition\nPress 3 to perform deletion\nPress 0 to exit\n");
        printf("Option chosen: ");
        scanf("%d", &ex);

        if (ex == 1)
        {
            f2 = fopen("index.txt", "r");
            f1 = fopen("data.txt", "r");

            printf("\nEnter the roll number you are looking for: ");
            scanf("%d", &key);

            clock_t begin = clock();
            int count = 0;
            while (flag == 1 && o != -1)
            {
                fseek(f2, o * sizeof(struct Index), SEEK_SET);
                fread(&idx, sizeof(struct Index), 1, f2);
                if (idx.rollno < key)
                {
                    o = idx.rc;
                }
                else if (idx.rollno > key)
                {
                    o = idx.lc;
                }
                else
                {
                    fseek(f1, idx.offset * sizeof(struct Student), SEEK_SET);
                    fread(&stud, sizeof(struct Student), 1, f1);
                    printf("Rollno = %d    Name = %s    Age = %d    Branch = %s\n", stud.rollno, stud.name, stud.age, stud.branch);
                    flag = 0;
                }
            }

            if (flag)
            {
                printf("\nNot present \n");
            }

            clock_t end = clock();

            double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

            printf("Time elpased is %f seconds\n\n", time_spent);
            printf(".....................................................................\n");

            fclose(f1);
            fclose(f2);
        }

        if (ex == 2)
        {
            f2 = fopen("index.txt", "r");

            fseek(f2, 0, SEEK_END);
            int f = (int)(ftell(f2) / sizeof(struct Index));
            printf("%d", f);

            struct Index ind[f];

            fseek(f2, 0, SEEK_SET);

            for (int i = 0; i < f; i++)
            {
                fread(&ind[i], sizeof(struct Index), 1, f2);
            }
            fclose(f2);

            f1 = fopen("data.txt", "a");
            f2 = fopen("index.txt", "w");

            char n[20], b[4];

            printf("\nEnter the Name (max 20 characters): ");
            scanf("%s", &n);
            strcpy(stud.name, n);
            printf("\nEnter the Roll Number: ");
            scanf("%d", &stud.rollno);
            printf("\nEnter the Age: ");
            scanf("%d", &stud.age);
            printf("\nEnter the Branch (max 4 characters): ");
            scanf("%s", &b);
            strcpy(stud.branch, b);

            printf("\nRollno = %d    Name = %s    Age = %d    Branch = %s\n", stud.rollno, stud.name, stud.age, stud.branch);
            fwrite(&stud, sizeof(struct Student), 1, f1);

            z = 0;
            m = 0;
            while (m == 0)
            {
                if (stud.rollno < ind[z].rollno)
                {
                    if (ind[z].lc == -1)
                    {
                        ind[z].lc = f;
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
                            ind[z].rc = f;
                            m = 1;
                        }
                        else
                        {
                            z = ind[z].rc;
                        }
                    }
                }
            }

            ind[f].rollno = stud.rollno;
            ind[f].lc = -1;
            ind[f].rc = -1;
            ind[f].offset = f;

            //Uncomment to show all records in index file
            /*printf(".....................................................................\n");
            for (int i = 0; i < f + 1; i++)
            {
                printf("Rollno = %d    LC = %d    RC = %d    Offset = %d\n", ind[i].rollno, ind[i].lc, ind[i].rc, ind[i].offset);
                fwrite(&ind[i], sizeof(struct Index), 1, f2);
            }*/

            printf("Record added successfully.");
            printf(".....................................................................\n");

            fclose(f1);
            fclose(f2);
        }

        if (ex == 0)
        {
            exit(0);
        }
    }
}