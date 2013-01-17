/*
 * poj2833 The Average
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


int max[10+2]; //min heap contains the greatest n1 ones;
int min[10+2]; //max heap contains the least n2 ones
int buf[20+1];

int compare(const void *a,const void* b)
{
	return *(int*)a - *(int*)b;
}

void buildMaxHeap(int a[],int n)
{
	int tmp;
	int j;
	for(int i=2;i<=n;i++){
		j=i;
		while(j>1){
			if(a[j]>a[j/2]){
				tmp = a[j/2];
				a[j/2] = a[j];
				a[j] = tmp;
				j/=2;
				continue;
			}
			else
				break;
		}
	}
}
void maintainMaxHeap(int a[],int n) //a[1] is not the greastest one in heap. balance it
{
	int key=a[1];
	int j = 1;
	int k;
	while(j<=n/2){
		if(2*j+1 <=n){
			if(a[2*j] > a[2*j+1])
				k=2*j;
			else
				k=2*j+1;
		}else {
			k = 2*j;
		}
		if(key > a[k])
			break;
		else{
			a[j] = a[k];
			j=k;
		}
	}
	a[j] = key;
}

void buildMinHeap(int a[],int n)
{
	int tmp;
	int j;
	for(int i=2;i<=n;i++){
		j=i;
		while(j>1){
			if(a[j]<a[j/2]){
				tmp = a[j/2];
				a[j/2] = a[j];
				a[j] = tmp;
				j/=2;
				continue;
			}
			else
				break;
		}
	}
}
void maintainMinHeap(int a[],int n) //a[1] is not the least one in heap. balance it
{
	int key=a[1];
	int j = 1;
	int k;
	while(j<=n/2){
		if(2*j+1 <=n){
			if(a[2*j] < a[2*j+1])
				k=2*j;
			else
				k=2*j+1;
		}else {
			k = 2*j;
		}
		if(key < a[k])
			break;
		else{
			a[j] = a[k];
			j=k;
		}
	}
	a[j] = key;
}
int main33()
{
	int a[]={0,1,2,3,4,5,6,7,8,9};
	buildMinHeap(a,9);
	for(int i=0;i<9;i++){
		printf("%d,",a[1]);
		a[1] = a[9-i];
		maintainMinHeap(a,8-i);
	}
	printf("\n");
	return 0;
}



int main()
{
	int n1,n2,n;
	int n11,n22;
	long long sum;
	float result;
	int tmp;
	while(1){
		scanf("%d%d%d",&n1,&n2,&n);
		if(n1+n2+n == 0)
			break;
		result = 0.0;
		sum = 0;
		n11 = n22 =0;
		//for(int i=0;i<n1+n2;i++){
			//scanf("%d",&tmp);
			//if(n11<n1){
				//max[++n11] = tmp;
				//maintainMinHeap(max,n11);
			//}
			//else if (n22<n2){
				//if(tmp > max[1]){
					//min[++n22] = max[1];
					//maintainMaxHeap(min,n22);
					//max[1] = tmp;
					//maintainMinHeap(max,n11);
				//}
				//else {
					//min[++n22] = tmp;
					//maintainMaxHeap(min,n22);
				//}
			//}
		//}
		for(int i=0;i<n1+n2;i++){
			scanf("%d",buf+i);
		}
		qsort(buf,n1+n2,sizeof(buf[0]),compare);
		for(int i=0;i<n2;i++)
			min[i+1] = buf[i];
		for(int i=0;i<n1;i++)
			max[i+1] = buf[i+n2];
		buildMinHeap(max,n1);
		buildMaxHeap(min,n2);
		for(int i=n1+n2;i<n;i++){
			scanf("%d",&tmp);
			if(tmp > max[1]){
				sum += max[1];
				max[1] = tmp;
				maintainMinHeap(max,n1);
			}
			else if(tmp < min[1]){
				sum += min[1];
				min[1] = tmp;
				maintainMaxHeap(min,n2);
			}
			else
				sum+= tmp;
		}
		//result = sum /(float)(n-n1-n2);
		//printf("%.6f\n",result);
		result = (float)sum;
		printf("%6f\n", (double)result/(n-n1-n2));
	}
	return 0;
}
