/* Author: Yoonhyuck WOO / JBNU_Industrial Information system Engineering
 Date; Nov. 11 2020
 Title: Student data in Linked List*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student* listPointer;
typedef struct student
{
	int no;
	char name[100];
	int year;
	char department[100];
	int age;
	listPointer* next;
}student;

listPointer head = NULL;

int add_stduent_info(int no, char* name, int year, char* department, int age)
{
	listPointer stu = (student*)malloc(sizeof(student));
	listPointer trace = head;
	stu->no = no;
	strcpy_s(stu->name, sizeof(stu->name), name);
	stu->year = year;
	strcpy_s(stu->department, sizeof(stu->department), department);
	stu->age = age;
	stu->next = NULL;
	if (head) {
		while (trace->next) {
			trace = trace->next;
		}
		trace->next = stu;
	}
	else {
		head = stu;
	}
}

void visualize() {
	listPointer visual = head;
	for (; visual; visual = visual->next) {
		printf("Std.No: %d, Std.Name: %s, Year: %d, Department: %s, Age: %d \n", visual->no, visual->name, visual->year, visual->department, visual->age);
	}
}

int main()
{
	int i = 1, j = 0, Std_no = 0, year = 0, age = 0, answer = 0;
	char Std_name[100], department[100];
	listPointer trace = head;
	//listPointer stu = (student*)malloc(sizeof(student));
	printf("Choose the option: \n");
	while (1)
	{
		printf("1. Add information of student.\n");
		printf("2. Quit.\n");
		scanf_s("%d", &answer);
		printf("Answer: %d\n", answer);
		if (answer == 1)
		{
			printf("             =============Adding information of student.=============\n");
			printf("%d. Std.No: ", i);
			scanf_s("%d", &Std_no);
			printf("%d. Std.Name: ", i);
			scanf_s("%s", &Std_name, sizeof(Std_name));
			printf("%d. year: ", i);
			scanf_s("%d", &year);
			printf("%d. department: ", i);
			scanf_s("%s", department, sizeof(department));
			printf("%d. age: ", i);
			scanf_s("%d", &age);
			printf("\n");
			i = i + 1;
			add_stduent_info(Std_no, Std_name, year, department, age);
		}
		else if (answer == 2)
		{
			visualize();
			printf("             =============End this program.=============\n");
			break;
		}
		else { printf("             =============Out of order.=============\n"); }
	}
	return 0;
}