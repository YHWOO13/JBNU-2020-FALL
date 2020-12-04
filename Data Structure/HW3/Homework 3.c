/* Author: Yoonhyuck WOO / JBNU_Industrial Information system Engineering
 Date; Nov. 9. 2020 - Nov.11. 2020
 Title: Student data in doubly Linked List*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student* listPointer;
/*문자열을 받을 때 char* name은 메모리 할당을 또 따로 해주어야 함= 번거로움
밑에와 같이 배열로 받으면 그럴 필요가 없음.*/
typedef struct student
{
	listPointer* lnext;
	int no;
	char name[100];
	int year;
	char department[100];
	int age;
	listPointer* rnext;
}student;

listPointer head = NULL;
listPointer tail = NULL;

int add_stduent_info(int no, char* name, int year, char* department, int age)
{
	listPointer stu = (student*)malloc(sizeof(student));
	listPointer trace = head;

	stu->no = no;
	strcpy_s(stu->name, sizeof(stu->name), name);
	stu->year = year;
	strcpy_s(stu->department, sizeof(stu->department), department);
	stu->age = age;
	stu->lnext = stu;
	stu->rnext = NULL;
	
	if (head)
	{
		while (trace->rnext != tail)
		{
			trace = trace->rnext;
		}
		trace->rnext = stu;
		stu->lnext = trace;
		stu->rnext = tail;
		tail->lnext = stu;
	}
	else
	{
		head = stu;
		head->rnext = tail;
		tail->lnext = head;
	}
	tail->rnext = NULL;
	head->lnext = NULL;
}

void forward_sequence()
{
	int i = 1;
	listPointer visual = head;
	for (; visual != tail; visual = visual->rnext) {
		printf("%d.  Std.No: %d, Std.Name: %s, Year: %d, Department: %s, Age: %d \n", i, visual->no, visual->name, visual->year, visual->department, visual->age);
		i++;
	}
}

void backward_sequence() {
	int i = 1;
	listPointer visual = tail->lnext;
	for (; visual != head->lnext; visual = visual->lnext) {
		printf("%d.  Std.No: %d, Std.Name: %s, Year: %d, Department: %s, Age: %d \n", i, visual->no, visual->name, visual->year, visual->department, visual->age);
		i++;
	}
}
void delete_all()
{
	listPointer temp = NULL;
	while (head->rnext)
		delete();
//tail 메모리 해제
	temp = head;
	head = head->rnext;
	free(tail);
	temp = NULL;
	tail = NULL;
}
int delete()
{
	listPointer temp = NULL;
	temp = head;
	head = head->rnext;
	free(temp);
	temp = NULL;
}

void find_student(char *name)
{
	listPointer trace = head;
	while (strcmp(trace->name,name))
	{
		trace=trace->rnext;
	}
	printf("Std.No: %d, Std.Name: %s, Year: %d, Department: %s, Age: %d \n", trace->no, trace->name, trace->year, trace->department, trace->age);
	printf("\n");
}

int main()
{
	int i = 0, j = 0, k=0, Std_no = 0, year = 0, age = 0, answer = 0;
	char Std_name[100], department[100];
//tail 메모리 할당
	tail = (student*)malloc(sizeof(student));
	printf("Choose 1st option: \n");
	while (1)
	{
		printf("1. Add information of student.\n");
		printf("2. Quit and Visualize or find information.\n");
		printf("3. End this Program.\n");
		printf("Answer: ");
		scanf_s("%d", &answer);
		if (answer == 1)
		{
			printf("             =============Adding information of student.=============\n");
			printf("%d. Std.No: ", i + 1);
			scanf_s("%d", &Std_no);
			printf("%d. Std.Name: ", i + 1);
			scanf_s("%s", &Std_name, sizeof(Std_name));
			printf("%d. year: ", i + 1);
			scanf_s("%d", &year);
			printf("%d. department: ", i + 1);
			scanf_s("%s", &department, sizeof(department));
			printf("%d. age: ", i + 1);
			scanf_s("%d", &age);
			printf("\n");
			i = i + 1;

/* 전역변수인 tail을 main에서 메모리 할당 후 add_student 함수에서 
head와 연결 시킨 후 , 전역변수인점을 이용하며 출력 함수(2개)에 사용*/
			add_stduent_info(Std_no, &Std_name, year, &department, age);
		}
		else if (answer == 2)
		{
			while (1)
			{
				printf("\n Choose 2nd option. \n");
				printf("1. Print all data in forward sequence visiting. \n");
				printf("2. Print all data in backward sequence visiting. \n");
				printf("3. Do you want to know student's information?\n");
				printf("4. Back to 1st option\n");
				printf("Answer: ");
				scanf_s("%d", &k);

				if (k == 1)
				{
					printf("             ==============You add %d student's information.==============\n", i);
					forward_sequence();
				}
				else if (k == 2)
				{
					printf("             ==============You add %d student's information.==============\n", i);
					backward_sequence();
				}

				else if (k == 3)
				{
					printf("Write the student's name: ");
					scanf_s("%s", &Std_name, sizeof(Std_name));
					find_student(&Std_name);
					break;
				}
				else if (k == 4)
				{
					break;
				}
				else { printf("             =============Out of order.=============\n"); }
			}
		}
		else if (answer == 3)
		{
			delete_all();
			break;
		}
		else { printf("             =============Out of order.=============\n"); }
	}

	return 0;
}