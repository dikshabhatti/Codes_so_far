#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
struct proc{
	int pid;//Process ID
	int at;//Arrival Time
	int bt;//Burst Time
	int rbt;//Remaining Burst Time
	int wt;//Waiting Time
	int tat;//Turn around Time
	int ft;//Finishing Time
	int pty;//Priority
};
int mean(vector<proc> x)
{
	int avg=0;
	for(int i=0;i<(int)x.size();i++)
	{
		avg+=x[i].rbt;
	}
	avg/=(int)x.size();
	return avg;
}
bool compare(const proc pro1,const proc pro2)
{
	if(pro1.rbt!=pro2.rbt)
	{
		return pro1.rbt<pro2.rbt;
	}
	else
	{
		return pro1.at<pro2.at;
	}
}
int median(vector<proc> x)
{
	sort(x.begin(),x.end(),compare);
	if(x.size()%2)
	{
		return x[x.size()/2].rbt;
	}
	else
	{
		return (x[x.size()/2].rbt+x[x.size()/2-1].rbt)/2;
	}
}
int time_quantum(vector<proc> x)
{
	if(x.size()==0)
		return 0;
	if(median(x)==mean(x))
	{
		return (mean(x)+2)/3;
	}
	else if(mean(x)>median(x))
	{
		return (mean(x)-median(x)+2)/3;
	}
	else
	{
		return (median(x)-mean(x)+2)/3;
	}
}
int main()
{
	int i,n;
	printf("\t\t\t---OPTIMUM SCHEDULING ALGORITHM---");
	printf("\n Enter the number of processes: ");
	freopen("input.txt","r",stdin);
	scanf("%d",&n);
	vector<proc> process(n);//Storing all the processes
	vector<proc> final(0);
	vector<proc> sys_proc(0);//System Processes
	vector<proc> inter_proc(0);//Interactive Processes
	vector<proc> other_proc(0);//Other Processes
	printf("Enter Process ID, Priority, Process Arrival Time and Process Burst Time respectively\n");
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&process[i].pid,&process[i].pty,&process[i].at,&process[i].bt);
		process[i].rbt=process[i].bt;
		process[i].tat=0;
		process[i].wt=0;
		process[i].ft=process[i].at;
		if(process[i].pty==1)
		{
			sys_proc.push_back(process[i]);
		}
		else if(process[i].pty==2)
		{
			inter_proc.push_back(process[i]);
		}
		else
		{
			other_proc.push_back(process[i]);
		}
	}
	fclose(stdin);
	int Queue_size[3]={2,4,8};//Size of 3 queues
	vector<proc> Queue1(0);
	vector<proc> Queue2(0);
	vector<proc> Queue3(0);
	vector<proc>::iterator it;
	int rmv;//For storing processes to be removed
	int tq[3];//Time quanta of all 3 queues
	int completed=0;//Counter storing number of complete processes
	int tm=0;//Current Time
	int ch=0;//Counter to know which queue is running
	int h;//Number of filled elements
	while(completed<n)
	{
		//Calculating Time Quantum of 3 Queue Levels
		tq[0]=time_quantum(process);
		tq[1]=2*tq[0];
		tq[2]=2*tq[1];
		switch(ch)
		{
			//QUEUE 1
			case 0:
			case 1:
			case 2: 
			case 3:
				//Filling of Queue 1
				Queue1.clear();
				rmv=0;
				h=0;
				for(i=0;i<(int)sys_proc.size() && h<Queue_size[0];i++,h++)
				{
					Queue1.push_back(sys_proc[i]);
					rmv+=1;
				}
				for(i=0;i<rmv;i++)
				{
					sys_proc.erase(sys_proc.begin());
				}
				if(h<Queue_size[0])
				{
					rmv=0;
					for(i=0;i<(int)inter_proc.size() && h<Queue_size[0];i++,h++)
					{
						Queue1.push_back(inter_proc[i]);
						rmv+=1;
					}		
					for(i=0;i<rmv;i++)
					{
						inter_proc.erase(inter_proc.begin());
					}	
					if(h<Queue_size[0])
					{
						rmv=0;
						for(i=0;i<(int)other_proc.size() && h<Queue_size[0];i++,h++)
						{
							Queue1.push_back(other_proc[i]);
							rmv+=1;
						}
						for(i=0;i<rmv;i++)
						{
							other_proc.erase(other_proc.begin());
						}
					}
				}
				//Executing Queue 1
				for(i=0;i<(int)Queue1.size();i++)
				{	
					if(tq[0]<Queue1[i].rbt)
					{
						Queue1[i].rbt-=tq[0];
						Queue1[i].wt+=tm-Queue1[i].ft;
						//cout<<"->"<<tm<<" "<<Queue1[i].pid<<" "<<Queue1[i].rbt<<" "<<Queue1[i].wt<<endl;
						tm+=tq[0];
						Queue1[i].ft=tm;
						//If Process remains incomplete it is send back to their respective priority queues
						if(Queue1[i].pty==1)
						{
							sys_proc.push_back(Queue1[i]);
						}
						
						else if(Queue1[i].pty==2)
						{
							inter_proc.push_back(Queue1[i]);
						}
						else
						{
							other_proc.push_back(Queue1[i]);
						}
					}
					else
					{
						Queue1[i].wt+=tm-Queue1[i].ft;
						//cout<<"->"<<tm<<" "<<Queue1[i].pid<<" 0 "<<Queue1[i].wt<<endl;
						tm+=Queue1[i].rbt;
						Queue1[i].rbt=0;
						Queue1[i].ft=tm;
						Queue1[i].tat=tm-Queue1[i].at;
						final.push_back(Queue1[i]);//Putting into vector of Completed Processes
						completed+=1;
					}
				}
				break;
				
			//QUEUE 2	
			case 4:
			case 5:
				//Filling of Queue 2
				Queue2.clear();
				rmv=0;
				h=0;
				for(i=0;i<(int)inter_proc.size() && h<Queue_size[1];i++,h++)
				{
					Queue2.push_back(inter_proc[i]);
					rmv+=1;
				}	
				for(i=0;i<rmv;i++)
				{
					inter_proc.erase(inter_proc.begin());
				}	
				if(h<Queue_size[1])
				{
					rmv=0;
					for(i=0;i<(int)other_proc.size() && h<Queue_size[1];i++,h++)
					{
						Queue2.push_back(other_proc[i]);
						rmv+=1;
					}
					for(i=0;i<rmv;i++)
					{
						other_proc.erase(other_proc.begin());
					}
				}
				
				//Executing Queue 2
				for(i=0;i<(int)Queue2.size();i++)
				{	
					if(tq[1]<Queue2[i].rbt)
					{
						Queue2[i].rbt-=tq[1];
						Queue2[i].wt+=tm-Queue2[i].ft;
						//cout<<"->"<<tm<<" "<<Queue2[i].pid<<" "<<Queue2[i].rbt<<" "<<Queue2[i].wt<<endl;
						tm+=tq[1];
						Queue2[i].ft=tm;
						//If Process remains incomplete it is send back to their respective priority queues
						if(Queue2[i].pty==2)
						{
							inter_proc.push_back(Queue2[i]);
						}
						else if(Queue2[i].pty==3)
						{
							other_proc.push_back(Queue2[i]);
						}
						else
						{
							cout<<"Wrong Priority Process in Queue2\n";
						}
					}
					else
					{
						Queue2[i].wt+=tm-Queue2[i].ft;
						//cout<<"->"<<tm<<" "<<Queue2[i].pid<<" 0 "<<Queue2[i].wt<<endl;
						tm+=Queue2[i].rbt;
						Queue2[i].rbt=0;
						Queue2[i].ft=tm;
						Queue2[i].tat=tm-Queue2[i].at;
						final.push_back(Queue2[i]);//Putting into vector of Completed Processes
						completed+=1;
					}
				}
				break;
		
			//QUEUE 3
			case 6:					
				//Filling of Queue 3
				Queue3.clear();
				rmv=0;
				for(i=0;i<(int)other_proc.size() && i<Queue_size[2];i++)
				{
					Queue3.push_back(other_proc[i]);
					rmv+=1;
				}
				for(i=0;i<rmv;i++)
				{
					other_proc.erase(other_proc.begin());
				}
				//Executing Queue 3
				for(i=0;i<(int)Queue3.size();i++)
				{	
					if(tq[2]<Queue3[i].rbt)
					{
						Queue3[i].rbt-=tq[2];
						Queue3[i].wt+=tm-Queue3[i].ft;
						//cout<<"->"<<tm<<" "<<Queue3[i].pid<<" "<<Queue3[i].rbt<<" "<<Queue3[i].wt<<endl;
						tm+=tq[2];
						Queue3[i].ft=tm;
						//If Process remains incomplete it is send back to their respective priority queues
						if(Queue3[i].pty==3)
						{
							other_proc.push_back(Queue3[i]);
						}
						else
						{
							cout<<"Wrong Priority Process in Queue3\n";
						}
					}
					else
					{
						Queue3[i].wt+=tm-Queue3[i].ft;
						//cout<<"->"<<tm<<" "<<Queue1[i].pid<<" 0 "<<Queue1[i].wt<<endl;
						tm+=Queue3[i].rbt;
						Queue3[i].rbt=0;
						Queue3[i].ft=tm;
						Queue3[i].tat=tm-Queue3[i].at;
						final.push_back(Queue3[i]);//Putting into vector of Completed Processes
						completed+=1;
					}
				}
				break;
		}
		process.clear();//Updating the initial process list
		for(it=sys_proc.begin();it!=sys_proc.end();it++)
		{
			//cout<<it->pid<<" ";
			process.push_back(*it);
		}		
		//cout<<endl;
		for(it=inter_proc.begin();it!=inter_proc.end();it++)
		{
			//cout<<it->pid<<" ";
			process.push_back(*it);
		}
		//cout<<endl;
		for(it=other_proc.begin();it!=other_proc.end();it++)
		{
			//cout<<it->pid<<" ";
			process.push_back(*it);
		}
		//cout<<endl;
		ch=(ch+1)%7;
	} 
	int twt=0,ttat=0;
	printf("\n\n\t\t\t---OPTIMUM ALGORITHM SCHEDULING---");
	printf("\n\n Process Priority Arrival  Burst   Waiting  Finishing Turnaround\n");
	printf("%5s         %9s %7s %10s %8s %9s\n\n", "id", "time", "time", "time", "time", "time");
	for(i = 0; i < n; i++)
	{

		twt+=final[i].wt;
		ttat+=final[i].tat;
		printf("%5d %5d %8d %7d  %8d %10d %9d", final[i].pid, final[i].pty, final[i].at,
						  final[i].bt,
						  final[i].wt , final[i].ft,
						  final[i].tat);

		printf("\n\n");
	}
	printf("Average Waiting Time: %lf\n",(double)twt/n);
	printf("Average Turn Aroud Time: %lf\n",(double)ttat/n);

    return 0;
}
