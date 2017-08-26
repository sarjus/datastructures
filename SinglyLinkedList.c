/*
 * SinglyLinkedList.c
 *
 *  Created on: 23-Jul-2017
 *      Author: Sarju S
 */
/* linked list operations*/

#include<stdio.h>
#include<stdlib.h>

struct node{

int data;
struct node *next;
} ;

typedef struct node node;

node *head=NULL;
node* createNode(){
    node *temp; // declare a node
    temp = (node*) malloc(sizeof(node)); // allocate memory using malloc()
    temp->next = NULL;// make next point to NULL
    return temp;//return the new node
}
void insert_at_beg(int data){
	/* add in the beginning*/
   	node *new_node;
   	new_node= createNode();
   	new_node->data=data;
 	if(head==NULL){
 		head=new_node;
 		//head->next=NULL;
 	}
 	else{
 		new_node->next=head;
 		head=new_node;
 	}
 }


void insert_at_end(int data){
 	/* add in the end*/
 	node *new_node,*current;
 	new_node= createNode();
 	new_node->data=data;
 	current=head;
 	if(current==NULL){/*Linked List is Empty */
 		head=new_node;
 	}
 	else{ /*Linked List is not Empty */
 		while(current->next!=NULL){
 			current=current->next;
 		}
  		current->next=new_node;

 	 	}
 	}

void insert_at_pos(int data,int pos){
 	/* add in a position*/
 	  int i;
 	  node *new_node,*prev_ptr,*cur_ptr;
 	  if(pos==1){
 		insert_at_beg(data);
 	  }
 	  else{

 		  new_node= createNode();
 		  new_node->data=data;
 		  cur_ptr=head;
 		  for(i=1;i<pos;i++){
 			  prev_ptr=cur_ptr;
 			  cur_ptr=cur_ptr->next;
 		 	}
 		  prev_ptr->next=new_node;
 		  new_node->next=cur_ptr;
 	  }
 }

void deleteNumber(int num){
	node * temp, *current;
	// remove initial matching elements
	    while (head && head->data == num)
	    {
	        temp = head;
	        head = head->next;
	        free(temp);
	    }

	    // remove non-initial matching elements
	    // loop invariant: "current != NULL && current->data != num"
	    for (current = head; current != NULL; current = current->next)
	    {
	        while (current->next != NULL && current->next->data == num)
	        {
	            temp = current->next;
	            current->next = temp->next;
	            free(temp);
	        }
	    }
 }

 void deleteFromlocation(int loc){
 	int i;
 	node *cur_ptr,*pre_ptr;
 	cur_ptr=head;
 	pre_ptr = head;
 	if(loc==1){
 		head=head->next;
 	}
 	else{
 		for(i=1;i<loc;i++){
 		  		pre_ptr=cur_ptr;
 		 		cur_ptr=cur_ptr->next;
 		 	}
 		 	pre_ptr->next=cur_ptr->next;
 	}

 		free(cur_ptr);
 }

void display(){
	node *cur_ptr;
 	cur_ptr=head;
 	if(cur_ptr==NULL){
 		printf("\n there are no elements to be displayed");
 	}
 	else{
 		 while(cur_ptr!=NULL){
 		 	 printf("->%d",cur_ptr->data);
 		 	 cur_ptr=cur_ptr->next;
 		 }
 	}
}

int main(){
	int ch,data,num,pos;
 	do{
 		setbuf(stdout,NULL);
 		printf("\n 1.insert in beginning\n 2.insert at end\n3.insert at particular position\n4.delete a particular value\n5.delete a particular location\n6.display\n7.exit");
 		 	 	scanf("%d",&ch);
	 	 		switch(ch){
 		 	 		case 1 : printf("enter element to be inserted");
 		 	   		   scanf("%d",&data);
 		 	   		   insert_at_beg(data);
 		 	 		   break;

 		 	 	 	case 2 : printf("enter the element to be inserted");
 		 	     		 scanf("%d",&data);
 		 	     		insert_at_end(data);
 		 	    		 break;
 		 	 	 	case 3 :printf("enter the element to be inserted and position");
 		 	 	     	 	 scanf("%d%d",&data,&pos);
 		 	 	     	 	 insert_at_pos(data,pos);
 		 	 	    		 break;
 	 	      		case 4 :printf("enter  value to be deleted");
 		 	 	     		 scanf("%d",&num);
 		 	 	     		deleteNumber(num);
 		 	 	    		 break;

 		 	 	  	case 5 :printf("enter location to be del3eted");
 		 	 	    		  scanf("%d",&pos);
 		 	 	    		deleteFromlocation(pos);
 		 	 	   		  break;

 		 	 	  	case 6 : display();
 		 	 	  		   break;
 		 	 	  		}
 		 	 	}while(ch!=7);
 		return 0;
 }

