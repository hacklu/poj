#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
using namespace std;

string getR(string s)
{
	string r;
	int pos;
	pos = s.find_first_of(' ');
	r=s.substr(0,pos);
	return r;

}
int getN(string s)
{
	string r;
	int pos;
	pos = s.find_last_of(' ');
	r=s.substr(pos+1);
	return atoi((const char*)r.c_str());
}

string right_padding_zero(string s,int loop)
{
	while(loop--)
		s+="0";
	return s;
}
string left_padding_zero(string s,int loop)
{
	while(loop--)
		s ="0" +s;
	return s;
}

///////////////////////////////////////
class bigNum
{
public:
	string s;
	unsigned int dot;
	bigNum add(bigNum l,bigNum r);
	bigNum muti(bigNum l,bigNum r);
	string add_basic(string l,string r);
	string muti_basic(string l,string r);
};


inline string convert(int a)
{
	switch(a)
	{
		case 0:return "0";
		case 1:return "1";
		case 2:return "2";
		case 3:return "3";
		case 4:return "4";
		case 5:return "5";
		case 6:return "6";
		case 7:return "7";
		case 8:return "8";
		case 9:return "9";
	}
}

inline int atoi2(const char c)
{
	switch(c)
	{
		case '0':return 0;
		case '1':return 1;
		case '2':return 2;
		case '3':return 3;
		case '4':return 4;
		case '5':return 5;
		case '6':return 6;
		case '7':return 7;
		case '8':return 8;
		case '9':return 9;
	}
}

void show_bigNum(bigNum  big_num)
{
	int length=big_num.s.length();
	string s1,s2;
	int l;
	s1 = big_num.s.substr(0,length-big_num.dot);
	s2 = big_num.s.substr(length-big_num.dot);
	l = s2.length();
	while(l)
	{
		if(s2.at(l-1)=='0')
			s2=s2.substr(0,l-1);
		else
			break;
		l--;
	}
	l = s1.length();
	if(l==1 && atoi2((const char)s1.at(0))==0)
		s1="";
	if(s2.length()>0)
		cout<< s1<<"."<<s2<<endl;
	else
		cout<<s1<<endl;
}
string bigNum::add_basic(string l,string r)
{
	string ret="";
	string tmp;
	int lsize,rsize;
	lsize =l.length();
	rsize =r.length();
	int max=(lsize>rsize)?lsize:rsize;
	l = left_padding_zero(l,(max-lsize+1));
	r = left_padding_zero(r,(max-rsize+1));
	max++;
	int carry=0;
	int a,b,c;
//	stringstream out;
	while(max)
	{
		a=atoi2((const char)l.at(max-1));
		b=atoi2((const char)r.at(max-1));
		c=a+b+carry;
		if(c>9)
		{
			carry=1;
			c=c%10;
		}
		else
			carry=0;


		tmp =convert(c);
		ret=tmp+ ret;
		max--;
	}
//	if(ret.compare(0,1,"0"))
	if(atoi2((const char)ret.at(0))==0)
		return ret.substr(1);
	return ret;
}
string bigNum::muti_basic(string l,string r)
{
	int lsize,rsize;
	string result="0";
	string tmp="";
	string tmp2="";
	lsize =l.length();
	rsize =r.length();
	if(lsize==0 ||rsize==0)
		return "";
	
	int a,b,c;
	int carry =0;
	while(rsize)
	{
		b = atoi2((const char)r.at(rsize-1));
		tmp="";
		tmp2="";
		for(lsize=l.length();lsize>0;lsize--)
		{
			a=atoi2((const char)l.at(lsize-1));
			c=a*b + carry;
			if(c>9)
				{
					carry=c/10;
					c=c%10;
				}
			else
				carry=0;
//			tmp=itoa(c);
			//tmp = "" +c;
			tmp=convert(c);
			tmp2 = tmp + tmp2;
			
		}
		if(carry!=0)
		{
			tmp=convert(carry);
			tmp2 = tmp + tmp2;
			carry=0;
		}
		tmp2 = right_padding_zero(tmp2,r.length()-rsize);
		result = add_basic(result,tmp2);
		rsize--;
	}

	return result;
}

bigNum bigNum::muti(bigNum l,bigNum r)
{

	bigNum ret;
	ret.dot=l.dot+r.dot;
	ret.s=muti_basic(l.s,r.s);
	return ret;
}
bigNum cal2(bigNum r,int n)
{
	bigNum result;
	result.dot =0;
	result.s="1";
	while(n--)
	{
		result = result.muti(result,r);	
	}
	return result;
}

bigNum cal3(bigNum r,int n)
{
	if(n==1)
		return r;
	else if(n==2)
		return r.muti(r,r);
	else if(n%2==0)
	{
		return cal3(cal3(r,2),n/2);
	}
	else
		return r.muti(r,cal3(r,(n-1)));
	
}

int main()
{

	bigNum b1,b2;
	b1.s="12";
	b2.s="11";


	string r;
	int n;
	int dot;
	size_t found;
	string s;
	bigNum bigbig;
	while(getline(cin,s))
	{
		r=getR(s);
		n=getN(s);
		found = r.find('.');
		if(found!=string::npos)
		{
			dot = (int)found;
			bigbig.s=r.substr(0,dot) + r.substr(dot+1);
			dot = (r.length() - (int)found -1);

		}
		else
		{
			bigbig.s =r;
			dot=0;
		}
			bigbig.dot=dot;
//		cout<<"cal:"+bigbig.s+"^";
//		cout<<n;
//		cout<<";dot=";
//		cout<<bigbig.dot;
//		cout<<"\t";
		show_bigNum(cal3(bigbig,n));
//		cal2(bigbig,n);
	}


}
