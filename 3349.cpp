#include <stdlib.h>
#include <string.h>
#include <cstdio>

using namespace std;


long snow[100000+1][7];
//struct snow{
//	long a;
//	long length[6];
//	int nextIndex;
//}my_snow[100000+1];
//long key[100000+1];
struct hashmap{
	int index;
}myhash[100000+1];

long simple_sequence(long data[],int start)
{
	long sum=0;
	long sum2=0;
//	sum += data[start] <<6;
//	sum += data[(start+1)%6]<<5;
	for(int i=0;i<6;i++)
		sum += data[(start+i)%6] << (5-i);
	for(int i=0;i<6;i++)
		sum2+= data[(start+6-i)%6] << (5-i);
	return (sum<=sum2)?sum:sum2;
}

long hash(long data[],int length)
{
	long min = data[0];
	long sum = -1;
	long tmp;
	for(int i=1;i<6;i++)
		min = (data[i]<min)?data[i]:min;
	for(int i=0;i<6;i++){
		if(data[i]==min){
				tmp  = simple_sequence(data,i);
			if(sum == -1)
				sum = tmp;
		       	else
				sum = (tmp <sum)?tmp:sum;	
		}
	}
	return sum;
}

int main()
{
	int snow_count;
	scanf("%d",&snow_count);

	for(int abc=0;abc<snow_count;abc++)
	{
		long tmp[6];
		scanf("%ld%ld%ld%ld%ld%ld",tmp+0,tmp+1,tmp+2,tmp+3,tmp+4,tmp+5);
		
	//	simple_sequence(tmp,6);

	//	memcpy(snow[abc],tmp,sizeof(long)*6);	

		//long key = hash(snow[abc],6);
		long key = hash(tmp,6);
		int mod = key %(100000+1);
		myhash[mod].index++;
		if(myhash[mod].index>1){
			printf("Twin snowflakes found.\n");
			return 0;
		}
	}
	printf("No two snowflakes are alike.\n");	

	return 0;
}
