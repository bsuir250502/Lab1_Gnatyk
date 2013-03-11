#include <stdio.h>
#include <conio.h>
#include <locale>
#include<stdlib.h>
#define MAX 100


struct student
{
	char name[10];
	char surname[10];
	char patronymic[10];
	char facul[10];
	char specialty[10];
	char group[6];
unsigned long int mark_1;
unsigned long int mark_2;
unsigned long int mark_3;
} student_list[MAX];

void init_list(void), enter_list(void),show_list(void);
int menu_select(void), find_free(void);

int main()
{
	                                   /* инициализация массива структур */
		char choice;
		init_list(); 
		 for(;;) 
		 {

    choice = menu_select();
    switch(choice) 
	{

      case 1: enter_list();
        break;
      case 2: show_list();
        break;
      case 3: exit(0);
       
    }
  }


}

/* Инициализация списка. */
void init_list(void)
{
  register int t;

  for(t=0; t<MAX; ++t) student_list[t].name[0] = '\0';
}


/* Получения значения, выбранного в меню. */
int menu_select(void)
{
  char s[80];
  int c;

  printf("1. Enter a list of students\n");
  printf("2. Show the list of students who need to give the prize\n");
  printf("3. Exit\n");


 do {
    printf("\nEnter the number of the desired item: ");
    gets(s);
    c = atoi(s);
  } while(c<0 || c>3);

  return c;
}


/* Ввод адреса в список. */
void enter_list(void)
{
  int slot;
  char s[80];

  slot = find_free();
  if(slot==-1) {
    printf("\nlist is full");
    return;
  }

  printf("Enter the name of the student: ");
  gets(student_list[slot].name);

  printf("Enter the last name of the student: ");
  gets(student_list[slot].surname);

  printf("Enter the student's first name: ");
  gets(student_list[slot].patronymic);

  printf("Enter the name of the faculty student: ");
  gets(student_list[slot].facul);

  printf("Enter the name of the specialty student: ");
  gets(student_list[slot].specialty);

   printf("Enter a group of student: ");
  gets(student_list[slot].group);

     printf("Enter the first assessment: ");
   gets(s);
   student_list[slot].mark_1=strtoul(s, '\0', 10);
   
   printf("Enter the second assessment of students: ");
   gets(s);
  student_list[slot].mark_2=strtoul(s, '\0', 10);
  
  printf("Enter the third assessment of student: ");
   gets(s);
  student_list[slot].mark_3=strtoul(s, '\0', 10);

}

/* Поиск свободной структуры. */
int find_free(void)
{
  register int t;

  for(t=0; student_list[t].name[0] && t<MAX; ++t) ;

  if(t==MAX) return -1;                       /* свободных структур нет */
  return t;
}


/* Вывод списка на экран. */
void show_list(void)
{
	int slot = find_free();
  if(slot==-1) 
	  slot==MAX;
  
	 int t;
  for(t=0; t<=slot; ++t) 
  {
	  if(( student_list[t].mark_1>3)&&(student_list[t].mark_2>3 )&&(student_list[t].mark_3>3 ))
	  {
		  printf("%s\n",student_list[t].name);
		  printf("%s\n",student_list[t].facul);
	  }

  }
  
  
}

