class Solution {
public:
    int majorityElement(vector<int>& arr) {
    int majele,n=arr.size();
	int majcount=0;
	for(int i=0;i<n;i++)
	{
		if(majcount==0)
		{
			majele=arr[i];
			majcount++;
		} 
		else if(arr[i]==majele) majcount++;
		else majcount--;
		
	}
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]==majele) cnt++;
	}
	if(cnt>(n/2)) return majele;
	return -1;
        
    }
};