#include <stdlib.h>
#include <string.h>
#include <cstdio>

using namespace std;


//long snow[100000+1][7];
//struct snow{
//	long a;
//	long length[6];
//	int nextIndex;
//}my_snow[100000+1];
//long key[100000+1];
//struct hashmap{
//	int index;
//}myhash[100000+1];

char myhash[40000000];

#define set(bitmap,index)  (bitmap[index/8] |= (1<<(index%8)))
#define get(bitmap,index)  (bitmap[index/8] &  (1<<(index%8)))

long simple_sequence(long data[],int start,int flags)
{
	long sum=0;
	long sum2=0;
//	sum += data[start] <<6;
//	sum += data[(start+1)%6]<<5;
	for(int i=0;i<6;i++)
		sum += data[(start+i)%6] << (5-i);
	for(int i=0;i<6;i++)
		sum2+= data[(start+6-i)%6] << (5-i);
	if(flags == 0)
		return (sum<=sum2)?sum:sum2;
	else 
		return (sum>=sum2)?sum:sum2;
}

long hash(long data[])
{
	long min = data[0];
	long max = data[0];
	long summin = -1;
	long summax = -1;
	long tmp;
	for(int i=1;i<6;i++){
		if(data[i] < min)
			min = data[i];
		else if(data[i] > max)
			max = data[i];
	}
	for(int i=0;i<6;i++){
		if(data[i]==min){
				tmp  = simple_sequence(data,i,0);
			if(summin == -1)
				summin = tmp;
		       	else
				summin = (tmp <summin)?tmp:summin;	
		}
		if(data[i]==max){
				tmp  = simple_sequence(data,i,1);
			if(summax == -1)
				summax = tmp;
		       	else
				summax = (tmp <summax)?tmp:summax;	
		}
	}
	return (summin<<1)|summax ;
}

int main()
{
	int snow_count;
	scanf("%d",&snow_count);
	long tmp[6];

	for(int abc=0;abc<snow_count;abc++)
	{
		scanf("%ld%ld%ld%ld%ld%ld",tmp+0,tmp+1,tmp+2,tmp+3,tmp+4,tmp+5);
		
	//	simple_sequence(tmp,6);

	//	memcpy(snow[abc],tmp,sizeof(long)*6);	

		//long key = hash(snow[abc],6);
		long key = hash(tmp);
		if(get(myhash,key) != 0 ){
			printf("Twin snowflakes found.\n");
			return 0;
		}
		else
			set(myhash,key);
	}
	printf("No two snowflakes are alike.\n");	

	return 0;
}
