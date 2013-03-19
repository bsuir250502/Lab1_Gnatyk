#include <stdio.h>
#include <conio.h>
#include <locale>
#include <stdlib.h>
#define MAX 100


struct student {
    char name[256];
    char surname[100];
    char patronymic[100];
    char facul[100];
    char specialty[100];
    char group[60];
    unsigned long int mark_1;
    unsigned long int mark_2;
    unsigned long int mark_3;
} student_list[MAX];

void init_list(void), enter_list(void), show_list(void);
int menu_select(void), find_free(void);
int sort();
int sort_f(const void *, const void *), sort_name(const void *,
                                                  const void *);

int main()
{
/* èíèöèàëèçàöèÿ ìàññèâà ñòðóêòóð */
//struct student liststd[MAX];
    char choice;
    init_list();
    for (;;) {

        choice = menu_select();
        switch (choice) {

        case 1:
            enter_list();
            break;

        case 2:
            show_list();
            break;

        case 3:
            exit(0);
            break;

        }
    }


}

/* Èíèöèàëèçàöèÿ ñïèñêà. */
void init_list(void)
{
    register int t;

    for (t = 0; t < MAX; ++t)
        student_list[t].name[0] = '\0';
}


/* Ïîëó÷åíèÿ çíà÷åíèÿ, âûáðàííîãî â ìåíþ. */
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
    } while (c < 0 || c > 3);
    system("cls");
    return c;
}


/* Ââîä àäðåñà â ñïèñîê. */
void enter_list(void)
{
    system("cls");
    int slot, i, j;
    char s[80];

    slot = find_free();
    //for(slot=i;slot<30; slot++)
    // {

    printf("Enter the name of the student: ");
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
    student_list[slot].mark_1 = strtoul(s, '\0', 10);

    printf("Enter the second assessment of students: ");
    gets_s(s);
    student_list[slot].mark_2 = strtoul(s, '\0', 10);

    printf("Enter the third assessment of student: ");
    gets_s(s);
    student_list[slot].mark_3 = strtoul(s, '\0', 10);
    system("cls");
    /* printf("vi hotite prodolshenie spolnenia inform o students?\n");

       printf("1 - yes\n2 - no");
       scanf_s("%d",&j);
       system("cls");
       if(j==2)
       break;



       } */
    return;
}

/* Ïîèñê ñâîáîäíîé ñòðóêòóðû. */
int find_free(void)
{
    register int t;

    for (t = 0; student_list[t].name[0] && t < MAX; ++t);

    if (t == MAX)
        return -1;              /* ñâîáîäíûõ ñòðóêòóð íåò */
    return t;
}



void show_list(void)
{
    struct student *p;
    p = &student_list[0];

    int slot = find_free();
    if (slot == -1)
        slot == MAX;
    int fac[3] = { 0 };
    fac[0] = 1;
    int k = 0;


    qsort(p, slot, sizeof(struct student), sort_f);

    for (int i = 0; i < slot; i++) {
        if (i == slot - 1) {
            if (strcmp(student_list[i].facul, student_list[i - 1].facul) !=
                0) {
                k++;
                fac[k]++;

            }
            if (strcmp(student_list[i].facul, student_list[i - 1].facul) ==
                0)
                fac[k]++;
        }

        if (i != slot - 1) {
            if (strcmp(student_list[i].facul, student_list[i + 1].facul) !=
                0) {

                fac[k]++;
                k++;
            } else {
                fac[k]++;
            }
        }
    }





    int fac_i[3];
    fac_i[0] = 0;
    fac_i[1] = fac[1];
    fac_i[2] = fac[1] + fac[2];
    int fac_flag[3];
    fac_flag[0] = 0;
    fac_flag[1] = 0;
    fac_flag[2] = 0;
    k = (-1);
    int j = 0;
    for (int i = 0; i < slot; i++) {
        if (i == fac_i[j]) {
            j++;
            k++;
        }
        if ((student_list[i].mark_1 > 3) && (student_list[i].mark_2 > 3)
            && (student_list[i].mark_3 > 3)) {
            if (fac_flag[k] == 0) {
                printf("%s", student_list[i].facul);
                printf("\n");
                printf("%s", student_list[i].surname);
                fac_flag[k] = 1;
            } else {
                printf("%s", student_list[i].surname);
                printf("\n");
            }

        }


    }
    getch();
    system("cls");
}

/*
 k=0;
  int koll_people=0,kol_people_fac=fac[0];
 
  while(koll_people<slot)
  {
  if((student_list[koll_people].mark_1>3)&&(student_list[koll_people].mark_2>3 )&&(student_list[koll_people].mark_3>3 ))
  {
	  if(koll_people==kol_people_fac) 
	  {         
	
	      printf("%s",student_list[koll_people].surname);
	      printf("\n");
		  k++;
		  koll_people++;
		  kol_people_fac=kol_people_fac+fac[k];
		
	 }
	  if((koll_people!=kol_people_fac))
	  {
	  printf("%s",student_list[koll_people].surname);
	  printf("\n");
	  koll_people++;
	  }
  }
  else
  {
	  if(koll_people==kol_people_fac) 
	  {
		 
	  }

  }
  }


 

 int koll_people,kol_people_fac=fac[0];

 for(koll_people=0;koll_people<slot;koll_people++)
 if((student_list[koll_people].mark_1>3)&&(student_list[koll_people].mark_2>3 )&&(student_list[koll_people].mark_3>3 ))
 {
	 printf("%s",student_list[koll_people].surname);
	 printf("\n");
	if(koll_people==kol_people_fac) 
	 {
		 printf("%s",student_list[koll_people].facul);
		 k++;
		 kol_people_fac=kol_people_fac+fac[k];
	 }
     
 }
 else if(koll_people==kol_people_fac) 
	 {
		 printf("%s",student_list[koll_people].facul);
		 k++;
		 kol_people_fac=kol_people_fac+fac[k];
	 }
 
 */





/*  int t,j;
  
  for (k=0;k<3;k++)
  {
	  if (fac[k]==0) break;
      printf("%s\n",student_list[fac[k]-1].facul);
	  if (k==0)  j=0;
	  else j=fac[k-1];
      for(t=j; t<fac[k]; ++t)
      {
		  if(( student_list[t].mark_1>3)&&(student_list[t].mark_2>3 )&&(student_list[t].mark_3>3 ))
          {
          printf("%s",student_list[t].surname);
		  printf("\n");
          }
      }
  }
              *///www.cyberforum.ru/cpp-beginners/thread409634.html
//www.cyberforum.ru/c-beginners/thread388245.html#post2194577

int sort_f(const void *a, const void *b)
{
    const student *k = (const student *) a;
    const student *m = (const student *) b;
    return (strcmp(k->facul, m->facul));
}
