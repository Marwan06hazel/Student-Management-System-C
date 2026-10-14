#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
	int id;
	char name[20];
	int age;
	float gpa;
} std;

struct node {
	struct Student data;
	struct node* next;
};

struct node* head = NULL;

void addStudent (const struct Student* const ptr) {
	struct node* link = malloc(sizeof(struct node));
	struct node* curr = NULL;
	link -> next = NULL;
	link -> data = *ptr;
	curr = head;

	if(head == NULL) {
		head = link;
		return;
	}

	while (curr != NULL) {
	    if (curr->data.id == ptr->id) {
	        printf("Duplicated Data\n");
	        free(link);
	        return;
	    }

	    if (curr->next == NULL) break;

	    curr = curr->next;
	}
	curr -> next = link;
}

void searchStudentbyID(int id){
	struct node* curr = NULL;
	curr = head;

	if (head == NULL){
		printf("No data yet\n");
	}

	while (curr != NULL){
		if (curr -> data.id == id){
			printf("Student ID: %d\n", curr -> data.id);
			printf("Student Name: %s\n", curr -> data.name);
			printf("Student age: %d\n", curr -> data.age);
			printf("Student ID: %.2f\n", curr -> data.gpa);
			printf("----------------------------------------------------\n");
			return;
		}
		else curr = curr -> next;
	}

	printf("Student is NOT found\n");
}

void updateStudent(int id){
	struct node* curr = NULL;
	curr = head;

	if (head == NULL){
		printf("NO data yet\n");
		return;
	}

	while(curr != NULL){
		if ((curr -> data.id) == id){
			printf("Student name = ");
			scanf("%s", curr -> data.name);

			printf("Student age = ");
			scanf("%d", &(curr -> data.age));

			printf("Student gpa = ");
			scanf("%f", &(curr -> data.gpa));
			return;
		}
		else curr = curr -> next;
	}
}

void calculateAverageGPA(void) {
	struct node* curr = NULL;
	curr = head;
	float GPASum = 0;
	int studentSum = 0;

	if (head == NULL){
		printf("GPA average = 0.0\n");
	}

	while (curr != NULL){
		GPASum += curr -> data.gpa;
		studentSum++;
		curr = curr -> next;
	}
	printf("GPA average = %.2f\n", (float)(GPASum / studentSum));
}

void highestGPA(void) {
    struct node* curr = NULL;
    struct node* ptr = NULL;
    curr = head;
    float placeholder = 0;

    if(head == NULL){
        printf("Highest GPA is 0.0\n");
    }

    while(curr != NULL){
        if((curr -> data.gpa) > placeholder){
            placeholder = curr -> data.gpa;
            ptr = curr;
        }
        curr = curr -> next;
    }
    searchStudentbyID(ptr -> data.id);
}

void deleteStudent(int id){
	struct node* curr = NULL;
	struct node* prev = NULL;

	prev = head;
	curr = head;

	if (head == NULL) {
		printf("No list to delete\n");
		return;
	}

	if (head -> data.id == id){
		head = curr -> next;
		free(curr);
		return;
	}

	curr = head -> next;

	while (curr != NULL){
		if (curr -> data.id = id){
			prev -> next = curr -> next;
			free(curr);
			return;
		}
		curr = curr -> next;
		prev = prev -> next;
	}
}

void displayInfo(void){
	struct node* curr = head;

	if(head == NULL){
		printf("No data yet\n");
	}

	while(curr != NULL){
		printf("Student ID: %d\n", curr -> data.id);
		printf("Student Name: %s\n", curr -> data.name);
		printf("Student Age: %d\n", curr -> data.age);
		printf("Student GPA: %.2f\n", curr -> data.gpa);
		printf("----------------------------------------------------\n");
		curr = curr -> next;
	}
}

int main(void){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int choice;
	int id;
	std s;

	do {
		printf("\n========== Student Management System ==========\n");
		printf("1. Add a Student\n");
		printf("2. Display All Students\n");
		printf("3. Search for a Student by ID\n");
		printf("4. Update Student Information\n");
		printf("5. Delete a Student\n");
		printf("6. Calculate Average GPA\n");
		printf("7. Find Student with Highest GPA\n");
		printf("8. Exit\n");
		printf("==============================================\n");

		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		printf("\n");

		switch(choice){
			case 1:
				printf("Student ID: ");
				scanf("%d", &s.id);

				printf("\nStudent Name: ");
				scanf("%s", s.name);

				printf("\nStudent Age: ");
				scanf("%d", &s.age);

				printf("\nStudent GPA: ");
				scanf("%f", &s.gpa);
				printf("\n");

				addStudent(&s);
				break;

			case 2:
				displayInfo();
				break;

			case 3:
				printf("\nEnter Student ID: ");
				scanf("%d", &id);
				searchStudentbyID(id);
				break;

			case 4:
				printf("\nEnter Student ID: ");
				scanf("%d", &id);
				updateStudent(id);
				break;

			case 5:
				printf("\nEnter Student ID: ");
				scanf("%d", &id);
				printf("\n");
				deleteStudent(id);
				break;

			case 6:
				calculateAverageGPA();
				break;

			case 7:
				highestGPA();
				break;

			case 8:
				printf("Program end");
				break;

			default:
				printf("Choose a valid choice: \n");
				scanf("%d", &choice);
		}

	} while(choice != 8);

	return 0;
}
