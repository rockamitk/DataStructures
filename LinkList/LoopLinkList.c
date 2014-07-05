#include<stdio.h>
#include<stdlib.h>

struct LinkList {
		int data;
		struct LinkList *next;
};

typedef struct LinkList LL;


	LL *createList()
	{
		LL *head;
		head=NULL;
		return head;
	}
	
	

	void insertNode(LL **head,int data)
        {
		LL *p,*q,*newNode;

		newNode=(LL *)malloc(sizeof(LL));
	
		if(!newNode){
		printf("MemmoryError");
		return;
		}

		newNode->data=data;
		p=*head;

	//inserting at begining

		if(!(*head))
		{
		   newNode->next=p;
		   *head=newNode;
		 }
		else 
		{
		//insert at list
		while(p!=NULL)
		{	q=p;
			p=p->next;
		}
		q->next=newNode; 
		newNode->next=p;
	     	}
	}

/*Traversal Of List*/

	void Traverse(LL *head)
	{
		LL *current=head;

		if(head == NULL){
		printf("NULL\n");
		return;
		}
		
		while(current!= NULL){
		printf(" %d ",current->data);
		current=current->next;
		}
	  printf("\n");

	}

/*Deletion Of Link List Node */

	int deleteNode(LL **head,int data)
	{
		int flag=1;
		LL *p=*head,*q,*t;
		if(*head == NULL){
		printf("NULL\n");
		return 0;
		}
			if((*head)->data == data) /*First Node Deletion*/
			{
				
				*head=(*head)->next;
				free(p);
				p=*head;
			}
		
			     while(flag) // Delete Duplicate Node
			     {
				while((p!= NULL) && (p->data != data))
				{
					q=p;
					p=p->next;
				}
				if(p == NULL)
				{  		/*End Node*/
//				printf("Node does not exist");
				return 0;
				}
				else
				{
					q->next=p->next;/*Middle Node*/
					t=p;
					p=q->next;
					free(t);
					flag=0;
				}
			  
			      if(p) flag=1;
			    }
			    
	return data;
	}
	
	void reversePrint(LL *head)
	 {
	 if(!head) return;
	 reversePrint(head->next);
	 printf(" %d ",head->data);
	 }

	int OddEven(LL *head)
	{
		while(head && head ->next)
		head=head->next->next;
		if(!head)
		return 0;
	    return 1;
	}
	
	LL *mergeList(LL *a,LL *b)
	{
		LL *list=NULL;
		if(!a)
		return b;
		if(!b)
		return a;
		
		if(a->data <= b->data)
		{
		 list=a;
		 list->next=mergeList(a->next,b);
		}

		else
		{
		 list=b;
		 list->next=mergeList(a,b->next);
		}
	return list;
	}

	LL *reversePair(LL *head)  //incorrect O/P
	{
		LL *temp;
		
		if(head==NULL || head->next==NULL)
		return NULL;
		else
		{
		temp=head->next;
		head->next=temp->next;
		temp->next=head;
		
		reversePair(head->next);
		}
	return temp;
	}
	
		
