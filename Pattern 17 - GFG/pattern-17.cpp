//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printTriangle(int n) {
        // code here
        int i=0;
        for(int j=0;j<n;j++)
        {
            for(i=0;i<n-j-1;i++) cout<<" ";
            char c='A';
            for(i=0;i<j;i++) cout<<c++;
            auto k=c--;
            while(k>='A') cout<<k--;
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