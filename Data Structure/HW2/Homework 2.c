/* Author: Yoonhyuck WOO / JBNU_Industrial Information system Engineering
 Date; Nov. 04. 2020 - Nov.06. 2020 
 Title: Student data in Linked List*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student* listPointer;
/*���ڿ��� ���� �� char* name�� �޸� �Ҵ��� �� ���� ���־�� ��= ���ŷο�
�ؿ��� ���� �迭�� ������ �׷� �ʿ䰡 ����.*/
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
/*���ڿ��� �ٸ� �Լ��� �Ѱ��ַ��� ���ڿ��� ù��° �ּҸ� �˷������
 �׷��� ������ �Լ��� �Ű������� ������ ������ ��*/
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

	if (head) 
{
		while (trace->next)
		{
			trace = trace->next;
		}
		trace->next = stu;
	}
	else 
	{
		head = stu;
	}
}

void visualize() {
	int i = 1;
	listPointer visual = head;
	for (; visual; visual = visual->next) {
		printf("%d.  Std.No: %d, Std.Name: %s, Year: %d, Department: %s, Age: %d \n",i, visual->no, visual->name, visual->year, visual->department, visual->age);
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
	temp = head;
	head = head->next;
	free(temp);
	temp = NULL;
}


int main()
{
	int i = 0, j = 0, Std_no = 0, year = 0, age = 0, answer = 0;
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
			printf("%d. Std.No: ", i+1);
			scanf_s("%d", &Std_no);
			printf("%d. Std.Name: ", i+1);
			scanf_s("%s", &Std_name, sizeof(Std_name));
			printf("%d. year: ", i+1);
			scanf_s("%d", &year);
			printf("%d. department: ", i+1);
			scanf_s("%s", &department, sizeof(department));
			printf("%d. age: ", i+1);
			scanf_s("%d", &age);
			printf("\n");
			i = i + 1;

			/*���� �Լ����� �Ű������� �����ͺ����� ��ٸ� main���� ������ ������ �ޱ� ����
			&�ٿ��������� ����ü�� ���鶧 �迭�� �����߱⋚���� �����̸��� ���൵ �ȴ�.*/
			add_stduent_info(Std_no, &Std_name, year, &department, age);
		}
		else if (answer == 2)
		{
			printf("             ==============You add %d student's information.==============\n", i);
			visualize();
			printf("             =============End this program.=============\n");
			delete_all();
			break;
		}
		else { printf("             =============Out of order.=============\n"); }
	}
	
	return 0;
}