/*	void reversePair(LL *head)
	{
		LL *temp,*temp2;
		
		while(head!=NULL && head->next!=NULL)
		{
		temp=head->next;
		temp2=temp->next;
		temp->next=head;
		head->next=temp2;
		if(head)
		head=head->next;
		}
	}
*/	
	LL *findMiddle(LL *head)
	{ 
	   LL *ptr1,*ptr2;
	      ptr1=ptr2=head;
	      int i=0;
	      
	      while(ptr1->next !=NULL)
	      {
	      	if(i==0){
	      	ptr1=ptr1->next;
	      	i=1;
	      	}
	      	else if(i==1){
	      		ptr1=ptr1->next;
	      		ptr2=ptr2->next;
	      		i=0;
	      		}
	      }
	      return ptr2;
	 }
	  
      LL *reverseList(LL *head)
	  {
	  	LL *temp=NULL,*nextNode=NULL;
	  	while(head)
	  	{
	  	nextNode=head->next;
	  	head->next=temp;
	  	temp=head;
	  	head=nextNode;
		  }
		 return temp;
	   }	  
	int CompareNode(LL *a,LL *b)
	{	int flag=1;
		while(a && b)
		{	
		if(a->data != b->data){
		flag=0;break;
		}
		a=a->next;b=b->next;
		}
		return flag;
	}
	
	LL *GetKplusOneThNode(int K,LL *head)
	{
	    LL *Kth;int i=0;
	    if(!head) return head;
	
	   for(i=0,Kth=head;Kth && (i<K); i++,Kth=Kth->next);
	    
	     if(i == K && Kth!=NULL)
	     return Kth;
	     return head->next;
	}
	
	int HasKnodes(LL *head,int K)
	{
		int i;
		for(i=0;head && (i < K);i++,head=head->next);
			if(i == K)
			     return 1;
			  return 0;
	}
	
	LL *ReverseBlockOfKNodes(LL *head,int K)
	{
		LL *cur=head,*temp,*next,*newHead;
		int i;
		if(K==0 || K==1)
			return head;
		if(HasKnodes(cur,K-1))
			newHead=GetKplusOneThNode(K-1,cur);
		else
		newHead=head;
		
		while(cur && HasKnodes(cur,K))
		{
		   temp=GetKplusOneThNode(K,cur);
		   i=0;
		   
		   while(i < K)
		   {
		   	next=cur->next;
		   	cur->next=temp;
		   	temp=cur;
		   	cur=next;
		   	i++;
		   }
		 }
		 
		 return newHead;
	}
	

int main()
{	LL *head=createList();
	LL *head2=createList();
	int data,ch;
	
	while(1)
	{
	 printf("\n1.Insert, 2.Delete, 3.Traverse, 4. reversePrint\n");
	 printf("5. List Even/Odd, 6. Merge Two List, 7.ReversePairNode\n");
	 printf("8.Palindrome,9.Reverse Block OfNodes,  0. Exit,  Choice :");
	 scanf("%d",&ch);
	 
	 switch(ch)
	 {
	 	case 1:
			printf("\t1. FirstList, 2. SecondList, Choice:");
			 scanf("%d",&ch);
 			 printf("Node Value:");
			 scanf("%d",&data);
			 if(ch == 1)
			 insertNode(&head,data);
			 else 
			 insertNode(&head2,data);
			 break;
	 		
	 	case 2:
 			 printf("Node Value:");
			 scanf("%d",&data);
			 ch=deleteNode(&head,data);
			 if(ch) printf("Node deleted :%d\n",ch);
			 break;
	
		case 3: 
			printf("\tFirst List:");
			Traverse(head);
			printf("\tSecond List:");
			Traverse(head2);
			break;
			
			
		case 4: printf("\tLink List :");
			reversePrint(head);
			printf("\n");
			break;

		case 5:
			 ch=OddEven(head);
			 if(ch) printf("\tList have Odd Length \n");
			else printf("\tList have Even Length\n");
			break;
			
		case 6:
			head=mergeList(head,head2);
			head2=NULL;printf("\n\tMerge in First List:");
			Traverse(head);
			break;
			
		case 7:
			head2=reversePair(head);
			Traverse(head2);
			break;
			
		case 8:
			head2=findMiddle(head);
			head2=reverseList(head2);
			//head=reverseList(head);
			//Traverse(head2);Traverse(head);
			ch=CompareNode(head,head2);
			 if(ch) printf("\tList are palindrom\n");
			 else printf("\tList are not palindrom\n");
			break;
		case 9:
			head2=ReverseBlockOfKNodes(head,3);
			Traverse(head2);
			break;
			
		case 0:
			exit(0);
		default :
			printf("Invalid Choicen");
			break;
	}
       }
return 0;
}
