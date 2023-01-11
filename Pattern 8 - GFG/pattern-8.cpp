//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
	
	void printTriangle(int n) {
	    // code here
	    for(int j=n-1;j>=0;j--)
	    {
	        for(int i=0;i<(n-j-1);i++) cout<<" ";
	        for(int i=0;i<(2*j)+1;i++) cout<<"*";
	        cout<<"\n";
	    }
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        Solution ob;
        ob.printTriangle(n);
    }
    return 0;
}
// } Driver Code Ends