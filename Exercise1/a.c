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

int generation(char *s,int len)
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
  FILE *f1,*f2;
  struct Student stud1,stud2;

  f1 = fopen("f1.txt", "w");
  f2 = fopen("f2.txt", "w");

  int n = 1000000;
  
  printf("Generating file...");
  for(int i=0; i<n; i++)
  {
    generation(stud1.name,5);
    generation(stud2.name,5);
    stud1.rollno = (rand() % (1000000));
    stud2.rollno = (rand() % (1000000));
    stud1.age = (rand() % (50));
    stud2.age = (rand() % (50));
    strcpy(stud1.branch,"CSE");
    strcpy(stud2.branch,"ECE");
    fwrite(&stud1, sizeof(struct Student), 1, f1);
    fwrite(&stud2, sizeof(struct Student), 1, f2);
  }
}
