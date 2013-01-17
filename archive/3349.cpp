/*
 * poj3349  Snowflake Snow Snowflakes
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int hash(long data[])
{
	return ((data[0] + data[2] +data[4]) | (data[1] + data[3] + data[5]))%99991;
}

long snow[100000+1][6];
struct hash_node{
	int index; //index in snow[]
	int next;// 0 means null
}my[100000+2];

int hashlist[100000+2];

int compare(int index,int cmp)
{
	int ret=-1;
	int x=my[index].index;
	int y=my[cmp].index;
	int i,j;
	for(i=0;i<6;i++){
		for(j=0;j<6;j++){
			if(snow[x][j] != snow[y][(i+j)%6])
				break;
		}
		if(j==6)
			return 0;
		for(j=0;j<6;j++){
			if(snow[x][j] != snow[y][(i-j+6)%6])
				break;
		}
		if(j==6)
			return 0;
	}
	return ret;
}
int main()
{
	int snow_count;
	scanf("%d",&snow_count);

	int key;
	int index=1;
	for(int i=0;i<snow_count;i++)
	{
		for(int j=0;j<6;j++)
			scanf("%ld",snow[i]+j);
		key = hash(snow[i]);
		my[index].index=i;
		my[index].next = hashlist[key];
		hashlist[key] = index;
		index ++;
	}
	for(int i=0;i<100000;i++){
		if(hashlist[i]){
			for(int index = hashlist[i];my[index].next >0;index=my[index].next){
				int cmp =index;
				while(cmp=my[cmp].next,cmp>0){
					if(0==compare(index,cmp))
						goto like;
				}
			}
		}
	}

	printf("No two snowflakes are alike.\n");	
	return 0;
like:
	printf("Twin snowflakes found.\n");
	return 0;
}
