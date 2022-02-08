#include<stdio.h>
int main(void){
	int n,i=0,j=0;
	scanf("%d",&n);
	while(1){
		if(n-1<=j*6){
			printf("%d\n",i+1);
			break;
		}
		i++;
		j+=i;
	}
}
