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
            int hash = 0;

            int key = 0;

            printf("\nEnter the roll number you are looking for: ");
            scanf("%d", &key);

            hash = key % 10;

            int flag = 1, o = 0;
            struct Index idx;
            struct Student stud;

            clock_t begin = clock();
            int count = 0;

            fseek(f2, hash * sizeof(struct Index), SEEK_SET);
            fread(&idx, sizeof(struct Index), 1, f2);

            if (idx.rollno == -1 || idx.rollno != key)
            {
                printf("Not Found\n");
            }
            else
            {
                fseek(f1, idx.offset * sizeof(struct Student), SEEK_SET);
                fread(&stud, sizeof(struct Student), 1, f1);
                printf("Rollno = %d    Name = %s    Age = %d    Branch = %s\n", stud.rollno, stud.name, stud.age, stud.branch);
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
            FILE *f7, *f8, *f9, *f0;
            f7 = fopen("index.txt", "r");
            f8 = fopen("data.txt", "r");

            int k;

            struct Student stud[10];
            struct Index id[10];

            for (int i = 0; i < 10; i++)
            {
                fread(&id[i], sizeof(struct Index), 1, f7);
                fread(&stud[i], sizeof(struct Student), 1, f8);
            }

            fclose(f7);
            fclose(f8);

            struct Student s;
            char n[20], b[4];

            printf("\nEnter the Name (max 20 characters): ");
            scanf("%s", &n);
            strcpy(s.name, n);
            printf("\nEnter the Roll Number: ");
            scanf("%d", &s.rollno);
            printf("\nEnter the Age: ");
            scanf("%d", &s.age);
            printf("\nEnter the Branch (max 4 characters): ");
            scanf("%s", &b);
            strcpy(s.branch, b);

            int hash = 0;

            hash = s.rollno % 10;

            if (id[hash].rollno != -1)
            {
                printf("Oops! Slot already filled, first clear the slot.\n");

                f9 = fopen("index.txt", "w");
                f0 = fopen("data.txt", "w");

                for (int i = 0; i < 10; i++)
                {
                    fwrite(&id[i], sizeof(struct Index), 1, f9);
                    fwrite(&stud[i], sizeof(struct Student), 1, f0);
                }

                fclose(f9);
                fclose(f0);
            }
            else
            {
                id[hash].rollno = s.rollno;
                stud[id[hash].offset].rollno = s.rollno;
                strcpy(stud[id[hash].offset].name,s.name);
                stud[id[hash].offset].age = s.age;
                strcpy(stud[id[hash].offset].branch,s.branch);

                f9 = fopen("index.txt", "w");
                f0 = fopen("data.txt", "w");

                for (int i = 0; i < 10; i++)
                {
                    fwrite(&id[i], sizeof(struct Index), 1, f9);
                    fwrite(&stud[i], sizeof(struct Student), 1, f0);
                }

                printf("Record added successfully.\n");
                printf(".....................................................................\n");

                fclose(f9);
                fclose(f0);
            }
        }

        else if (ex == 3)
        {
            FILE *f3, *f4, *f5, *f6;
            f3 = fopen("index.txt", "r");
            f4 = fopen("data.txt", "r");

            int k;

            struct Student stud[10];
            struct Index id[10];

            for (int i = 0; i < 10; i++)
            {
                fread(&id[i], sizeof(struct Index), 1, f3);
                fread(&stud[i], sizeof(struct Student), 1, f4);
            }

            fclose(f3);
            fclose(f4);

            printf("\nEnter the roll number you want to delete: ");
            scanf("%d", &k);

            int hash = 0;

            hash = k % 10;

            if (id[hash].rollno == -1 || id[hash].rollno != k)
            {
                printf("Not Found\n");

                f5 = fopen("index.txt", "w");
                f6 = fopen("data.txt", "w");

                for (int i = 0; i < 10; i++)
                {
                    fwrite(&id[i], sizeof(struct Index), 1, f5);
                    fwrite(&stud[i], sizeof(struct Student), 1, f6);
                }

                fclose(f5);
                fclose(f6);
            }
            else
            {
                id[hash].rollno = -1;
                stud[id[hash].offset].rollno = -1;

                f5 = fopen("index.txt", "w");
                f6 = fopen("data.txt", "w");

                for (int i = 0; i < 10; i++)
                {
                    fwrite(&id[i], sizeof(struct Index), 1, f5);
                    fwrite(&stud[i], sizeof(struct Student), 1, f6);
                }

                printf("Record deleted successfully.\n");
                printf(".....................................................................\n");

                fclose(f5);
                fclose(f6);
            }
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