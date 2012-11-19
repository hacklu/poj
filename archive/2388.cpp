#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;
int compare(int a,int b)
{
	return (*(int*)a-*(int*)b);
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
		data[i++] = atoi(s.c_str());
	}
	qsort(data,count,sizeof(data[0]),(int(*)(const void *,const void *))compare);
	cout<<data[count/2]<<endl;
	return 0;

}
