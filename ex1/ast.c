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

int main()
{
  FILE *fp;
  struct Student stud;

  fp = fopen("f3s.txt", "r");
  double avgst;
  int keys[15] = {15, 234, 319, 455, 456, 3321, 4587, 5678, 65789, 123678, 456346, 567432, 875643, 900000, 987654};

  int key = 0, flag = 1;

  int count = 0;
  double tt;

  for (int i = 0; i < 15; i++)
  {
    flag = 1;
    clock_t begin = clock();
    while (fread(&stud, sizeof(struct Student), 1, fp))
    {
      if (stud.rollno == keys[i])
      {
        printf("Rollno = %d    Name = %s    Age = %d    Branch = %s\n", stud.rollno, stud.name, stud.age, stud.branch);
        flag = 0;
        break;
      }
    }

    if (flag)
    {
      printf("Not present");
    }

    clock_t end = clock();

    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    tt = tt + time_spent;
  }

  avgst = tt/(15);
  printf("Average Search Time: %f", avgst);
}
