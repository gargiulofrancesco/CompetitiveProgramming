//solution uploaded to: https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1


/*
  Use a greedy approach: keep track of the current number of jumps and the range [l,r] of positions
  it is possible to reach. Find the position in [l,r] that allows to jump to the farthest point tmax.
  Increment jumps++ and move the range to [r+1, tmax]. 
  
  If [l,r] doesn't contain a position that allows to jump after r, then there doesn't exist a 
  solution to reach the end.
*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        int sol[n] = {0};
        int left = 0, right=0, jumps=0;
        
        while(left<n){
            int tmax = right;
            for(int i=left; i<=right && i<n; i++){
                sol[i] = jumps;
                tmax = max(tmax, i+arr[i]);
            }
            
            if(tmax == right && right < n-1){
                sol[n-1] = -1;
                break;
            }
            
            jumps++;
            left=right+1;
            right=tmax;
        }
        
        return sol[n-1];
   
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
