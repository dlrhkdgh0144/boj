#include<stdio.h>
long long fi[90]={0,};
int main(void){
	int n,i;
	fi[0]=1;
	fi[1]=1;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		if(i>1&&fi[i]==0){
			fi[i]=fi[i-2]+fi[i-1];
		}
	}
	printf("%lld\n",fi[n-1]);
} 
