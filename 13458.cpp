#include<stdio.h>
int main(void){
	int n,b,c,i,a[1000001],j;
    long long res=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	scanf("%d %d",&b,&c);
	for(i=0;i<n;i++){
		if(a[i]>=b){
			j=(a[i]-b)/c;
			if((a[i]-b)%c==0){
				res+=j;
			}
			else res+=j+1;
		}
	}
	res+=n;
	printf("%lld\n",res);
}
