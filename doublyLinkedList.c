/*
 * doublyLinkedList.c
 *
 *  Created on: 26-Aug-2017
 *      Author: Sarju S
 */
#include<stdio.h>
#include<stdlib.h>
typedef struct doublyNode{
	int data;
	struct doublyNode *rightLink;
	struct doublyNode *leftLink;
}doublyNode;
doublyNode *head=NULL;
doublyNode * createNode(int data){
	doublyNode *temp;
	temp = (doublyNode*)malloc(sizeof(doublyNode));
	temp->data = data;
	temp->rightLink=NULL;
	temp->leftLink =NULL;
	return temp;
}
void insert_at_beg(int data){
	doublyNode  *new_node;
	new_node = createNode(data);
	if(head==NULL){
		head =new_node;
	}
	else{
		new_node->rightLink=head;
		head->leftLink=new_node;
		head =new_node;
	}
}

void insert_at_end(int data){
	doublyNode  *new_node,*temp;
	new_node = createNode(data);
	if(head==NULL){
		head =new_node;
	}
	else{
		for(temp=head;temp->rightLink!=NULL;temp=temp->rightLink);
		temp->rightLink=new_node;
		new_node->leftLink=temp;

	}
}
void insert_at_pos(int data, int pos){
	doublyNode *temp,*new_node;
	int i;
	new_node = createNode(data);
	temp = head;

	if(pos==1){
		insert_at_beg(data);
	}
	else{
		for(i=1;i<pos;i++){
				temp=temp->rightLink;
			}
		temp->leftLink->rightLink=new_node;
		new_node->leftLink=temp->leftLink;
		new_node->rightLink=temp;
		temp->leftLink=new_node;
	}
}
void display(){
	doublyNode *temp;
	temp=head;
	while(temp){
		printf("%d->", temp->data);
		temp=temp->rightLink;
	}
}
void delete_number(int number){
	doublyNode *temp,*current;
	while(head&&head->data==number){
		temp = head;
		if(head->rightLink==NULL){
			head=NULL;
		}
		else{
			head=temp->rightLink;
			head->leftLink=NULL;
		}

		free(temp);
	}
	 for (current = head; current != NULL; current = current->rightLink)
		    {
		        while (current->rightLink != NULL && current->rightLink->data == number)
		        {
		            temp = current->rightLink;
		            current->rightLink = temp->rightLink;
		            temp->rightLink->leftLink=current;
		            free(temp);
		        }
		    }
}
int main(){
	int choice,data,pos;
	do{
		setbuf(stdout,NULL);
		printf("\n1.INSERT AT BEG\n2.INSERT AT END\n3.INSERT AT POS\n4.DELETE NO\n5.DISPLAY\n6.EXIT");
		printf("\nENTER YOUR CHOICE:");
		scanf("%d",&choice);
		switch(choice){
		case 1: printf("\nEnter the element to insert:");
				scanf("%d",&data);
				insert_at_beg(data);
				break;
		case 2: printf("\nEnter the element to insert:");
				scanf("%d",&data);
				insert_at_end(data);
				break;
		case 3: printf("\nEnter the element to insert and Position:");
				scanf("%d%d",&data,&pos);
				insert_at_pos(data,pos);
				break;
		case 4: printf("\nEnter the element to be deleted:");
				scanf("%d",&data);
				delete_number(data);
				break;
		case 5: display();
		}
	}while(choice<6);
}
