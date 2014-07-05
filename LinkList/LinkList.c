#include<stdio.h>
#include<stdlib.h>

struct ListNode {
		int data;
		struct ListNode *next;
};

typedef struct ListNode ListNode;


	ListNode *create(){
		
		ListNode *head;
		head=NULL;
		return head;
		}
	
	

void InsertLinkList(ListNode **head,int data,int position){
	int k=1;
	ListNode *p,*q,*newNode;

	newNode=(ListNode *)malloc(sizeof(ListNode));
	
	if(!newNode){
	printf("MemmoryError");
	return;
	}

	newNode->data=data;
	p=*head;

	//inserting at begining

	if(position == 1){
	   newNode->next=p;
	   *head=newNode;
	 }
	else {
		//travese list until the position where we want to insert
		while((p!=NULL) && (k < position)){
			k++; q=p;
			p=p->next;
		}
		q->next=newNode; 
		newNode->next=p;
	     }
}

/*Traversal Of List*/

	void Traverse(ListNode *head){
		ListNode *current=head;

		if(head == NULL){
		printf("\t!~~~~~~~~List Empty~~~~~~~~~!\n");
		return;
		}
		
		printf("\tList :");
		while(current!= NULL){
		printf(" %d",current->data);
		current=current->next;
		}
	  printf("\n");

	}

/*Deletion Of Link List Node */

	void DeleteNode(ListNode **head){
		int k=1,pos;
		ListNode *p,*q;
		if(*head == NULL){
		printf("\t!~~~~~~~~~~~~~~~List Empty~~~~~~~~~~~~~!\n");
		return;
		}
		                        
                        printf("Which position :");
                        scanf("%d",&pos);

		p=*head;
			if(pos == 1) /*First Node Deletion*/
			{
				*head=(*head)->next;
				free(p);
				return;
			}
		
			else{
				while((p!= NULL) && ( k< pos)){
					k++; q=p;
					p=p->next;
					}
				if(p == NULL)
				{  		/*End Node*/
				printf("Position Not Exit");
				return;
				}
				else
				{
					q->next=p->next;/*Middle Node*/
					free(p);
				}
			  }
	return;
	}

//Deletion of Entire Link List
	void DeleteLinkList(ListNode **head){
		ListNode *auxiliaryNode,*iterator;
		iterator=*head;
		while(iterator)
		{
			auxiliaryNode=iterator->next;
			free(iterator);
			iterator=auxiliaryNode;
		}	
			*head=NULL;
	return;
	}
//Insert node in sorted List

	ListNode *insertInSortedList(ListNode *head){
				ListNode *current=head,*temp,*newNode;
			
				newNode=(ListNode *)malloc(sizeof(ListNode));
				printf("Enter Node value: "); scanf("%d",&(newNode->data));
				if(!head) return newNode;		

				while(current != NULL && current->data < newNode->data){
					temp=current;
					current=current->next;
					}

					newNode->next=current;
					temp->next=newNode;
					return head;

			}

//Reverse Link List
		ListNode *reverseList(ListNode *head){
				ListNode *temp=NULL,*nextNode=NULL;

				while(head){
					nextNode->next=head->next;
					head->next=temp;
					temp=head;
					head=nextNode;
				}
			return temp;
		}




//Main Function
   int main(){
	int position,data;
	int ch;
	ListNode *head;
	head=create(); //Initialisation List


    while(1){
	
		printf("\n");
                printf("<1> Insert,  ");
                printf("<2> Traverse, ");
                printf("<3> Delete, ");
		printf("<4> Delete Total List  ");
                printf("<5> Exit\n");
                printf("<6> Insert node at sorted position,  ");
		printf("<7> Reverse List\n");

                scanf("%d",&ch);

		if(ch == 1){
                        
                        printf("Enter Value And Position \n");
                        scanf("%d %d",&data,&position);
                        
                        InsertLinkList(&head,data,position);
			}

		else if(ch == 2){
                        Traverse(head);
			}
		
		else if(ch == 3){
                        DeleteNode(&head);
			}

		else if(ch == 4){
			DeleteLinkList(&head);
			}

		else if(ch == 5){
			DeleteLinkList(&head);
			exit(0);
			}

		else if(ch == 6){
			head=insertInSortedList(head);
			}

		else if(ch == 7){
			head=reverseList(head);
			}

		else
		printf("Invalid Choice \n");
                
	    }
   return 0;
	}

