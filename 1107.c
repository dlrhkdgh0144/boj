#include<stdio.h>
#include<string.h>
#include<math.h>

int main(void){
	int n,m,but[10]={0,},i,j,tmp;
	int cur,ok,min;
	scanf("%d",&n);
	scanf("%d",&m);
	for(i=0;i<m;i++){
		scanf("%d",&tmp);
		but[tmp]=1;
	}
	min=abs(n-100);
	for(i=0;i<=999999;i++){
		cur=i;
        	ok=0;
        	j=0;
        	while(1){
        	    tmp=cur%10;
        	    if(but[tmp]==1){
        	        break;
        	    }
        	    else cur=cur/10;
        	    j++;
        	    if(cur==0){
        	        ok=1;
        	        break;
        	    }
        	}
        	if(ok){
        	    if(min>(j+abs(n-i))) min=j+abs(n-i);
        	}
	}
	printf("%d\n",min);
}
