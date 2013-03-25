#include <stdio.h>
#include <conio.h>
#include <locale>
#include<stdlib.h>

char *gets_s(char *s, size_t buf_size)
{
    char *result;
    result = fgets(s,buf_size,stdin);
    result[strlen(s)-1] = '\0';
    return result;
}
struct student
 {
char name[10];
char surname[10];
char patronymic[10];
char facul[10];
char specialty[10];
char group[6]; 
int marks[50]; 
int total_marks; 
float pts;
};


int enter_student(struct student *student_list, int max_number_of_students,int number_of_students);
void show_list(struct student *student_list,int number_of_students);
int menu_select(void);
int sort();
int sort_f(const void *a, const void *b);
int sort_name(const void *, const void*);
void clear_screen();
int on_faculty(struct student student, char *facul);
int is_premialist(struct student student);
void print_student(struct student student,int number_of_students);
float calculate ( struct student student);
int main() 
{
	
	const int max_number_of_students = 150;
    struct student students_list[max_number_of_students];
    int number_of_students=25;
    char choice;
    while(1) 
	{
		choice = menu_select();
        switch (choice) 
		{
		case 1:
			number_of_students=enter_student(students_list, number_of_students, max_number_of_students);break;
        case 2: 
			qsort(students_list, number_of_students, sizeof(struct student), sort_f);
            show_list(students_list, number_of_students);break; 
	   case 3:
            exit(0);break; 

	   }

   }
}

float calculate ( struct student student)
{
	int sum = 0,i = 0;
	float pts = 0;
	for( i = 0; i<=5;i++)
	{
		while(student.marks[i]!=0)
			sum+=student.marks[i];
	}
	    student.pts = sum/(i+1);
	return student.pts;
}
void clear_screen()
{
#ifdef __WIN32
    system("cls");
#else
    system("clear");
#endif
} 


int menu_select(void) 
{
	const int buf_size = 80;
    char s[buf_size];
    int c;
 
     printf("1. Enter a list of students\n");
     printf("2. Show the list of students who need to give the prize\n");
     printf("3. Exit\n");
	 do {
		 printf("\nEnter the number of the desired item\n");
		 gets_s(s,buf_size);
         c = atoi(s);}
	 while (c < 0 || c > 3); 
	     clear_screen();
     return c; 

}

int enter_student(struct student *student_list, int max_number_of_students,int number_of_students)
{
	int i, j;
    const int input_buffer_size = 80;
	const int name_size=10;
	const int surname_size=10;
	const int facul_size=10;
	const int patronymic_size=10;
	const int specialty_size=10;
	const int group_size=6;
    char input_buffer[input_buffer_size];
    char *strtoul_end_ptr;
	int max_marks=5;
	const int buf_size=80;	
	char s[buf_size];
	number_of_students=0;
	max_number_of_students=0;


    if(number_of_students > max_number_of_students){
		printf("Max number of students (%d) reached", max_number_of_students);
        return number_of_students;
    }
    clear_screen();
    i =number_of_students;
 
     printf("Enter the name of the student: "); 
	 gets_s(student_list[i].name, name_size);

     printf("Enter the surname of the student: "); 
	 gets_s(student_list[i].surname, surname_size);

	 printf("Enter the patronymic: ");
     gets_s(student_list[i].patronymic,patronymic_size);

	 printf("Enter the name of the faculty student:");
	 gets_s(student_list[i].facul,facul_size);
 
     printf("Enter the name of the specialty student: ");
     gets_s(student_list[i].specialty,specialty_size);
 
     printf("Enter a group of student: ");
     gets_s(student_list[i].group,group_size);
	 
	 for(j = 0; j < max_marks; j++)
	 {
		 printf("Enter mark number %d:\n",j);
         gets_s(input_buffer, input_buffer_size);
         student_list[i].marks[j] = strtoul(s, &strtoul_end_ptr, 10);
			if(*strtoul_end_ptr)
			{
				 printf("Wrong mark, try again.\n");
					j--;
             continue;
			}
		calculate(student_list[i]);
	 }
	 return (number_of_students)+1; 
	  	
}


int on_faculty(struct student student, char *facul)
{
	return strcmp(student.facul, facul); 

}


int is_premialist(struct student *student_list) 
{
    int i;
		for(i = 0; i< student_list[i].total_marks; i++) 
			{
				if(student_list[i].pts < 4)
					return 0;
			}

		return 1;
} 



void show_list(struct student *student_list, int number_of_students)
{
    int i, j,number_of_faculties;
	char* facul;
	int	student=0;
    for(i = 0; i < number_of_faculties; i++)
	{
		facul = student_list[i].facul;   
        printf("Faculty %s:\n",facul);
        printf("Premialists:\n");
			for(j = 0; j < number_of_students; j++) 
			{
				if(on_faculty(student_list[j],facul) && is_premialist(student_list[j]))
					print_student(student_list[j],number_of_students);
			}
	}

	
        printf("Everyone else:\n");
			for(j = 0; j < number_of_students; j++) 
			{
				if(on_faculty(student_list[j], facul) && !is_premialist(student_list[j]))
					print_student(student_list[j],number_of_students);
            }
}
	


void print_student( struct student* student_list,int number_of_students)
{
	int i;
		for(i = 0; i< number_of_students; i++) 
	
	printf("%s\n",student_list[i].surname);
}

int sort_f(const void *a, const void *b)
 {
    const struct student *k = (const struct student *) a;
   const struct student *m = (const struct student *) b;
     return (strcmp(k->facul, m->facul));
 } 
