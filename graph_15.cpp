class Solution {
public:

    void explore_neighbour(int X, int Y,int d1, int d2,queue<pair<int,int>>&q,vector<vector<bool>>&vis,bool &flag ,int N)
    {
        int x[]={-1,-1,1,1,2,2,-2,-2};
        int y[]={2,-2,2,-2,1,-1,1,-1};
        for(int i=0;i<8;i++)
        {
            if(X+x[i]<0||X+x[i]>=N||Y+y[i]<0||Y+y[i]>=N||vis[X+x[i]][Y+y[i]])
            {
                continue;
            }
            if(X+x[i]==d1&&Y+y[i]==d2)
            {
                flag=true;
                return;
            }
            q.push({X+x[i],Y+y[i]});
            vis[X+x[i]][Y+y[i]]=true;
        }
    }


	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N)
	{
	    int s1=KnightPos[0]-1;
	    int s2=KnightPos[1]-1;
	    int d1=TargetPos[0]-1;
	    int d2=TargetPos[1]-1;
	    if(s1==d1&&d2==s2)
	    {
	        return 0;
	    }
	    queue<pair<int,int>>q;
	    vector<vector<bool>>vis;
	    for(int i=0;i<N;i++)
	    {
	        for(int j=0;j<N;j++)
	        {
	            vis[i][j]=false;
	        }
	    }
	    q.push({s1,s2});
	    vis[s1][s2]=true;
	    
	    int count;
	    int step=0;
	    count=q.size();
	    bool flag=false;
	    while(count>0)
	    {
	        step++;
	        for(int i=0;i<N;i++)
	        {
	            
	                pair<int,int>p=q.front();
	                q.pop();
	                explore_neighbour(p.first,p.second,d1,d2,q,vis,flag,N);
	                if(flag==true)
	                {
	                    return step;
	                }
	            
	        }
	        count=q.size();
	    }
	    
	    
	    return -1;
	    
	    
	}
};
