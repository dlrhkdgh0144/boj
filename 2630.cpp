#include<stdio.h>
int white=0;
int blue=0;
int arr[128][128];

void dnc(int sx, int sy, int ex, int ey){
	int i,j,color=arr[sx][sy];
	for(i=sx;i<ex;i++){
		for(j=sy;j<ey;j++){
			if(color!=arr[i][j]){
				dnc(sx,sy,(sx+ex)/2,(sy+ey)/2);
				dnc((sx+ex)/2,sy,ex,(sy+ey)/2);
				dnc(sx,(sy+ey)/2,(sx+ex)/2,ey);
				dnc((sx+ex)/2,(sy+ey)/2,ex,ey);
				return;
			}
		}
	}
	if(color==0) white++;
	else blue++;
	return;
}

int main(void){
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	dnc(0,0,n,n);
	printf("%d\n%d\n",white,blue);
}
