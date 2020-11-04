#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
	char no[10];
	char name[20];
	int year;
	char department[30];
	int age;

	struct student * next;

}; 

//name, year,department, age

typedef struct student *listPointer;

listPointer first, second;


void insertLast(listPointer first, listPointer in) //Insert new node into Linked List at last
{
	listPointer temp;
	temp = first;
	while (temp->next) temp = temp->next;
	
	temp->next = in;

}

void insertFirst(listPointer first, listPointer in) //Insert new node into Linked List at first
{
	if (first->next) {
		in->next = first->next;
		first->next = in;
	}
	first->next = in;
}

/*
void insertLast(listPointer first, listPointer in) //Insert new node into Linked List(name is first), after x
{
	listPointer temp;
	temp = first;
	while (temp->next) temp = temp->next;

	temp->next = in;

}
*/

void deleteL(listPointer *first, listPointer trail, listPointer x) //Delete x, which is next to trail
{
	if (trail)
		trail->next = x->next;
	else
		*first = (*first)->next;

	free(x);

}

void printList(listPointer first)
{
	printf("\nAll data contained in the Linked List : \n");
	for (first = first->next; first; first = first->next)
		printf("학번: %s, 이름: %s, 학년: %d, 학과: %s, 나이: %d\n", first->no, first->name, first->year, first->department, first->age);
	printf("\n");
}


int main(void)
{
	

	char tempNo[30];
	char tempName[30];
	

	struct student * stu1 = malloc(sizeof(struct student));
	stu1->next = NULL;

	struct student * newStudent;

	while (1) {

		printf("\n학번: ");
		scanf("%s", tempNo);

		if (strcmp(tempNo, "quit") == NULL) break;
		else {

			newStudent = malloc(sizeof(struct student)); //Heap memory allocation	
			
			strcpy(newStudent->no, tempNo);
			printf("학생이름: ");
			scanf("%s", tempName);
			strcpy(newStudent->name, tempName);
			printf("학년: ");
			scanf("%d", &newStudent->year);
			strcpy(newStudent->department, "Industrial Engineering");
			newStudent->age = 30;
			newStudent->next = NULL;

			insertLast(stu1, newStudent);
		}
	}


	struct student * p;

	p = stu1->next;

	/*
	for (i = 0; i < 21; i++)
	{
		

		printf("학번: %s, 이름: %s, 학년: %d, 학과: %s, 나이: %d \n", stu[i].no, stu[i].name, stu[i].year, stu[i].department, stu[i].age);
		
		printf("\n");
	}
	

	for (i = 0; i < 20; i++)
	{

		stu[i].next = &stu[i + 1];
					
	}
	*/

	printf("Linking is finished\n\n");
	
	
	/*
	for (p = stu; p; p=p->next)
	{

		if (p != NULL) {
			printf("학번: %s, 이름: %s, 학년: %d, 학과: %s, 나이: %d\n", p->no, p->name, p->year, p->department, p->age);
			printf("\n");
		}
	}
	*/
	printList(stu1);


	return 0;

}