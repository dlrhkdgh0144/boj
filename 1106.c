#include<stdio.h>

int dp[1001];

int main(void){
    int c,n,i,j,min,tmp;
    int cost[20],cus[20];
    scanf("%d %d",&c,&n);
    for(i=0;i<n;i++){
        scanf("%d %d",&cost[i],&cus[i]);
    }
    dp[0]=0;
    for(i=1;i<=c;i++){
        min=1000001;
        for(j=0;j<n;j++){
            if(i-cus[j]>0){
                tmp=dp[i-cus[j]]+cost[j];
                if(tmp<min) min=tmp;
            }
            else{
                if(min>cost[j]) min=cost[j];
            }
        }
        dp[i]=min;
    }
    printf("%d\n",dp[c]);
}
