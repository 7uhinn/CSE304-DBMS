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

struct IndFile
{
  int rollno;
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
  struct Student data;
  struct IndFile ind;

  f1 = fopen("data.txt", "w");
  f2 = fopen("index.txt", "w");

  int n = 1000000;

  printf("Generating file...");

  for (int i = 0; i < n; i++)
  {
    generation(data.name, 5);
    data.rollno = (rand() % (1000000));
    ind.rollno = data.rollno;
    ind.offset = i;
    data.age = (rand() % (50));
    strcpy(data.branch, "CSE");
    fwrite(&data, sizeof(struct Student), 1, f1);
    fwrite(&ind, sizeof(struct IndFile), 1, f2);
  }
}
