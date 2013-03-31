#ifdef __cplusplus
extern "C" {
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define input_buf_size 80
#define SIZE( x ) (sizeof( x )/sizeof( *x ))


char *gets_s(char *s, size_t buf_size)
{
    char *result;
    result = fgets(s, buf_size, stdin);
    result[strlen(s) - 1] = '\0';
    return result;
}

typedef struct student {
    char name[100];
    char surname[100];
    char patronymic[100];
    char facul[100];
    char specialty[100];
    char group[50];
    int marks[50];
    int total_marks;
    float pts;
} student;

void clear_screen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
int faculty_count=0;
int menu_select(void)
{
    char s[input_buf_size];
    int c;

    printf("1. Enter a list of students\n");
    printf("2. display a list of standouts\n");
    printf("3. Exit\n");
    do {
        printf("\nEnter the number of the desired item\n");
        gets_s(s, input_buf_size);
        c = atoi(s);
    }
    while (c < 0 || c > 3);
    clear_screen();
    return c;

}

int faculty_exists(student * student_list, int number_of_students,char *faculty)
{
int i ;
    for (i = 0; i < number_of_students; i++){
        if (!strcmp(faculty, student_list[i].facul)){
            return 1;
		}
    return 0;
	}
}

int enter_student(struct student *student_list,int number_of_students,int max_number_of_students)
{
    int j;
    char input_buffer[input_buf_size];
    char *strtoul_end_ptr;
    int max_marks = 5;
    char s[input_buf_size];
    int name_size = SIZE (student_list[number_of_students].name);
    int surname_size = SIZE(student_list[number_of_students].surname);
    int patronymic_size = SIZE(student_list[number_of_students].patronymic);
    int facul_size = SIZE(student_list[number_of_students].facul);
    int specialty_size = SIZE(student_list[number_of_students].specialty);
    int group_size = SIZE(student_list[number_of_students].group);
     
    
    if (number_of_students > max_number_of_students) {
        printf("Max number of students (%d) reached",max_number_of_students);
        return number_of_students;
    }
    clear_screen();
    printf("Enter the name of the student: ");
    gets_s(student_list[number_of_students].name,name_size);

    printf("Enter the surname of the student: ");
    gets_s(student_list[number_of_students].surname, surname_size);

    printf("Enter the patronymic: ");
    gets_s(student_list[number_of_students].patronymic, patronymic_size);

    printf("Enter the name of the faculty:");

    gets_s(student_list[number_of_students].facul, facul_size);
    if(!faculty_exists(student_list, number_of_students, student_list[number_of_students].facul))
     {faculty_count++;}

    printf("Enter the name of the specialty student: ");
    gets_s(student_list[number_of_students].specialty, specialty_size);

    printf("Enter a group of student: ");
    gets_s(student_list[number_of_students].group, group_size);

    student_list[number_of_students].total_marks = max_marks;
    
    for (j = 0; j < max_marks; j++) {
        printf("Enter mark number %d:\n", j+1);
        gets_s(input_buffer, input_buf_size);
        student_list[number_of_students].marks[j] = strtoul(input_buffer, &strtoul_end_ptr, 10);
}
    number_of_students++;
    return number_of_students;

}


int is_premialist(student current_student)
{
    int i;
    for (i = 0; i <5; i++) {
        if (current_student.marks[i] < 4){
            return 0;
		}
    }
  return 1;
}



void show_list(struct student *student_list, int number_of_students)
{
    int i, j;
	for(i = 0; i < number_of_students; i++){
		if(i==0){
			printf("Faculty %s:\n", student_list[i].facul);
            printf("Premialists:\n");
		}
		else{
			if((strcmp(student_list[i].facul,student_list[i-1].facul)!=0)){
				printf("Faculty %s:\n", student_list[i].facul);
                printf("Premialists:\n");
			}
		}
        for(j = 0; j < number_of_students; j++) {
			if((strcmp(student_list[i].facul,student_list[i-1].facul)==0))
				break;
            if((strcmp(student_list[j].facul,student_list[i].facul)==0)){
				if (is_premialist(student_list[j])){
					printf("%s\n", student_list[j].surname);
				}
			}
		}
	}
}

int sort_f(const void *a, const void *b)
{
    const struct student *k = (const struct student *) a;
    const struct student *m = (const struct student *) b;
    return (strcmp(k->facul, m->facul));
}


int main()
{
int number_of_students=0;
    struct student students_list[150];
    char choice;
    while (1) {
        choice = menu_select();
        switch (choice) {
        case 1:
            number_of_students = enter_student(students_list,number_of_students,(sizeof(students_list)/sizeof(students_list[0])));
            break;
        case 2:
            qsort(students_list, number_of_students, sizeof(struct student), sort_f);
            show_list(students_list, number_of_students);
            break;
        case 3:
            exit(0);
            break;

        }
    }
}
#ifdef __cplusplus
}
#endif