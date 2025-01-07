#include <stdio.h>
#include <stdlib.h>

typedef struct nod{
	int data;
	struct nod* next;
} node;

node* createNode(int x){
	node* newN=(node*)malloc(sizeof(node));
	newN->data=x;
	newN->next=NULL;
	return newN;
}

void createListAndRow(node** rootn, int** row){
	int x=0;
	node* curn=*rootn;
	int* curr=*row;
	while(x!=-1){
		printf("Enter neighbor (-1 to stop): ");
		scanf("%d",&x);
		if(x==-1) break;
		curr[x-1]=1;
		curn->next=createNode(x);
		curn=curn->next;
	}
}

void main(){
	int n,x;
	printf("Enter no. of nodes: ");
	scanf("%d",&n);
	node** adjLs=(node**)malloc(n*sizeof(node*));
	int** adjMx=(int**)malloc(n*sizeof(int*));
	for(int i=0;i<n;i++){
		printf("Node %d:\n",i+1);
		adjLs[i]=createNode(i+1);
		adjMx[i]=(int*)calloc(n,sizeof(int));
		createListAndRow(&adjLs[i],&adjMx[i]);
	}
	printf("Adjacency lists:\n");
	for(int i=0;i<n;i++){
		node* cur=adjLs[i];
		printf("%d: ",cur->data);
		while(cur->next){
			cur=cur->next;
			printf("%d ",cur->data);
		}
		printf("\n");
	}
	printf("Adjacency matrix:\n");
	for(int i=0;i<n;i++){
		printf("%d: ",i+1);
		for(int j=0;j<n;j++){
			printf("%d ",adjMx[i][j]);
		}
		printf("\n");
	}
}