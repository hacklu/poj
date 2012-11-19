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
char pre[30];
char in[30];
char post[30];
int len;
int find(char* str,char c)
{
	for(int i=0;i<26;i++)
	{
		if(str[i] == c)
			return i;
	}
	return -1;
}
void solve(int pre_s,int len1,int in_s,int len2)
{
	if(len1<1)
		return;
	post[--len] = pre[pre_s];
	char root=pre[pre_s];
	int pos=find(in+in_s,root);
	//right child
	if(len1-pos-1 >0)
	solve(pre_s+pos+1,len1-pos-1,in_s+pos+1,len1-pos-1);
	//left child
	if(pos>0)
	solve(pre_s+1,pos,in_s,pos);
}
int main()
{
	while(cin>>pre>>in)
	{
		memset(post,0,30);
		len = strlen(pre);
		solve(0,len,0,len);
		cout<<post<<endl;
	}
	return 0;
}
