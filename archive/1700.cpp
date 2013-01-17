/*
 * poj1700	Cross river
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


int compare(const void* a,const void* b)
{
	return *(int*)a - *(int*)b;
}

//qsort(a,n,sizeof(a[0]),compare);
int person[1000+1];
int main()
{
	int T;
	int N;
	int a,b,x,y; // a<b << x< y
	int total;

	scanf("%d",&T);
	while(T--){
		total = 0;
		scanf("%d",&N);
			for(int i=0;i<N;i++)
				scanf("%d",person+i);
			qsort(person,N,sizeof(person[0]),compare);
			while(N>0){
				if(N>=4){
					a = person[0];
					b = person[1];
					x = person[N-2];
					y = person[N-1];
					if((x+a)>2*b)
						total +=b+a+y+b;
					else
						total +=x+a+y+a;
					N-=2;
					continue;
				}
				else if(N==1)
					total+=person[0];
				else if(N==2)
					total +=person[1];
				else if(N==3)
					total +=person[1] + person[2] + person[0];
				break;
			}

	printf("%d\n",total);
	}
	return 0;
}
