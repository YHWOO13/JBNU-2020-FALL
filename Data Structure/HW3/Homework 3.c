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
	listPointer trace1 = head;
	listPointer trace2 = tail;
	stu->no = no;
	strcpy_s(stu->name, sizeof(stu->name), name);
	stu->year = year;
	strcpy_s(stu->department, sizeof(stu->department), department);
	stu->age = age;
	stu->lnext = stu;
	stu->rnext = NULL;

	if (head)
	{
		while (trace1->rnext)
		{
			trace1 = trace1->rnext;
		}
		trace1->rnext = stu->lnext;
		stu->lnext = trace1->rnext;
	}
	else
	{
		head = stu;
	}
	/*
	if (tail)
	{
		while (tail->lnext)
		{
			trace2 = trace2->lnext;
		}
		trace2->lnext = stu->rnext;
		stu->rnext = trace2->lnext;
	}
	else
	{
		tail = stu;
	}*/
}

void forward_sequence() {
	int i = 1;
	listPointer visual = head;
	for (; visual; visual = visual->rnext) {
		printf("%d.  Std.No: %d, Std.Name: %s, Year: %d, Department: %s, Age: %d \n", i, visual->no, visual->name, visual->year, visual->department, visual->age);
		i++;
	}
}

void backward_sequence() {
	int i = 1;
	listPointer visual = tail;
	for (; visual; visual = visual->lnext) {
		printf("%d.  Std.No: %d, Std.Name: %s, Year: %d, Department: %s, Age: %d \n", i, visual->no, visual->name, visual->year, visual->department, visual->age);
		i++;
	}
}
void delete_all()
{
	while (head)
		delete();
}
int delete()
{
	listPointer temp = NULL;
	temp = head->lnext;
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
	listPointer trace = head;
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

			/*만약 함수에서 매개변수로 포인터변수를 썼다면 main에서 포인터 변수를 받기 위해
			&붙여야하지만 구조체를 만들때 배열로 선언했기문에 변수이름만 써줘도 된다.*/
			add_stduent_info(Std_no, &Std_name, year, &department, age);
		}
		else if (answer == 2)
		{
			printf("Choose another option \n");
			printf("1. Print all data in forward sequence visiting. \n");
			printf("2. Print all data in backward sequence visiting. \n");
			printf("3. Do you want to know student's information?\n");
			scanf_s("%d", &k);

			if (k == 1)
			{
				printf("             ==============You add %d student's information.==============\n", i);
				forward_sequence();
				printf("             =============End this program.=============\n");
				delete_all();
				break;
			}
			else if (k == 2)
			{
				printf("             ==============You add %d student's information.==============\n", i);
				backward_sequence();
				//printf("             =============End this program.=============\n");
				//delete_all();
				break;
			}

			else if (k == 3)
			{
				printf("Write the student's name: ");
				scanf_s("%s", &Std_name, sizeof(Std_name));
				find_student(&Std_name);
				break;
			}

			else { printf("             =============Out of order.=============\n"); }
		}
		else { printf("             =============Out of order.=============\n"); }
	}

	return 0;
}