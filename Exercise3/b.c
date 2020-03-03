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
        int ex = 0;

        printf("Press 1 to perform search\nPress 2 to perform addition\nPress 3 to perform deletion\nPress 0 to exit\n");
        printf("Option chosen: ");
        scanf("%d", &ex);

        if (ex == 1)
        {
            f2 = fopen("index.txt", "r");
            f1 = fopen("data.txt", "r");

            int key = 0;

            printf("\nEnter the roll number you are looking for: ");
            scanf("%d", &key);

            int flag = 1, o = 0;
            struct Index idx;
            struct Student stud;

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

        else if (ex == 2)
        {
            f2 = fopen("index.txt", "r");

            fseek(f2, 0, SEEK_END);
            int f = (int)(ftell(f2) / sizeof(struct Index));

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

            struct Student stud;

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

            int z = 0;
            int m = 0;
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

            printf(".....................................................................\n");
            for (int i = 0; i < f + 1; i++)
            {
                printf("Rollno = %d    LC = %d    RC = %d    Offset = %d\n", ind[i].rollno, ind[i].lc, ind[i].rc, ind[i].offset);
                fwrite(&ind[i], sizeof(struct Index), 1, f2);
            }

            printf("Record added successfully.\n");
            printf(".....................................................................\n");

            fclose(f1);
            fclose(f2);
        }

        else if (ex == 3)
        {
            f2 = fopen("index.txt", "r");

            int t = 0, z = 0, m = 0;

            int k = 0, flag = 1, o = 0;

            printf("\nEnter the roll number you want to delete: ");
            scanf("%d", &k);

            struct Index id;

            printf("9");

            while (flag == 1 && o != -1)
            {
                printf("0");
                fseek(f2, o * sizeof(struct Index), SEEK_SET);
                fread(&id, sizeof(struct Index), 1, f2);
                if (id.rollno < k)
                {
                    printf("1");
                    o = id.rc;
                }
                else if (id.rollno > k)
                {
                    printf("2");
                    o = id.lc;
                    printf("%d", o);
                }
                else
                {
                    t = id.offset;
                    printf("%d", t);
                    flag = 0;
                }
            }

            if (flag)
            {
                printf("\nNot present \n");
            }

            if (flag == 0)
            {
                fseek(f2, 0, SEEK_END);
                int f = (int)(ftell(f2) / sizeof(struct Index));

                fclose(f2);

                f1 = fopen("data.txt", "r");

                struct Student stud[f];

                for (int i = 0; i < f; i++)
                {
                    fread(&stud[i], sizeof(struct Student), 1, f1);
                }
                fclose(f1);

                f1 = fopen("data.txt", "w");
                f2 = fopen("index.txt", "w");

                struct Index ind[f];

                for (int i = 0; i < t; i++)
                {
                    fwrite(&stud[i], sizeof(struct Student), 1, f1);

                    if (i == 0)
                    {
                        ind[0].rollno = stud[0].rollno;
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
                            if (stud[i].rollno < ind[z].rollno)
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
                                if (stud[i].rollno > ind[z].rollno)
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

                        ind[i].rollno = stud[i].rollno;
                        ind[i].lc = -1;
                        ind[i].rc = -1;
                        ind[i].offset = i;
                    }
                }

                for (int i = t + 1; i < f; i++)
                {
                    fwrite(&stud[i], sizeof(struct Student), 1, f1);

                    z = 0;
                    m = 0;
                    while (m == 0)
                    {
                        if (stud[i].rollno < ind[z].rollno)
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
                            if (stud[i].rollno > ind[z].rollno)
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

                    ind[i - 1].rollno = stud[i].rollno;
                    ind[i - 1].lc = -1;
                    ind[i - 1].rc = -1;
                    ind[i - 1].offset = i - 1;
                }

                printf("\n.....................................................................\n");
                for (int i = 0; i < f - 1; i++)
                {
                    printf("Rollno = %d    LC = %d    RC = %d    Offset = %d\n", ind[i].rollno, ind[i].lc, ind[i].rc, ind[i].offset);
                    fwrite(&ind[i], sizeof(struct Index), 1, f2);
                }
            }

            fclose(f2);
            fclose(f1);
        }

        else if (ex == 0)
        {
            exit(0);
        }

        else
        {
            printf("Invalid Choice.\n\n");
        }
    }
}