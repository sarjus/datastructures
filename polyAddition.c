/*
 * polyAddition.c
 *
 *  Created on: 26-Aug-2017
 *      Author: Sarju S
 */
/* polynomial using linkd list*/
#include<stdio.h>
#include<stdlib.h>

typedef struct polyNode{
	int coef;
	int expo;
	struct polyNode *next;
}polyNode;

polyNode *startC=NULL,*cur_ptr=NULL;

polyNode *poly_read()
 	{
	polyNode *start=NULL,*p,*temp=NULL;
 	int no_ofterms,i;
 	setbuf(stdout,NULL);
 	printf("\nEnter the no_of terms\n");
 	scanf("%d",&no_ofterms);
 	for(i=0;i<no_ofterms;i++){
 		p=(polyNode*)malloc(sizeof(polyNode));
 		printf("enter the coefficient and exponent\n");
 		scanf("%d%d",&p->coef,&p->expo);
 		p->next=NULL;
 		if(start==NULL){
 			start=p;
 			temp=p;
 		}
 		else{
 			temp->next=p;
 			temp=p;
 		}
 	}
 	return(start);
 }

int compare(int expo1,int expo2){

 	if(expo1<expo2)
 		return -1;
 	else if(expo1>expo2)
 		return 1;
 	else
 		return 0;
 	}

void attach(int coefficient,int exponent){

	polyNode *temp;
 	temp=(polyNode*)malloc(sizeof(polyNode));
 	temp->coef=coefficient;
 	temp->expo=exponent;
 	temp->next=NULL;
 	if(startC==NULL){
 		startC=temp;
 		cur_ptr=temp;
 	}
 	else{
 		cur_ptr->next=temp;
 		cur_ptr=temp;
 	}

 }

void poly_add(polyNode *a,polyNode *b)
 	{

 	int sum;
 	polyNode *startA,*startB;
 	startA=a;
 	startB=b;
	while(startA && startB){
 		switch(compare(startA->expo,startB->expo)){
 		case -1:attach(startB->coef,startB->expo);
       			startB=startB->next;
       			break;
 		case 0:	sum= startA->coef+startB->coef;
 				if(sum)
 				attach(sum,startA->expo);
 				startA=startA->next;
 				startB=startB->next;
 				break;
 		case 1:attach(startA->coef,startA->expo);
 			   startA=startA->next;
 		}
 	}

 	for(;startA;startA=startA->next)
 		attach(startA->coef,startA->expo);
 	for(;startB;startB=startB->next)
 		attach(startB->coef,startB->expo);
}
void poly_print(polyNode *d){
 	for(;d;d=d->next)
 		printf("%d X^%d+",d->coef,d->expo);
 }

int main(){

	polyNode *a,*b,*c;
 	printf("\n The first polynomial\n");
 	a=poly_read();

 	printf("\nThe  second polynomial\n");
 	b=poly_read();
 	poly_add(a,b);

 	printf("\nFIRST POLYNOMIAL\n\n");
 	pprint(a);
 	printf("\nSECOND POLYNOMIAL\n\n");
 	poly_print(b);


 	printf("\nRESULTING POLYNOMIAL\n\n");
 	c=startC;
 	poly_print(c);
 	return 0;
 	}

