#include<stdio.h>

int main(){
    int i,n,st[4],result=0,now,prev=0,flag=0,dp[500];
    char rank[36];
    scanf("%d",&n);
    for(i=0;i<4;i++){
        scanf("%d",&st[i]);
    }
    scanf("%s",rank);
    for(i=0;i<n;i++){
        if(rank[i]=='B') now=st[0]-1;
        else if(rank[i]=='S') now=st[1]-1;
        else if(rank[i]=='G') now=st[2]-1;
        else if(rank[i]=='P') now=st[3]-1;
        else now=st[3];
        if(now==st[3]&&i>0) dp[i]=dp[i-1]+now;
        else if(i<2) dp[i]=now;
        else{
            if(dp[i-2]+now>dp[i-1]||now<prev) dp[i]=dp[i-2]+now;
            else dp[i]=dp[i-1];
        }
        prev=now;
        /*
        if(rank[i]=='B') now=st[0]-1;
        else if(rank[i]=='S') now=st[1]-1;
        else if(rank[i]=='G') now=st[2]-1;
        else if(rank[i]=='P') now=st[3]-1;
        else now=st[3];

        if(rank[i]=='D'||flag==1) result+=now;
        else result+=(now-prev);

        if(now-prev <0&&flag==0) flag=1;
        else flag=0;
        prev=now;*/
    }
    printf("%d\n",dp[n-1]);
    return 0;
}
