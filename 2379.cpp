#include <stdlib.h>
#include <string>
#include <iostream>
#include <string.h>
#include <cstdio>

using namespace std;
const int problem_count = 21;
struct team{
	int teamno;
	int solved;
	int totaltime;
};
struct team_work{
	int isaccept; //1 ac. 0 not
	int time;
};
int compare_solved(void *a,void *b)
{
	int ret = (((team*)a)->solved - ((team*)b)->solved);
	if(ret == 0)
		return (((team*)a)->totaltime - ((team*)b)->totaltime);
	else
		return ret;

}
int compare_totaltime(void *a,void *b)
{
	return (((team*)a)->totaltime - ((team*)b)->totaltime);
}

int main()
{
	int C,N;
	int i,j;
	int ci,pi,ti,ri;
	//cin>>count>>windowSize;
	scanf("%d %d",&C,&N);
	struct team *t = new team[C+1];
	memset(t,0,sizeof(team) * (C+1));
	struct team_work (*tw)[problem_count] = new team_work[C+1][problem_count];
	memset(tw,0,sizeof(team_work)*problem_count*C);

	for(int abc=0;abc<N;abc++)
	{
		scanf("%d%d%d%d",&ci,&pi,&ti,&ri);
		if(tw[ci][pi].isaccept)
			continue;
		else{
			if(ri){
				tw[ci][pi].isaccept = ri;
				tw[ci][pi].time += ti;
			}
			else
				tw[ci][pi].time += 20 *60;
		}
	}
	for(int i=1;i<=C;i++){
		t[i].teamno = i;
		for(int j=1;j<problem_count;j++){
			if(tw[i][j].isaccept){
				t[i].totaltime += tw[i][j].time;
				t[i].solved ++;
			}
		}
	}
	
	qsort(t,C+1,sizeof(t[0]),(int(*)(const void*,const void*))compare_solved);

	for(int i=1;i<=C;i++){
		printf("%d ",t[i].teamno);
	}
	printf("\n");
	return 0;
}
