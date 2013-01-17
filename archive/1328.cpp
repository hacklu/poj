/*
 * poj1328  Radar Installation
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

struct pointer{
	int x;
	int y;
}islands[1000+1];

int compare(const void* a,const void* b)
{
	float t= (*(float*)a) - (*(float*)b);
	if(t>0)
		return 1;
	if(t==0)
		return 0;
	else
		return -1;
}

//qsort(a,n,sizeof(a[0]),compare);

float radar[1000][2];

void calculate(struct pointer p,int d,float *ret)
{
	float tmp = sqrt(d*d - p.y * p.y);
	ret[0] = p.x - tmp;
	ret[1] = p.x + tmp;
}

int main()
{
	int n,d;
	int fail;
	int result;
	int test_case=0;

	while(scanf("%d%d",&n,&d),n){
		test_case++;
		fail=0;
		result=1;
		for(int i=0;i<n;i++)
			scanf("%d%d",&islands[i].x,&islands[i].y);
		//qsort(islands,n,sizeof(islands[0]),compare);

		for(int i=0;i<n;i++){
			if(islands[i].y>d){
				fail = 1;
				break;
			}
			calculate(islands[i],d,radar[i]);
		}

		if(fail)
			result=-1;
		else{
			qsort(radar,n,sizeof(radar[0]),compare);

			float cur[2];
			cur[0] = radar[0][0];
			cur[1] = radar[0][1];
			for(int i=1;i<n;i++){
				if(radar[i][0] > cur[1]){ //  (A B) [C D]
					cur[0] = radar[i][0];
					cur[1] = radar[i][1];
					result++;
				}
				//else if(radar[i][0] == cur[1]){   //(A B) [B D]
					//cur[0] = cur[1];
				//}
				//else if(radar[i][0] >= cur[0] && radar[i][1] >= cur[1]){ //(A [C B) D]
					//cur[0] = radar[i][0];
				//}
				//else { // (A [C D] B)
					//cur[0] = radar[i][0];
					//cur[1] = radar[i][1];
				//}
				else { // ( ) Union ( )
					cur[0] = radar[i][0];
					cur[1] = (cur[1] <radar[i][1])?(cur[1]):(radar[i][1]);
				}
			}
		}
		printf("Case %d: %d\n",test_case,result);
	}
	return 0;
}
