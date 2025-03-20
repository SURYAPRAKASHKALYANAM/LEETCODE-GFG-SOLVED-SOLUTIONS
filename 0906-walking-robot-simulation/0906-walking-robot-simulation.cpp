class Solution {
public:
    set<pair<int,int>> s;
    void go(int &x,int &y,int dx,int dy,int steps)
    {
        while(steps--)
        {
            x+=dx;
            y+=dy;
            if(s.find({x,y})!=s.end()) {x-=dx,y-=dy; return;}
        }
    }
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int max_x=INT_MIN,max_y=INT_MIN,min_x=0,min_y=0;
        int x=0,y=x,pos=0,maxi=0;
        // char dire[4]={'N','E','S','W'};
        for(auto i:obstacles) s.insert({i[0],i[1]});
        for(auto i:commands)
        {
            if(i==-2)
            {
                if(pos==0) pos=3;
                else pos--;
            }
            else if(i==-1)
            {
                pos=(pos+1)%4;
            }
            else
            {
                if(pos==0) go(x,y,0,1,i);
                else if(pos==1) go(x,y,1,0,i);
                else if(pos==2) go(x,y,0,-1,i);
                else go(x,y,-1,0,i); 
                
            }
            maxi=max(maxi,x*x+y*y);
        }
        s.clear();
        return maxi;
    }
};