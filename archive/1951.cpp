/*
 * poj1951 Extra Krunch
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


int compare(const void* a,const void* b)
{
	return 0;
}

//qsort(a,n,sizeof(a[0]),compare);
char buf[71];
char ascii[128+1];
char out[80];
char final[80];
int main()
{
	int length;
	int index=0;
	int flags_start,flags_blank;
	int j;
	ascii['A']=1;
	ascii['E']=1;
	ascii['I']=1;
	ascii['O']=1;
	ascii['U']=1;

	scanf("%[^\n]",buf);
	//gets(buf);
	length= strlen(buf);
	for(int i=0;i<length;i++){
		if(buf[i]< 'A' || ascii[buf[i]]!=1)
			out[index++] = buf[i];
		ascii[buf[i]]=1;
	}
	
	flags_start = flags_blank =0;
	j=0;
	for(int i=0;i<index;i++){
		if(out[i] == ' ' && flags_start==0)
			continue;
		if(out[i] ==' ' && flags_start==1){
			flags_blank=1;
			continue;
		}
		if(out[i]!= ' '){
			if(flags_start==0)
				flags_start=1;
			if(flags_blank==1 && (out[i]< 'A')){ // , . ?
				flags_blank=0;
			}
			if(flags_blank)
				final[j++] = ' ';
			final[j++]=out[i];
			flags_blank=0;
		}
	}
	final[j] = '\0';
	printf("%s\n",final);
	return 0;
}
