#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;
int compare(int a,int b)
{
	return (*(int*)a-*(int*)b);
}
void insert(int a[],int begin,int end,int key)
{
	int i=begin;
	for(;i<end;i++)
	{
		if(a[i]<key)
			a[i-1]=a[i];
		else
			break;
	}
	a[i-1]=key;
}
int main()
{
	string s;
	getline(cin,s);
	int count = atoi(s.c_str());
	int *data = new int[count];
	if(!data)
		return -1;
	int i=0;
	int sum=0;
	while(getline(cin,s))
	{
		data[i] = atoi(s.c_str());
		//sum += data[i];
		i++;
	}
	long long charge=0;
	qsort(data,count,sizeof(data[0]),(int(*)(const void *,const void *))compare);
	for(i=0;i<count-1;i++)
	{
		sum = data[i]+data[i+1];
		charge+=sum;
		//void insert(int a[],int begin,int end,int key)
		insert(data,i+2,count,sum);
	}

	cout<<charge<<endl;
	return 0;

}
