/*
 * poj1065  Wooden Sticks
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct Wooden{
	int l; //length
	int w; //width
	int flags;
}wood[5000+1],wood2[5000+1];

int compare(const void* a,const void* b)
{
	int ret;
	ret = ((struct Wooden*)a)->l - ((struct Wooden*)b)->l;
	if(ret==0)
		ret = ((struct Wooden*)a)->w - ((struct Wooden*)b)->w;
	return ret;
}

int main()
{
	int T;
	int n;
	int setup_time;
	int i,j,k;

	scanf("%d",&T);
	while(T--){
		setup_time=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d%d",&wood[i].l,&wood[i].w);
			wood[i].flags=1;
		}

		qsort(wood,n,sizeof(wood[0]),compare);

		int finish=0;
		int minWidth;
		int start=0;
		while(finish<n){
			for(int i=start;i<n;i++){
				if(wood[i].flags==1){
					start=i;
					break;
				}
			}
			wood[start].flags=0;
			finish++;
			minWidth=wood[start].w;


			for(int i=1;i<n;i++){
				if(wood[i].flags && wood[i].w>=minWidth){
					wood[i].flags = 0;
					minWidth=wood[i].w;	
					finish++;
				}
			}
			setup_time++;
		}
		printf("%d\n",setup_time);
	}
	return 0;
}
