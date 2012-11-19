#include <stdlib.h>
#include <string>
#include <iostream>
#include <string.h>

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
	string s;
	getline(cin,s);
	string s2;
	int pos=0;
	pos = s.find_first_of(' ');
	s2 = s.substr(0,pos);
	
	//int length = atoi(s2.c_str());
	length = atoi(s2.c_str());
	length++; // NULL-terminal
	s2 = s.substr(pos);
	int count = atoi(s2.c_str());
	char **a = (char**)new long[count];
	char *data = new char[(length)*count];
	if(!data || !a)
		return -1;
	memset(data,length*count,0);
	memset(a,count*sizeof(char*),0);
	int i=0;
	while(getline(cin,s))
	{
		strcpy(data+i*length,s.c_str());
		a[i] = data+i*length;
		i++;
	}
	length --; //fixme!!!
	qsort(a,count,sizeof(a[0]),(int(*)(const void *,const void *))compare);
	for(int j=0;j<count;j++)
		cout<<a[j]<<endl;
	return 0;

}
