//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printTriangle(int n) {
        // code here
        int k=1;
        for(int i=0;i<n;i++)
        {
            if(i%2==0) k=1;
            else k=0;
            for(int j=0;j<i+1;j++)
            {
                if(k) cout<<k--<<" ";
                else cout<<k++<<" ";
            }
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