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

  fp = fopen("f2.txt", "r");

  int key = 0, flag = 1;
  printf("Enter the roll number you are looking for: ");
  scanf("%d", &key);

  clock_t begin = clock();
  int count = 0;
  while (fread(&stud,sizeof(struct Student),1,fp))
  {
    if (stud.rollno == key)
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

  printf("Time elpased is %f seconds", time_spent);
}
