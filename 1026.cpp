#include<stdio.h>
#include<stdlib.h>
int comp(const void *a,const void *b){
	int n1=*(int *)a;
	int n2=*(int *)b;
	if(n1>n2) return 1;
	if(n1<n2) return -1;
	return 0;
}
int comp2(const void *a,const void *b){
	int n1=*(int *)a;
	int n2=*(int *)b;
	if(n1<n2) return 1;
	if(n1>n2) return -1;
	return 0;
}
int main(void){
	int n,a[50],b[50],i,s=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
		scanf("%d",&b[i]);
	}
	qsort(a,n,sizeof(int),comp);
	qsort(b,n,sizeof(int),comp2);
	for(i=0;i<n;i++){
		s+=a[i]*b[i];
	}
	printf("%d\n",s);
}
