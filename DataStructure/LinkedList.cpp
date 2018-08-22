#include<stdio.h>
#include<stdlib.h>
struct NodeP{
	int cof;
	int pwr;
	struct NodeP *next;
};
struct NodeP* polyOne=NULL;
struct NodeP* polyTwo=NULL;	
struct NodeP* polyAdd=NULL;

struct Node{
	int data;
	struct Node *next;	
};
struct Node* head=NULL;
struct Node* head2=NULL;
void createEmptyLL(struct Node** head);
void checkIfEmpty(struct Node** head);
void LLnElements(struct Node** head,int n);
void insert(struct Node** head, int in);
void printLL(struct Node** head);
void insertAtBeginning(struct Node** head,int in);
void insertAfterSelectedNode(struct Node** head,int a,int in);
void insertBeforeSelectedNode(struct Node** head,int a,int in);
void averageLL(struct Node** head);
void findFreq(struct Node** head);
int freq(struct Node** head,int in);
void appendTwoLL(struct Node* head,struct Node* head2);
void deleteNodeatEnd(struct Node** head);
void deleteNodeatBegin(struct Node** head);
void deleteNodeatSelected(struct Node** head,int in);
void deleteLL(struct Node** head);
void polyLL();
void polyAddition(struct NodeP* polyOne,struct NodeP* polyTwo,struct NodeP* polyAdd);

int main(){
	int choice,a,b;
	while(1){
	        printf("Hello User\n");
        	printf("Press (1) to create an empty list\n");
        	printf("Press (2) to check if the linked list is empty\n");
       		printf("Press (3) to linked list with 10 nodes and display them\n");
        	printf("Press (4) to insert a node at the beginning of a linked list\n");
        	printf("Press (5) to insert a node after a specific node\n");
        	printf("Press (6) to insert a node before a specific node\n");
        	printf("Press (7) to find the average of linked list elements\n");
        	printf("Press (8) to find the frequency of each element in the linked list\n");
        	printf("Press (9) to append the above linked list with another linked list\n");
        	printf("Press (10) to delete a node from the end of the linked list\n");
        	printf("Press (11) to delete a node from beginning of the the linked list\n");
		printf("Press (12) to delete a specific node from a linked list\n");
		printf("Press (13) to delete the entire linked list\n");
		printf("Press (14) to print the linked list\n");
		printf("Press (15) to represent polynomials using linked list and add two polynomials\n");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				createEmptyLL(&head);
				break;
			case 2:
				checkIfEmpty(&head);
				break;
			case 3:
				printf("Enter the number of elements you want to put in the linked list\n");
				scanf("%d", &a);
				LLnElements(&head,a);
			
				break;
			case 4:
				printf("Enter the element to inserted\n");
				scanf("%d", &a);
				insertAtBeginning(&head,a);	
				break;	
			case 5:
				printf("Enter the element to be inserted\n");
				scanf("%d", &a);
				printf("Enter the node after which you want to insert a node\n");
				scanf("%d", &b);
				insertAfterSelectedNode(&head,b,a);
				break;
			case 6:
				printf("Enter the element to be inserted\n");
                                scanf("%d", &a);
                                printf("Enter the node before which you want to insert a node\n");
                                scanf("%d", &b);
                                insertBeforeSelectedNode(&head,b,a);
                                break;
			case 7:
				averageLL(&head);
				break;
			case 8:
				findFreq(&head);
				break;
			case 9:
				printf("Enter the number of elements you want to put in the second linked list\n");
                                scanf("%d", &a);
                                LLnElements(&head2,a);
                                printLL(&head2);	
				printf("Second Linked List created\n");
				appendTwoLL(head,head2);
				break;
			case 10:
				deleteNodeatEnd(&head);
				break;
			case 11:
				deleteNodeatBegin(&head);
				break;
			case 12:
				printf("Enter the node you want to delete\n");
				scanf("%d", &a);
				deleteNodeatSelected(&head,a);	
				break;
			case 13:
				deleteLL(&head);
				break;
			case 14:
				printLL(&head);
				break;
			case 15:
				polyLL();
		}

	}
}

void createEmptyLL(struct Node** head){
	*head=NULL;
	printf("Empty Linked List created succesfully\n");
}

void checkIfEmpty(struct Node** head){
	if(*head==NULL){
		printf("Linked list is empty\n");
		return;
	}
	printf("Linked list is not empty\n");
}

void LLnElements(struct Node** head,int n){
	int in;
	for(int i=0;i<n;i++){
		printf("Enter the next element\n");
		scanf("%d", &in);
		insert(head,in);	
	}
}
void insert(struct Node** head,int in){
	struct Node* temp= (struct Node*) malloc(sizeof(struct Node));
	struct Node *ptr;
	temp->next=NULL;
	temp->data=in;
	if(*head==NULL){
		*head=temp;
	}
	else{
		ptr=*head;
		while(ptr->next!=NULL){
			ptr=ptr->next;
		}
		ptr->next=temp;
	}
}

