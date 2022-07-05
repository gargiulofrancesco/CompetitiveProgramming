//solution uploaded to: https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1

/*
  Let sum be the sum of all the array elements. A solution exists only if sum is even.
  Use the dynamic programming solution to the subset sum problem and check if there
  exists a solution for sum/2.
  
  Build a table M[n+1][sum+1] where M[i][j] indicates if it's possible for a subset of
  the first i integers to sum to j. The first row corresponds to the empty set and the 
  first column to sum=0. The recurrence is the following: M(i,j)=
  - 1                                  if i=j=0
  - 0                                  if i=0 AND j>0
  - M(i-1, j) OR M(i-1, j-A[i])        otherwise
*/

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for(int i=0; i<N; i++){
            sum += arr[i];
        }
        
        //if a solurion exists then sum must be even
        if(sum%2==1) return 0;
        
        bool M[N+1][sum+1];
        for(int i=1; i<sum+1; i++){
            M[0][i] = false;
        }
        for(int i=0; i<N+1; i++){
            M[i][0] = true;
        }
        
        for(int i=1; i<N+1; i++){
            for(int j=1; j<sum+1; j++){
                M[i][j] = M[i-1][j];
                int rem = j-arr[i-1];
                if((rem>=0) && M[i-1][rem]) M[i][j]=true;
            }
        }
        
        if(M[N][sum/2]) return 1;
        else return 0;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends
