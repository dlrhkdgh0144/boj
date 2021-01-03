#include<stdio.h>

int value(int a,int b){
	a=a%10;
	b=b%4;
	int i,res=1;
	if(b==0) b=4;
	if(a==0) return 10;
	if(a==1||a==5||a==6){
		return a;
	}
	else{
		for(i=0;i<b;i++){
			res*=a;
		}
		res=res%10;
		return res;
	}
}

int main(void){
	int t,i,a,b;
	int ans[100000];
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%d %d",&a,&b);
		ans[i]=value(a,b);
	}
	for(i=0;i<t;i++){
		printf("%d\n",ans[i]);
	}
}
