//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printTriangle(int n) {
        // code here
        for(int i=0;i<n;i++)
        {
            for(int k=0;k<n-i-1;k++) cout<<" ";
            for(int k=0;k<(2*i)+1;k++) cout<<"*";
            // for(int k=0;k<n-i-1;k++) cout<<" ";
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