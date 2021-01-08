#include<stdio.h>
int v[50][50]={0,};
int a[50][50]={0,};
void init(int arr[50][50]){
	int i,j;
	for(i=0;i<50;i++){
		for(j=0;j<50;j++){
			arr[i][j]=0;
		}
	}
}
void dfs(int x,int y,int m,int n){
	if((x+1<m&&a[x+1][y]==1)&&v[x+1][y]==0){//right
		v[x+1][y]=1;
		dfs(x+1,y,m,n);
	}
	if((x-1>=0&&a[x-1][y]==1)&&v[x-1][y]==0){//left
		v[x-1][y]=1;
		dfs(x-1,y,m,n);
	}
	if((y-1>=0&&a[x][y-1]==1)&&v[x][y-1]==0){//up
		v[x][y-1]=1;
		dfs(x,y-1,m,n);
	}
	if((y+1<n&&a[x][y+1]==1)&&v[x][y+1]==0){//up
		v[x][y+1]=1;
		dfs(x,y+1,m,n);
	}
}
int main(void){
	int i,j,ans[100]={0,},m,n,k,t,x,y,b;
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%d %d %d",&m,&n,&k);
		for(j=0;j<k;j++){
			scanf("%d %d",&x,&y);
			a[x][y]=1;
		}
		for(b=0;b<m;b++){
			for(j=0;j<n;j++){
				if(v[b][j]==0&&a[b][j]==1){
					ans[i]++;
					dfs(b,j,m,n);
				}
			}
		}
		init(a);
		init(v);
	}
	for(i=0;i<t;i++){
		printf("%d\n",ans[i]);
	}
}
