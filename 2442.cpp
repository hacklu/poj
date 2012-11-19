#include <stdlib.h>
#include <string>
#include <iostream>
#include <string.h>
#include <cstdio>

using namespace std;
int length;
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
int compare(void *a,void *b)
{
	return (*(int*)a - *(int*)b);
}
int a[100+100][2000+100];
int main()
{
	int caseNum,m,n;
	int sum =0;
	int i,j;
	//cin>>count>>windowSize;
	scanf("%d",&caseNum);
	for(int abc=0;abc<caseNum;abc++)
	{
		scanf("%d%d",&m,&n);
		sum =0;
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
				scanf("%d",&a[i][j]);
			a[i][j]=0;
			qsort(a[i],n,sizeof(a[0][0]),(int(*)(const void*,const void*))compare);
			sum += a[i][0];
		}

		for(int i=0;i<n;i++)
		{
			printf("%d ",sum);
			int diff = 1000000;
			int tmp;
			int tmp_index;
			int min_index;
			int flags=1;
			for(int j=0;j<m;j++)
			{
				tmp_index = a[j][n];
				if(tmp_index ==n-1)
					continue;
				tmp = a[j][tmp_index+1] - a[j][tmp_index];
				if(tmp ==0)
				{
					a[j][n]++;
					sum+= tmp;
					flags=0;
					break;
				}
				if(tmp <diff)
				{
					diff = tmp;
					min_index = j;
				}
			}
			if(flags==1)
			{
				sum += diff;
				a[min_index][n]++;
			}
		}

		printf("\n");
	}	
	return 0;
}
