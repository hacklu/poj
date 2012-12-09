#include <stdlib.h>
#include <string.h>
#include <stdio.h>

using namespace std;

int range[10000+1];

int main()
{
	int N,K;
	int count=0;
	int tmp=0;
	int cow=0;
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++)
	{

		scanf("%d",&cow);
		if(range[cow]==0){
			range[cow]=1;
			tmp++;
		}
		if(tmp==K){
			count++;
			tmp=0;
			memset(range,0,(1+K)*sizeof(int));
		}

	}	
	printf("%d\n",count+1);
	return 0;
}
