#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *gets_s(char *s, size_t buf_size)
{
    char *result;
    result = fgets(s,buf_size,stdin);
    result[strlen(s)-1] = '\0';
    return result;
}
              

struct student {
    char name[256];
    char surname[100];
    char patronymic[100];
    char facul[100];
    char specialty[100];
    char group[60];
    int marks[50];
    int total_marks;
};

void enter_list(void), show_list(void);
int menu_select(void), find_free(void);
int sort();
int sort_f(const void *, const void *), sort_name(const void *,
                                                  const void *);

int main()
{
/* èíèöèàëèçàöèÿ ìàññèâà ñòðóêòóð */
    const int max_number_of_students = 150;
    struct student students_list[max_number_of_students];
    int number_of_students;
    char choice;
    while(1){

        choice = menu_select();
        switch (choice) {

        case 1:
            number_of_students = enter_student(students_list, number_of_students, max_number_of_students);
            break;

        case 2:
            qsort(student_list, number_of_students, sizeof(struct student), sort_f);
            show_list(student_list, number_of_students);
            break;

        case 3:
            exit(0);
            break;
        }
    }
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
        c = atoi(s);
    } while (c < 0 || c > 3);
    clear_screen();
    return c;
}


int enter_student(struct student *student_list, int current_number_of_students, int max_number_of_students)
{
    int i, j;
    const int input_buffer_size = 80;
    char input_buffer[input_buffer_size];
    char *strtoul_end_ptr;
    if(current_number_of_students >= max_number_of_students)
    {
        printf("Max number of students (%d) reached", max_number_of_students);
        return current_number_of_students;
    }
     
    clear_screen();
    i = current_number_of_students;

    printf("Enter the name of the student: ");
    gets_s(student_list[i].name, name_size);

    printf("Enter the surname of the student: ");
    gets_s(student_list[i].surname, surname_size);

    printf("Enter the patronymic: ");
    gets_s(student_list[i].patronymic);

    printf("Enter the name of the faculty student: ");
    gets_s(student_list[i].facul);

    printf("Enter the name of the specialty student: ");
    gets_s(student_list[i].specialty);


    printf("Enter a group of student: ");
    gets_s(student_list[i].group);

    for(j = 0; j < max_marks; j++){
        printf("Enter mark number %d:\n",j);
        gets_s(input_buffer, input_buffer_size);
        student_list[i].mark[j] = strtoul(s, &strtoul_end_ptr, 10);
        if(*strtoul_end_ptr){
            printf("Wrong mark, try again.\n");
            j--;
            continue;
        }
    }
    /* printf("vi hotite prodolshenie spolnenia inform o students?\n");

       printf("1 - yes\n2 - no");
       scanf_s("%d",&j);
       system("cls");
       if(j==2)
       break;



       } */
    return number_of_students+1;
}

int on_faculty(struct student student, char *faculty)
{
    return strcmp(student.facutlty, faculty);
}

int is_premialist(struct student student)
{
    int i;
    /* for(i = 0; student.marks[i] != -1; i++) */
    for(i = 0; i < student.total_marks; i++) {
        if(student.marks[i] < 4){
            return 0;
        }
    }
    return 1;
}

void show_list(struct student *student_list, number_of_students)
{
    int i, j;
    for(i = 0; i < number_of_faculties; i++){
        facutlty = faculties[i];
        printf("Faculty %s:\n", faculty);
        printf("Premialists:\n");
        for(j = 0; j < number_of_students; j++) {
            if(on_faculty(students[j], faculty) && is_premialist(students[j])){
                print_student(students[j]);
            }
        }
        printf("Everyone else:\n");
        for(j = 0; j < number_of_students; j++) {
            if(on_faculty(students[j], faculty) && !is_premialist(students[j])){
                print_student(students[j]);
            }
        }
    }
}

/*
www.cyberforum.ru/cpp-beginners/thread409634.html
www.cyberforum.ru/c-beginners/thread388245.html#post2194577
*/

int sort_f(const void *a, const void *b)
{
    const struct student *k = (const struct student *) a;
    const struct student *m = (const struct student *) b;
    return (strcmp(k->facul, m->facul));
}
