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
int sort_function(const void *a,const void *b);

int main()

{
/* eieoeaeecaoey ianneaa no?oeoo? */
char choice;
init_list();
for(;;)
{

    choice = menu_select();
    switch(choice)
     {

      case 1: enter_list();break;
		  
      case 2:show_list();break;
		  
      case 3: exit(0);break;
       
      }
  }


}

/* Eieoeaeecaoey nienea. */
void init_list(void)
{
  register int t;

  for(t=0; t<MAX; ++t) student_list[t].name[0] = '\0';
}


/* Iieo?aiey cia?aiey, aua?aiiiai a iai?. */
int menu_select(void)
{
  char s[80];
  int c;
 
  printf("1. Enter a list of students\n");
  printf("2. Show the list of students who need to give the prize\n");
  printf("3. Exit\n");


 do {
    printf("\nEnter the number of the desired item\n");
    gets_s(s);
    c = atoi(s);
  } while(c<0 || c>3);
 system("cls");
  return c;
}


/* Aaia aa?ana a nienie. */
void enter_list(void)
{
   system("cls");
  int slot,i,j;
  char s[80];
 
  for(i=0;i<30;i++)
  {
	   slot = find_free();
  if(slot==-1) {
    printf("\nlist is full");
	return;}
  printf("Enter the namô of the student: ");
  gets_s(student_list[slot].name);
 
  printf("Enter the surname of the student: ");
  gets_s(student_list[slot].surname);

  printf("Enter the patronymic: ");
  gets_s(student_list[slot].patronymic);

  printf("Enter the name of the faculty student: ");
  gets_s(student_list[slot].facul);

  printf("Enter the name of the specialty student: ");
  gets_s(student_list[slot].specialty);

   printf("Enter a group of student: ");
   gets_s(student_list[slot].group);

   printf("Enter the first assessment: ");
   gets_s(s);
   student_list[slot].mark_1=strtoul(s, '\0', 10);
   
   printf("Enter the second assessment of students: ");
   gets_s(s);
  student_list[slot].mark_2=strtoul(s, '\0', 10);
  
  printf("Enter the third assessment of student: ");
  gets_s(s);
  student_list[slot].mark_3=strtoul(s, '\0', 10);
  system("cls");
  printf("vi hotite prodolshenie spolnenia inform o students?\n");
  
	  printf("1 - yes\n2 - no\n");
	  scanf_s("%d",&j);
	 system("cls");
	  if(j==2)
		  break;

		  

  } return;
}

/* Iiene naiaiaiie no?oeoo?u. */
int find_free(void)
{
  register int t;

  for(t=0; student_list[t].name[0] && t<MAX; ++t) ;

  if(t==MAX) return -1; /* naiaiaiuo no?oeoo? iao */
  return t;
}


/* Auaia nienea ia ye?ai. */
void show_list(void)
{
int slot = find_free();
  if(slot==-1)
slot==MAX;
  
int t;
  for(t=0; t<10; ++t)
  {
      if(( student_list[t].mark_1>3)&&(student_list[t].mark_2>3 )&&(student_list[t].mark_3>3 ))
      {
          printf("%s\n",student_list[t].surname);
          printf("%s\n",student_list[t].facul);
}

  }
  
 getch();
 system("cls");
 
}

int sort_function(const char *a,const char *b)
{

   return(strcmp(a,b));
}
int sort()
{
	int a,i;
	
	int slot = find_free();
    if(slot==-1)
    slot==MAX;
	qsort(student_list[0].facul,slot-1,sizeof(int),sort_function);

}