void printLL(struct Node** head){
	struct Node *ptr = *head;
	if(*head==NULL){
		printf("Linked list is Empty\n");
		return;
	}
	printf("The linked list is:\n");
	while(ptr!=NULL){
		printf("%d,", ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
}

void insertAtBeginning(struct Node** head,int in){
	struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
	ptr->data=in;
	ptr->next= (*head);
	(*head)= ptr;
}



void insertAfterSelectedNode(struct Node** head,int a,int in){
	
	if(*head==NULL){
		printf("The linked LIst is empty\n");
	}
	else{
		 
		struct 	Node *ptr1,*ptr2;
		struct Node* temp =(struct Node*) malloc(sizeof(struct Node));
		ptr1=*head;
		temp->data=in;
		while(ptr1!=NULL){
			if(ptr1->data==a){
				ptr2=ptr1->next;
				ptr1->next=temp;
				temp->next=ptr2;	
				return;
			}
			ptr1=ptr1->next;
		}	
	}
}

void insertBeforeSelectedNode(struct Node** head,int a,int in){

        if(*head==NULL){
                printf("The linked List is empty\n");
        }
        else{

                struct  Node *ptr1,*ptr2;
                struct Node* temp =(struct Node*) malloc(sizeof(struct Node));
                ptr1=*head;
                temp->data=in;
                while(ptr1!=NULL){
			if(ptr1->data==a){
				printf("You cannot insert an element before head of linked list\n");
				return;
			}
                        if((ptr1->next)->data==a){
                                ptr2=ptr1->next;
                                ptr1->next=temp;
                                temp->next=ptr2;
                                return;
                        }
                        ptr1=ptr1->next;
                }
        }
}
void averageLL(struct Node** head){
	float sum=0.0,counter=0;
	if(*head==NULL){
		printf("The linked list is empty\n");	
		return;
	}
	else{
		struct Node *ptr=*head;
		while(ptr!=NULL){
			sum+=ptr->data;
			counter++;
			ptr=ptr->next;
		}
		printf("The average of linked List is : %f \n", sum/counter);
	}
}
void findFreq(struct Node** head){
	if(*head==NULL){
		printf("The linked list is empty");	
	}
	else{
		struct Node *ptr =*head;
		while(ptr!=NULL){
			printf("The frequency of %d in linked is %d \n", ptr->data,freq(head,ptr->data));
			ptr=ptr->next;
		}
	}
}	

int freq(struct Node** head,int in){
	struct Node* ptr = *head;
	int count=0;
	while(ptr!=NULL){
		if(ptr->data==in){
			count++;
		}
		ptr=ptr->next;
	}
	return count;
}

void appendTwoLL(struct Node* head,struct Node* head2){
	struct Node *ptr;
	ptr=head;
	if(head!=NULL&&head2!=NULL){
		while(ptr->next!=NULL){
			ptr=ptr->next;
		}
		ptr->next=head2;
	}
	else{
                printf("either of the two linked lists are empty\n");
        }
}

void deleteNodeatEnd(struct Node** head){
        struct Node *ptr1,*ptr2;
        if((*head)->next==(Node*)NULL){
                ptr1=*head;
                *head =NULL;
                free(ptr1);
        }
        else{
                ptr2=*head;
                ptr1=(*head)->next;
                while(ptr1->next!=NULL){
                        ptr2=ptr1;
                        ptr1=ptr1->next;
                }
                ptr2->next=NULL;
                free(ptr1);
        }
}


void deleteNodeatBegin(struct Node** head){
	struct Node *ptr1,*ptr2;
	if(*head==NULL){
		printf("The linked list cannot be empty\n");
	}
	else{
		ptr1=*head;
		ptr2=(*head)->next;
		ptr1=NULL;
		free(ptr1);
		*head=ptr2;
	}
}

void deleteNodeatSelected(struct Node** head,int in){
	struct Node *ptr1,*ptr2,*ptr3;
	ptr1=*head;
	if(*head==NULL){
		printf("The linked list is empty\n");
	}
	else{
		while(ptr1->next!=NULL){
			if((ptr1->next)->data==in){
				ptr2=ptr1->next;
				ptr3=ptr2->next;
				ptr1->next=ptr3;
				free(ptr2);
			}
			ptr1=ptr1->next;
		}
	}		
}

void deleteLL(struct Node** head){
	struct Node *ptr1,*ptr2;
	ptr1=*head;
	while(ptr1!=NULL){
		ptr2=ptr1->next;
		free(ptr1);
		ptr1=ptr2;
	}
	*head=NULL;
}

void polyLL(){
	polyAddtion(polyOne,polyTwo,polyAdd);
}

void polyAddition(struct NodeP* polyOne,struct NodeP* polyTwo,struct NodeP* polyAdd){
	while(polyOne->next!=NULL&&polyTwo->next!=NULL){
		if(polyOne->pwr>polyTwo->pwr){
			polyAdd->pwr=polyOne->pwr;
			polyAdd->cof=polyOne->cof;
			polyOne=polyOne->next;
		}
		else if(polyOne->pwr<polyTwo->pwr){
			polyAdd->pwr=polyTwo->pwr;
                        polyAdd->cof=polyTwo->cof;
                        polyTwo=polyTwo->next;
		}
		else{
			polyAdd->pwr=polyOne->pwr;
                        polyAdd->cof=polyOne->cof+polyTwo->cof;
                        polyOne=polyOne->next;
			polyTwo=polyTwo->next;
		}
		polyAdd->next=(struct NodeP*) malloc(sizeof(struct NodeP*));
		polyAdd=polyAdd->next;
		polyAdd->next=NULL;
	}
	while(polyOne->next!=NULL||polyTwo->next!=NULL){
		if(polyOne->next!=NULL){
			polyAdd->pwr=polyOne->pwr;
                        polyAdd->cof=polyOne->cof;
                        polyOne=polyOne->next;
		}
		if(polyTwo->next!=NULL){
			polyAdd->pwr=polyTwo->pwr;
                        polyAdd->cof=polyTwo->cof;
                        polyTwo=polyTwo->next;
		}
		polyAdd->next=(struct NodeP*) malloc(sizeof(struct NodeP*));
                polyAdd=polyAdd->next;
                polyAdd->next=NULL;
	}
}	
