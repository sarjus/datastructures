/* polynomial using linkd list*/
#include<stdio.h>
#include<stdlib.h>

typedef struct polyNode{
	int coef;
	int expo;
	struct polyNode *next;
}polyNode;

node *startC=NULL,*cur_ptr=NULL;

node *pread()
 	{
 	node *start=NULL,*p,*temp=NULL;
 	int no_ofterms,i;
 	setbuf(stdout,NULL);
 	printf("\nEnter the no_of terms\n");
 	scanf("%d",&no_ofterms);
 	for(i=0;i<no_ofterms;i++){
 		p=(node*)malloc(sizeof(node));
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

 	node *temp;
 	temp=(node*)malloc(sizeof(node));
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

void polyadd(node *a,node *b)
 	{

 	int sum;
 	node *startA,*startB;
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
void pprint(node *d){
 	for(;d;d=d->next)
 		printf("%d X^%d+",d->coef,d->expo);
 }

int main(){

 	node *a,*b,*c;
 	printf("\n The first polynomial\n");
 	a=pread();

 	printf("\nThe  second polynomial\n");
 	b=pread();
 	polyadd(a,b);

 	printf("\nFIRST POLYNOMIAL\n\n");
 	pprint(a);
 	printf("\nSECOND POLYNOMIAL\n\n");
 	pprint(b);


 	printf("\nRESULTING POLYNOMIAL\n\n");
 	c=startC;
 	pprint(c);
 	return 0;
 	}

