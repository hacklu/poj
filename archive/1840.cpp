#include <stdlib.h>
#include <stdio.h>
#include <math.h>

const int max_10000=14983;

int memory[100*100+5000];

int myhash(long value)
{
	return (abs(value)%max_10000);
}

struct hash_node{
	long value;
	int next;
}my_node[100*100+5000];

int index;
void addkey(long value)
{
	int key = (abs(value)%max_10000) ;
	if(memory[key]==0){
		memory[key]=index;
		my_node[index].value = value;
		index++;
	}else {
		int next = memory[key];
		my_node[index].value = value;
		my_node[index].next = next;
		memory[key] = index;
		index++;
	}
}

int main()
{
	index=1;
	int result = 0;
        int a1,a2,a3,a4,a5;
	int x1,x2,x3,x4,x5;
        scanf("%d%d%d%d%d",&a1,&a2,&a3,&a4,&a5);

	long v=0;
	int k=0;
	for(x1=-50;x1<=50;x1++){
		if(x1==0)
			continue;
			for(x2=-50;x2<=50;x2++){
				if(x2==0)
					continue;
				v= x1*x1*x1*a1 + x2*x2*x2*a2;
				addkey(v);
			}
	}

	int t=0;
	for(x3=-50;x3<=50;x3++){
		if(x3==0)
			continue;
		for(x4=-50;x4<=50;x4++){
			if(x4==0)
				continue;
			for(x5=-50;x5<=50;x5++){
				if(x5==0)
					continue;
				v = x3*x3*x3*a3 + x4*x4*x4*a4 + x5*x5*x5*a5;
				//v = 0 - v ;
				k = myhash(v);
				if(memory[k] ==0)
					continue;
				else{
					int cur = memory[k];
					do{
						if(my_node[cur].value==-v){
							result++;
							cur = my_node[cur].next;
						}
						else
							cur = my_node[cur].next;
					}while(cur!=0);
				}
	//printf("%d\n",t++);	
			}
		}
	}

	printf("%d\n",result);
}
					
