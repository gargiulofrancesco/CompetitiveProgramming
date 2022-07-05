//Solution uploaded to: https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1

/*
  Let LIS[i] be the length of the LIS of A[1...i] ending in A[i].
  The recurrence is the following: LIS[i] = 
  -  1+max(LIS[j] | 1<=j<i AND A[j]<A[i])    if such j exists
  -  1                                       otherwise
  
  This solution takes quadratic time but we can improve it up to O(nlog(n)) by taking
  into account only dominant positions: given A[j]<A[i] we say that j dominates i if
  LIS[j]>=LIS[i] AND j<i. While computing LIS[i] values, keep a BBST updated so that 
  it stores dominant positions only and compute LIS[i] as predecessor(A[i])+1.
*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        int LIS[n];
        map<int, int> dpos;
        
        for(int i=0; i<n; i++){
            auto pred = dpos.lower_bound(a[i]);
            
            LIS[i]=1;
            if(pred!=dpos.begin()){
                pred--;
                LIS[i]+=(LIS[(*pred).second]);
            }
            
            auto succ=dpos.lower_bound(a[i]);
            if(succ!=dpos.end() && LIS[i]>=LIS[(*succ).second]){
                dpos.erase(succ);
            }
    
            dpos[a[i]]=i;
        }
        
        int res = INT_MIN;
        for(int i=0; i<n; i++){
            res = max(res, LIS[i]);
        }
        
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends
