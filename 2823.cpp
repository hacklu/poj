#include <stdlib.h>
#include <string>
#include <iostream>
#include <string.h>
#include <cstdio>

using namespace std;
int length;
int cal(char* a)
{
//	int length=strlen(a);
	int c=0;
	for(int i=0;i<length-1;i++)
		for(int j=i+1;j<length;j++)
		{	
			if(a[i]>a[j])
				c++;
		}
	return c;
}
int compare(char* a,char* b)
{
//	return (*(int*)a-*(int*)b);
	return (cal(*(char**)a)-cal(*(char**)b));
}
int selectMin(int a[],int *work,int length)
{
	if(length==1)
		return a[0];
	for(int i=0,j=0;i<length;i+=2,j++)
	{
		if(i+1<length)
		{
		work[j]= a[i]<a[i+1]?a[i]:a[i+1];
		}
		else
			work[j]=a[i];
	}
	return selectMin(work,work,length/2+length%2);
}

int selectMax(int a[],int *work,int length)
{
	if(length==1)
		return a[0];
	for(int i=0,j=0;i<length;i+=2,j++)
	{
		if(i+1<length)
		{
		work[j]= a[i]>a[i+1]?a[i]:a[i+1];
		}
		else
			work[j]=a[i];
	}
	return selectMax(work,work,length/2+length%2);
}
void minHeap(int a[],int start,int *work,int length)
{
	int mid = length/2;
	int tmp;
	for(int i=1;i<=length;i++)
		work[i] = i+start-1;
	for(int i=mid;i>0;i--)
	{
		if(a[work[i]] > a[work[2*i]])
		{
			tmp = work[i];
			work[i] = work[2*i];
			work[2*i] = tmp;
		}
		if(2*i <length && a[work[i]]>a[work[2*i+1]])
		{
			tmp = work[i];
			work[i] = work[2*i+1];
			work[2*i+1] = tmp;
		}
	}

}
void maxHeap(int a[],int start,int *work,int length)
{
	int mid = length/2;
	int tmp;
	for(int i=1;i<=length;i++)
		work[i] = i+start-1;
	for(int i=mid;i>0;i--)
	{
		if(a[work[i]] < a[work[2*i]])
		{
			tmp = work[i];
			work[i] = work[2*i];
			work[2*i] = tmp;
		}
		if(2*i <length && a[work[i]]<a[work[2*i+1]])
		{
			tmp = work[i];
			work[i] = work[2*i+1];
			work[2*i+1] = tmp;
		}
	}

}
#if 0
{
	int mid = length/2;
	int tmp;
	for(int i=mid;i>0;i--)
	{
		if(a[i] < a[2*i])
		{
			tmp = a[i];
			a[i] = a[2*i];
			a[2*i] = tmp;
		}
		if(2*i <length && a[i]<a[2*i+1])
		{
			tmp = a[i];
			a[i] = a[2*i+1];
			a[2*i+1] = tmp;
		}
	}

}
#endif
int main()
{
#if 0
	char ccc[]="ZWQM";
	char bbb[]="DAABEC";
	length=5;
	cout<<cal(ccc)<<endl;
	length=7;
	cout<<cal(bbb)<<endl;
	return -1;
#endif
#if 0
	string s;
	getline(cin,s);
	string s2;
	int pos=0;
	pos = s.find_first_of(' ');
	s2 = s.substr(0,pos);
	
#endif
	int count,windowSize ;
	//cin>>count>>windowSize;
	scanf("%d%d",&count,&windowSize);
	int *data = new int[count];
	int *min = new int[count];
	int *max = new int[count];
	int *work = new int[windowSize+1];
	if(!data || !min || !max ||!work)
		return -1;
	memset(data,count *sizeof(data[0]),0);
	memset(min,count *sizeof(min[0]),0);
	memset(max,count *sizeof(max[0]),0);
	
	int i=0;
//	while(cin>>data[i++])
//		;
	for(int i=0;i<count;i++)
		scanf("%d",(data+i));
	int j,index,timeoutHigh,timeoutLow,low,high;
	j=index=timeoutHigh=timeoutLow=low=high=i=0;
	low = high =0;
	for(int i=0;i<count-windowSize+1;i++)
	{
	//	memcpy(work+1,data+i,windowSize*sizeof(data[0]));
	//	minHeap(data,i,work,windowSize);
		min[i] = selectMin(data+i,work,windowSize);
		max[i] = selectMax(data+i,work,windowSize);

/*
		for(int j=i;j<i+windowSize;j++)
		{
			if(high>= i) // 
			{
				if(data[j] >=data[high])
					high = j;
			}
			else
			{
				high = j;

			}
			if(low >=i)
			{
				if(data[j] <=data[low])
					low = j;	
			}
			else 
			{
				low =j;
			}
		}
		min[i] = data[low];
		max[i] = data[high];
		
*/
	}
	for(int i=0;i<count-windowSize+1;i++)
		printf("%d ",min[i]);
		//cout<<min[i]<<" ";
	cout<<endl;
	for(int i=0;i<count-windowSize+1;i++)
		printf("%d ",max[i]);
		//cout<<max[i]<<" ";
	cout<<endl;
	return 0;
}
