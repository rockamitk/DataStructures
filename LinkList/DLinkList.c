#include<stdio.h>
#include<stdlib.h>

struct DNode {
		int data;
		struct DNode *next;
		struct DNode *prev;
};

typedef struct DNode DNode;


	DNode *create(){
		
		DNode *head;
		head=NULL;
		return head;
		}
	
	

void insertNode(DNode **head,int data,int position){
	int k=2;
	DNode *temp,*newNode;
	
	newNode=(DNode *)malloc(sizeof(DNode));
	
	if(!newNode){
	printf("MemoryError");
	return;
	}

	newNode->data=data;

	//inserting at begining

	if(position == 1){
	   newNode->next=*head;
	   newNode->prev=NULL;
	  if(*head)
		(*head)->prev=newNode;
	   *head=newNode;
	 return;
	 }
	else{
	temp=*head;
		//travese list until the position where we want to insert
		while((temp->next!=NULL) && (k < position)){
			k++; temp=temp->next;			
			 
			}

		if(k < position) {
		printf("Position Does not Exist");
		return;
		} 

		newNode->next=temp->next;
		newNode->prev=temp;
		if(temp->next)  //wheather temp is Last Node ??
		temp->next->prev=newNode;

		temp->next=newNode;
	}	return;	     
}       

/*Traversal Of List*/

	void Traverse(DNode *head){
		DNode *current=head;

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

	void deleteNode(DNode **head){
		int k=1,pos;
		DNode *temp,*temp2;
		temp=*head;

		if(*head == NULL){
		printf("\t!~~~~~~~~~~~~~~~List Empty~~~~~~~~~~~~~!\n");
		return;
		}
		                        
                        printf("Which position :");
                        scanf("%d",&pos);

		
			if(pos == 1) /*First Node Deletion*/
			{
				*head=(*head)->next;
				if(*head != NULL)
				(*head)->prev = NULL;
				
				free(temp);
				return;
			}
		
	
				while((temp->next!= NULL) && ( k< pos)){
					temp=temp->next;
					k++;
					}
				if(k!=pos)
				{  		/*End Node*/
				printf("Position Not Exist");
				return;
				}

					temp2=temp->prev;/*Middle Node*/
					temp2->next=temp->next;
					if(temp->next)
					temp->next->prev=temp2;
					free(temp);
	return;
	}

	void DeleteLinkList(DNode **head){
		DNode *auxiliaryNode,*iterator;
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

   int main(){
	int position,data;
	int ch;
	DNode *head;
	head=create(); //Initialisation List


    while(1){
	
		printf("\n");
                printf("<1> Insert,  ");
                printf("<2> Traverse, ");
                printf("<3> Delete, ");
		printf("<4> Delete Total List  ");
                printf("<5> Exit\n");

                scanf("%d",&ch);

		if(ch == 1){
                        
                        printf("Enter Value And Position \n");
                        scanf("%d %d",&data,&position);
                        
                        insertNode(&head,data,position);
			}

		else if(ch == 2){
                        Traverse(head);
			}
		
		else if(ch == 3){
                        deleteNode(&head);
			}

		else if(ch == 4){
			DeleteLinkList(&head);
			}

		else if(ch == 5){
			DeleteLinkList(&head);
			exit(0);
			}

		else
		printf("Invalid Choice \n");
                
	    }
   return 0;
	}

