#include <iostream>
#include <cstring>
using namespace std;

int d(int generator)
{
	if(generator<10)
		return generator+generator;
	else if(generator <100)
		return (generator + generator/10 + (generator%10));
	else if(generator <1000)
		return (generator + generator/100 + (generator%100)/10 + generator%10);
	else if(generator <10000)
		return (generator + generator/1000 + (generator%1000)/100 + (generator%100)/10 + generator%10);
	else return 0;
}

//class queue
//{
//public:
//	const int MAX=40;
//	int front;
//	int rear;
//	int q[MAX];
//	queue(){front=0;rear=0;memset(q,0,MAX*sizeof(int));}
//	int get(){
//		if(front=rear)
//			return 0;
//		else
//		{
//			int tmp = q[front];
//			front = (front+1)%MAX;
//			return tmp;
//		}
//	}
//	void put(int data){
//		q[rear] = data;
//		rear = (rear+1)%MAX;
//	}
//};

#define set(bitmap,index)  (bitmap[index/8] |= (1<<(index%8))) 
#define get(bitmap,index)  (bitmap[index/8] &  (1<<(index%8)))
//use bitmap
int main()
{
	char * bitmap = new char[1250];
	if(!bitmap)
		return -1;
	memset(bitmap,0,1250*sizeof(char));
	for(int i=1;i<10001;i++)
		set(bitmap,d(i));
	for(int i=1;i<10001;i++)
		if(get(bitmap,i)==0)
			cout<<i<<endl;
}

