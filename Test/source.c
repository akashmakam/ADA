#include<stdio.h>
#include<stdlib.h>
#define MAX 40
int v,adj[MAX][MAX],indegree[MAX],topo[MAX],r,count=0;
int front,rear,queue[MAX];
void in()
{
	for(int i=0;i<v;i++)
	{
		indegree[i]=0;
	}
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			if(adj[j][i]==1)
			{
				indegree[i]++;
			}
		}
	}
}
void topological()
{
	r=0;
	front=0,rear=-1;
	for(int i=0;i<v;i++)
	{
		if(indegree[i]==0)
		{
			queue[++rear]=i;
		}
	}
	while(front<=rear && front<v) 
	{
		int u=queue[front++];
		topo[r++]=u;
		for(int i=0;i<v;i++)
		{
			count++;
		
			if(adj[u][i]==1)
			{
				indegree[i]--;
				
				if(indegree[i]==0)
				{
					
					queue[++rear]=i;
				}
				
				
				
			}
			
			
		}
	
	}
	
	/*if(r!=v)
	{
		printf("Graph is not DAG\n");
		return;
	}
	printf("Topological sorting\n");
	int i;
	for(i=0;i<v-1;i++)
	{
		printf("%c-->",topo[i]+65);
	}
	 printf("%c\n",topo[i]+65);
	 printf("\nOperation count:%d\n",count);*/
}
void tester()
{
	int i,j;
	printf("Enter the number of vertices:");
	scanf("%d",&v);
	printf("Enter Adjacency matrix\n");
	for (i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			scanf("%d",&adj[i][j]);
		}
	}
	printf("Adjacency matrix\n");
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			printf("%d\t",adj[i][j]);
		}
		printf("\n");
	}
	count=0;
	in();
       	topological();
}
void plotter(int c)
{
	FILE *fp3=fopen("srcbest.txt","a");
	FILE *fp2=fopen("srcworst.txt","a");
	for(int i=1;i<=10;i++)
	{
		v=i;
		if(c==1)
		{

			for(int i=0;i<v;i++)
			{
				for(int j=0;j<v;j++)
				{
					if(j>i)
						adj[i][j]=1;
					else
						adj[i][j]=0;
				}
			}
		}
		if(c==0)
		{
			for(int i=0;i<v;i++)
                        {
                                for(int j=1;j<=v;j++)
                                {
					adj[i][j]=0;
				}
			}
			for(i=0;i<v;i++)
				adj[i][i+1]=1;
		}
		count=0;
		in();
		topological();
		if(c==1)
		{
			fprintf(fp2,"%d\t%d\n",v,count);
		}
		if(c==0)
		{
			fprintf(fp3,"%d\t%d\n",v,count);
		}
	}
	fclose(fp3);
	fclose(fp2);
}


		
int main()
{
	int ch;
	while(1)
	{
		printf("Enter\n1.To tester\n2.To plotter\nAny other key to exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:tester();
			       break;
			case 2:for(int i=0;i<2;i++)
				       plotter(i);
			       break;
			 default : exit(0);
		}
	}
}