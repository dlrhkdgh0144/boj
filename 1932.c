#include<stdio.h>

int main(void){
    int n,i,j,tri[501][501],dp[501][501];
    int max=0,tmp;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++){
            scanf("%d",&tri[i][j]);
        }
    }
    dp[0][0]=tri[0][0];
    for(i=1;i<n;i++){
        dp[i][0]=dp[i-1][0]+tri[i][0];
        dp[i][i]=dp[i-1][i-1]+tri[i][i];
        for(j=1;j<i;j++){
                if(dp[i-1][j-1]>dp[i-1][j]){
                    tmp=dp[i-1][j-1];
                }
                else tmp=dp[i-1][j];
                dp[i][j]=tri[i][j]+tmp;
        }
    }
    for(i=0;i<n;i++){
        if(max<dp[n-1][i]) max=dp[n-1][i];
    }
    printf("%d\n",max);
}
