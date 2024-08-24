#include<stdio.h>
#include<stdlib.h>

typedef struct list{
int data;
struct list* link;
} Node;

Node *ptr, *ptr1, *temp, *head = NULL;

void CreateNode() {
ptr = (Node*)(malloc(sizeof(Node)));
if (ptr == NULL) {
printf("Memory allocation failed");
exit(1);
}
printf("\nEnter data: ");
scanf("%d", &ptr->data);
ptr->link = NULL;
}

void Traverse() {
temp = head;
while(temp != NULL) {
printf("%d -> ", temp->data);
temp = temp->link;
}
printf("NULL\n");
}

void addAtBeginning() {
CreateNode();
if (head == NULL) {
head = ptr;
} else {
ptr->link = head;
head = ptr;
}
}

void DeletefromBeginning() {
if (head == NULL) {
printf("\nList Empty\n");
return;
}

temp = head;
head = head->link;
free(temp);
}

void DeletefromEnd() {
if (head == NULL) {
printf("List Empty\n");
return;
} else if (head->link == NULL) {
free(head);
head = NULL;
} else {
temp = head;
while(temp->link != NULL) {
ptr1 = temp;
temp = temp->link;
}
free(temp);
ptr1->link = NULL;
}
}

void AddAtEnd(){
temp=head;CreateNode();
if (head==NULL){
head=ptr;
}
else if (head->link==NULL){

head->link=ptr;
}
else{
while (temp->link!=NULL){
temp=temp->link;
}
temp->link=ptr;
}
}

int Size(){
temp=head;
int c=0;
while(temp != NULL) {
c++;
temp = temp->link;
}
return c;
}

void AddAtAnyPos() {
    CreateNode();
    int pos, s, p = 1;
    printf("Enter position: ");
    scanf("%d", &pos);
    s = Size();
   
    if (head == NULL && pos == 1) {
        AddAtEnd();
    } else if (head == NULL && pos != 1) {
        printf("Error: Invalid position\n");
    } else if (pos > s + 1 || pos <= 0) {
        printf("Error: Invalid position\n");
    } else if (pos == 1) {
        ptr->link = head;
        head = ptr;
    } else {
        temp = head;
        while (p < pos - 1) {
            temp = temp->link;
            p++;
        }
        ptr->link = temp->link;
        temp->link = ptr;
    }
}

void DeleteFromAnypos(){
	int pos,p=0;
	int s=Size();
	printf("\nEnter position");
	scanf("%d",&pos);
	if (head==NULL){
		printf("Error");
	} else if (pos>s){
		printf("Error");
	} else if (pos==s){
		DeletefromEnd();
	} else{
		temp=head;
		while (p<pos-2){
			temp=temp->link;
			p++;
		}
		ptr1=temp->link;
		temp->link=ptr->link;
		free(ptr1);
	}
}

int main() {
int d;
do {
printf("\n 1. Add at Beginning");
printf("\n 2. Delete at Beginning");
printf("\n 3. Traverse");
printf("\n 4. Delete from End");
printf("\n 5. Add at end");
printf("\n 6. Size Of List");
printf("\n 7. Add At Any Position");
printf("\n 8.Delete from any position");

printf("\n -1. Exit");
printf("\n\nEnter choice: ");
scanf("%d", &d);

switch(d) {
case 1: addAtBeginning();
Traverse();
break;
case 2: DeletefromBeginning();
Traverse();
break;
case 3: Traverse();
break;
case 4: DeletefromEnd();
Traverse();
break;
case 5: AddAtEnd();
Traverse();
break;
case 6: printf("%d",Size());
break;
case 7: AddAtAnyPos();
Traverse();
break;
case 8: DeleteFromAnypos();
Traverse();
break;
case -1: exit(0);
default: printf("Wrong choice");
}
} while (d != -1);
return 0;
}

