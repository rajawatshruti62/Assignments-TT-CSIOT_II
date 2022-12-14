
#include<stdio.h>
#include<stdlib.h>
typedef struct nodetype{
	int data;
	struct nodetype* address;
}node;
//insert an element at the beginning of the linked list
void insertatbeg(node **head,int item)
{
	node *ptr;
	ptr=(node*)malloc(sizeof(node));
	ptr->data=item;
	ptr->address=*head;
	*head=ptr;
}
//insert an element at the end of the linked list 
void insertatend(node** head,int item){
	node *ptr,*last;
	ptr=(node*)malloc(sizeof(node));
	ptr->data=item;
	ptr->address=NULL;
	if(head==NULL)
	*head=ptr;
	else{
		last=*head;
		while(last->address!=NULL)
		last=last->address;
		last->address=ptr;
		
	}
}
//to display all elements of linked list
void display(node *head){
	if(head==NULL){
		printf("LL is empty");
		return;
	}
	while(head!=NULL){
		printf("%d->",head->data);
		head=head->address;
	}
}
//to delete an item at the beg
void deleteatbeg(node **head){
	node *ptr;
	if(head==NULL){
		printf("\n LL is empty");
		return;
	}
	ptr=*head;
	*head=ptr->address;
	printf("\n Deleted Value=%d",ptr->data);
	free(ptr);
}
//to delete an element at the end
void deleteatend(node **head){
	node *ptr,*last;
	if(*head=NULL){
		printf("\n LL is empty");
		return;
	}
	if((*head)->address==NULL){
		ptr=*head;
		*head=ptr->address;
	}
	else{
		last=*head;
		while(last->address->address!=NULL){
			last=last->address;
		}
		ptr=last->address;
		last->address=NULL;}
		printf("\n Deleted Value=%d",ptr->data);
		free(ptr);
}
//search an item
node* search(node *head,int key){
	while(head!=NULL && head->data!=key){
		head=head->address;
	}
	return head;
}
//to display elements in reverse order
void displayinreverse(node *head){
	if(head->address!=NULL){
		displayinreverse(head->address);
	}
	printf("%d->",head->data);
}
int main(){
	int item,choice;
	node *head;
	head=NULL;
	while(1){
		printf("\n_______LINKED LIST________\n");
		printf("\n1.Insert at beg");
		printf("\n2.Insert at end");
		printf("\n3.Delete at beg");
		printf("\n4.Delete at end");
		printf("\n5.Display all elements in order");
		printf("\n6.Display in reverse order");
		printf("\n7.EXIT");
		printf("\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter item:");
				scanf("%d",&item);
				insertatbeg(&head,item);
				break;
			case 2:
				printf("Enter item:");
				scanf("%d",&item);
				insertatend(&head,item);
				break;
			case 3:
				deleteatbeg(&head);
				break;
			case 4:
				deleteatend(&head);
				break;
			case 5:
				display(head);
				break;
			case 6:
				displayinreverse(head);
				break;
			default:
				exit(1);
		}
		
	}
	
}