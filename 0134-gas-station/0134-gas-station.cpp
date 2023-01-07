class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int station=gas.size(),i=0,j=0,cur_gas=0,start=0;
        int tc=0,tg=0;
        for(i=0;i<station;i++)
        {
            cur_gas+=gas[i];
            cur_gas-=cost[i];
            if(cur_gas<0)
            {
                cur_gas=0;
                start=i+1;                                  //   SURYA_PRAKASH :**ORDER OF N+(STARTING POSTION)**//
            }
            tc+=cost[i];
            tg+=gas[i];
        }
        if(tc>tg) return -1;
        for(i=0;i<=start;i++)
        {
            cur_gas+=gas[i]-cost[i];
            if(cur_gas<0) return -1;
        }
        return start;
        // while(i<station)
        // {
        //     cur_gas+=gas[i];
        //     while(cur_gas>=cost[j])
        //     { 
        //         cur_gas-=cost[j];
        //         if(j==station-1) j=-1;    //SURYA PRAKASH :**ORDER OF N^2**//
        //         cur_gas+=gas[j+1];
        //         j++;
        //         if(j==i) return i;
        //     }
        //     i++;
        //     j=i;
        //     cur_gas=0;
        // }
    }
};