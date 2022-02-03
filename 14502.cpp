#include<stdio.h>
#include<queue>
#include<iostream>

using namespace std;

int board[8][8];
int n,m;
int res=0;

void bfs(){
    int area=0;
    queue<pair<int,int> > q;
    int check[8][8]={0,};
    int tb[8][8]={0,};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]==2){
                q.push(pair<int,int>(i,j));
                check[i][j]=1;
            }
            tb[i][j]=board[i][j];
        }
    }

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        if(x<n-1&&tb[x+1][y]==0&&check[x+1][y]==0){
            tb[x+1][y]=2;
            q.push(pair<int,int>(x+1,y));
            check[x+1][y]=1;
        }
        if(x>0&&tb[x-1][y]==0&&check[x-1][y]==0){
            tb[x-1][y]=2;
            q.push(pair<int,int>(x-1,y));
            check[x-1][y]=1;
        }
        if(y<m-1&&tb[x][y+1]==0&&check[x][y+1]==0){
            tb[x][y+1]=2;
            q.push(pair<int,int>(x,y+1));
            check[x][y+1]=1;
        }
        if(y>0&&tb[x][y-1]==0&&check[x][y-1]==0){
            tb[x][y-1]=2;
            q.push(pair<int,int>(x,y-1));
            check[x][y-1]=1;
        }
        q.pop();
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(tb[i][j]==0){
                area++;
            }
        }
    }
    if(area>res) res = area;
}

void solution(int x, int y, int dep){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]==0&&dep<2){
                board[i][j]=1;
                solution(i,j,dep+1);
                board[i][j]=0;
            }
            else if(board[i][j]==0&&dep==2){
                board[i][j]=1;
                bfs();
                board[i][j]=0;
            }
        }
    }
}

int main(void){
    int i,j;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&board[i][j]);
        }
    }
    solution(0,0,0);
    cout<<res<<endl;
}
