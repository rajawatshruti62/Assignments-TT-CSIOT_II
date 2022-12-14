
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
//insert in between
void insertinbetween(int item,node **head,int after){
	node *ptr;
	ptr=(node*)malloc(sizeof(node));
	ptr->data=item;
	ptr->address=NULL;
	node *s;
	s=*head;
	while(s->data!=after){
		s=s->address;
	}
	ptr->address=s->address;
	s->address=NULL;
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

//finding kth element from end of the linked list
int kthelement(node **head,int k){
	k=k-1;
	node *s,*t;
	s=*head;
	t=*head;
	while(k>0){
		t=t->address;
		k--;
	}
	while(t->address!=NULL){
		s=s->address;
		t=t->address;
	}
	return s->data;
}
//finding middle element of a linked list
int middle(node **head){
	node *s,*t;
	s=*head;
	t=*head;
	while(t!=NULL && t->address!=NULL && (t->address)->address!=NULL){
		s=s->address;
		t=(t->address)->address;
	}
	return s->data;
}
int main(){
	int item,choice;
	node *head;
	head=NULL;
	while(1){
		printf("\n_______LINKED LIST________\n");
		printf("\n1.Insert at beg");
		printf("\n2.Insert at end");
		printf("\n3.Insert at specific position (after)");
		printf("\n4.Delete at beg");
		printf("\n5.Delete at end");
		printf("\n6.Display all elements in order");
		printf("\n7.Finding kth element");
		printf("\n8.finding middle element");
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
				printf("Enter item:");
				scanf("%d",&item);
				int after;
				scanf("%d",&after);
				insertinbetween(item,&head,after);
				break;
			case 4:
				deleteatbeg(&head);
				break;
			case 5:
				deleteatend(&head);
				break;
			case 6:
				display(head);
				break;
			case 7:
				int k;
				scanf("%d",&k);
				printf("%d",kthelement(&head,k));
			case 8:
				printf("%d",middle(&head));
			default:
				exit(1);
		}
		
	}
	
}
