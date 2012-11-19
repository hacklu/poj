#include <stdlib.h>
#include <string>
#include <iostream>
#include <string.h>
#include <cstdio>

using namespace std;
const int problem_count = 25;
struct team{
	int teamno;
	int solved;
	long totaltime;
//	int hassubmit;
};
struct team_work{
	int isaccept; //1 ac. 0 not
	long time;
	long firstaccept;
};
int compare_solved(void *a,void *b)
{
	int ret = (((team*)b)->solved - ((team*)a)->solved);
	if(ret == 0){
			ret =  (((team*)a)->totaltime - ((team*)b)->totaltime);
	}
	if(ret ==0)
		ret = ((team*)a)->teamno - ((team*)b)->teamno;
	return ret;

}
int compare_totaltime(void *a,void *b)
{
	return (((team*)a)->totaltime - ((team*)b)->totaltime);
}

int c[1001],p[1001],r[1001];
long t[1001];
int main()
{
	int C,N;
	int ci,pi,ri;
	long ti;
	//cin>>count>>windowSize;
	scanf("%d %d",&C,&N);
	struct team *te = new team[C+2];
	memset(te,0,sizeof(team) * (C+2));
	struct team_work (*tw)[problem_count] = new team_work[C+2][problem_count];
	memset(tw,0,sizeof(team_work)*problem_count*(2+C));

	for(int abc=0;abc<N;abc++)
	{
		scanf("%d%d%ld%d",&ci,&pi,&ti,&ri);
		c[abc] = ci;
		p[abc] = pi;
		t[abc] = ti;
		r[abc] = ri;
		if(ri){
			tw[ci][pi].isaccept = 1;
			if(tw[ci][pi].firstaccept==0)
				tw[ci][pi].firstaccept = ti;
			else
				tw[ci][pi].firstaccept = (tw[ci][pi].firstaccept < ti)?(tw[ci][pi].firstaccept):ti;
		}
	}
	
	for(int i=0;i<N;i++)
	{
		ci = c[i];
		pi = p[i];
		ti = t[i];
		ri = r[i];

//		if(te[ci].hassubmit == 0)
//			te[ci].hassubmit =1;

		if(ri)
			continue;
		else if(tw[ci][pi].isaccept == 0)
			continue;
		else{
			if(ti < tw[ci][pi].firstaccept)
				tw[ci][pi].time += 20 *60;
		}
	}
	for(int i=1;i<=C;i++){
		te[i].teamno = i;
		for(int j=1;j<problem_count;j++){
			if(tw[i][j].isaccept){
				te[i].totaltime += tw[i][j].time;
				te[i].totaltime += tw[i][j].firstaccept;
				te[i].solved ++;
			}
		}
	}
	
	qsort(&te[1],C,sizeof(te[0]),(int(*)(const void*,const void*))compare_solved);

	for(int i=1;i<=C;i++){
		printf("%d ",te[i].teamno);
	}
	printf("\n");
	return 0;
}
