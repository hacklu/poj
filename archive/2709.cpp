/*
 * poj2709  Painter
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void insert_sort(int *a,int length)
{
	for(int i=1;i<length;i++){
		int key = a[i];
		int j=i-1;

		while(j>=0 && a[j]<key ){
			a[j+1] = a[j];
			j--;
		};
		a[j+1] = key;
	}
}

int main()
{
	int N;
	int colors[12];
	int gray;
	int kits=0;
	while(scanf("%d",&N),N){
		kits=0;
		for(int i=0;i<N;i++){
			scanf("%d",colors+i);
		}
		scanf("%d",&gray);

		insert_sort(colors,N);
		kits = (colors[0]+49) /50;
		for(int i=0;i<N;i++)
			colors[i] = kits*50 - colors[i];

		while(gray>0){
			insert_sort(colors,N);
			if(colors[2]>0){ //enough now
				//colors[0] -= colors[2];
				//colors[1] -= colors[2];
				//gray -= colors[2];
				colors[0] --;
				colors[1] --;
				colors[2] --;
				gray --;
			}
			else{
				kits++;
				for(int i=0;i<N;i++)
					colors[i] += 50;
			}
		};
		printf("%d\n",kits);
	}
	return 0;
}
