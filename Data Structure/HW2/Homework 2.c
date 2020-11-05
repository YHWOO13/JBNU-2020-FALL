/* Author: Yoonhyuck WOO / JBNU_Industrial Information system Engineering
 Date; Nov. 11 2020
 Title: Student data in Linked List*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student* listPointer;
/*문자열을 받을 때 char* name은 메모리 할당을 또 따로 해주어야 함= 번거로움
밑에와 같이 배열로 받으면 그럴 필요가 없음.*/
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
/*문자열을 다른 함수에 넘겨주려면 문자열의 첫번째 주소를 알려줘야함
 그렇기 떄문에 함수의 매개변수로 포인터 변수를 씀*/
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

			/*만약 함수에서 매개변수로 포인터변수를 썼다면 main에서 포인터 변수를 받기 위해
			&붙여야하지만 구조체를 만들때 배열로 선언했기떄문에 변수이름만 써줘도 된다.*/
			add_stduent_info(Std_no, Std_name, year, department, age);
		}
		else if (answer == 2)
		{
			printf("             ==============You add %d student's information.==============\n", i-1);
			visualize();
			printf("             =============End this program.=============\n");
			break;
		}
		else { printf("             =============Out of order.=============\n"); }
	}
	free(head);
	return 0;
}