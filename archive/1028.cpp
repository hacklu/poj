#include <string>
#include <iostream>
#include <cstring>
using namespace std;
class stack
{

	int index;
	int length;
	long *data;
	string str[200];
	int i;
public:
	stack(int length)
	{
		data = new long[length];
		this->length = length;
		if(data)
			memset(data,0,length);
		index =0;
		i=0;
	}
	void destroy()
	{
		index =0;
	}
	~stack()
	{
		if(data)
			delete data;
	}
	long pop()
	{
		if(index ==0)
			return 0;

		return data[--index];

	}
	void push(long d)
	{
		data[index++] =d;

	}
	string get()
	{
		long addr = pop();
		if(!addr)
			return "";
		else 
			return *(string*)addr;
	}

	void put(string str)
	{

		this->str[i] = str;
		push((long)&(this->str[i]));
		i++;
	}
};

int main()
{
	string tmp;
	stack back(200);
	stack forward(200);
	string current = "http://www.acm.org/";
	while(getline(cin,tmp))
	{
		if(tmp.compare(0,2,"VI")==0)
		{
			tmp = tmp.substr(6);
			back.put(current);
			current  = tmp;
			cout <<current <<endl;
			forward.destroy();


		}
		else if(tmp.compare(0,2,"BA")==0)
		{
			tmp = back.get();
			if(tmp.length() ==0)
			{
				cout <<"Ignored"<<endl;
				continue;
			}
			forward.put(current);
			current = tmp;
			cout <<current <<endl;

		}
		else if (tmp.compare(0,2,"FO")==0)
		{
			tmp = forward.get();
			if(tmp.length() ==0)
			{
				cout <<"Ignored"<<endl;
				continue;
			}
			back.put(current);
			current = tmp;
			cout <<current <<endl;


		}
		else //quit
		{

		}
	}
	return 0;
}


