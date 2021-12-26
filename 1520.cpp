#include<vector>
#include<iostream>

using namespace std;

vector<vector<int> > map;
vector<vector<int> > roots;
int m,n;

int dfs(int curx,int cury){
    int cur,res=0;

    cur = map[curx][cury];
    if(curx>0&&map[curx-1][cury]<cur){//up
        if(roots[curx-1][cury]>=0){
            res+=roots[curx-1][cury];
        }
        else res+=dfs(curx-1,cury);
    }
    if(cury>0&&map[curx][cury-1]<cur){//left
        if(roots[curx][cury-1]>=0){
            res+=roots[curx][cury-1];
        }
        else res+=dfs(curx,cury-1);
    }
    if(curx<m-1&&map[curx+1][cury]<cur){//down
        if(roots[curx+1][cury]>=0){
            res+=roots[curx+1][cury];
        }
        else res+=dfs(curx+1,cury);
    }
    if(cury<n-1&&map[curx][cury+1]<cur){//right
        if(roots[curx][cury+1]>=0){
            res+=roots[curx][cury+1];
        }
        else res+=dfs(curx,cury+1);
    }

    roots[curx][cury]=res;

    return res;
}

int main(void){
    int answer=0;
    cin>>m>>n;
    for(int i=0;i<m;i++){
        vector<int> v(n);
        vector<int> r(n,-1);
        map.push_back(v);
        roots.push_back(r);
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        }
    }
    roots[m-1][n-1]=1;
    answer=dfs(0,0);
    cout<<answer<<endl;
    return 0;
}
