#include<stdio.h>

int n,m;
char map[101][101];
int visit[101][101]={0,};
typedef struct Node{
	int x;
	int y;
	int time;
	struct Node *next;
}Node;
typedef struct Queue{
	Node *front;
	Node *rear;
}Queue;
void push(Queue *q, int x, int y, int t){
	Node *newnode=(Node*)malloc(sizeof(Node));
	newnode->next=NULL;
	newnode->x=x;
	newnode->y=y;
	newnode->time=t;
	if(q->front==NULL){
		q->front=newnode;
		q->rear=newnode;
	}
	else{
		q->rear->next=newnode;
		q->rear=newnode;
	}
}
void pop(Queue *q){
	Node *tmp;
	tmp=q->front;
	q->front=q->front->next;
	if(q->front==NULL) q->rear=NULL;
	free(tmp);
}
void bfs(Queue *q){
	int x=q->front->x,y=q->front->y,t=q->front->time;
	if(x==n-1&&y==m-1){
		printf("%d\n",t);
		exit(0);
	}
	if(x<n-1&&visit[x+1][y]==0){//down
		if(map[x+1][y]=='1'){
			visit[x+1][y]=1;
			push(q,x+1,y,t+1);
		}
	}
	if(x>0&&visit[x-1][y]==0){//up
		if(map[x-1][y]=='1'){
			visit[x-1][y]=1;
			push(q,x-1,y,t+1);
		}
	}
	if(y>0&&visit[x][y-1]==0){//left
		if(map[x][y-1]=='1'){
			visit[x][y-1]=1;
			push(q,x,y-1,t+1);
		}
	}
	if(y<m-1&&visit[x][y+1]==0){//left
		if(map[x][y+1]=='1'){
			visit[x][y+1]=1;
			push(q,x,y+1,t+1);
		}
	}
	pop(q);
	if(q->front!=NULL) bfs(q);
}
int main(void){
	int i;
	Queue *q=(Queue*)malloc(sizeof(Queue));
	scanf("%d %d",&n,&m);
	q->front=NULL;
	q->rear=NULL;
	for(i=0;i<n;i++){
		scanf("%s",map[i]);
	}
	visit[0][0]=1;
	push(q,0,0,1);
	bfs(q);
}
