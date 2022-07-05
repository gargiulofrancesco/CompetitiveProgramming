//solution uploaded to: https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1

/*
  Use a dynamic programming approach where LCS(i,j) contains the solution for the problem
  on prefixes s1[1,i] and s2[1,j]. Given the solutions for all possible subproblems,
  compute LCS(i,j) as:
  - 1 + LCS(i-1, j-1),                  if s1[i]=s2[j]
  - max(LCS(i-1, j), LCS(i, j-1)),       otherwise
  In the bottom-up approach we use a table M[n+1][m+1] where the first row and column
  (empty prefixes) are filled with zeroes and each remaining cell M[i][j] depends just
  on M[i-1][j-1], M[i-1][j] and M[i][j-1]
*/


// { Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

 // } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        int M[x+1][y+1];
        for(int i=0; i<x+1; i++){
            M[i][0] = 0;
        }
        for(int i=0; i<y+1; i++){
            M[0][i] = 0;
        }
        
        for(int i=1; i<x+1; i++){
            for(int j=1; j<y+1; j++){
                if(s1[i-1]==s2[j-1]) M[i][j]=M[i-1][j-1]+1;
                else M[i][j]=max(M[i-1][j], M[i][j-1]);
            }
        }
        
        return M[x][y];
    }
};


// { Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
  // } Driver Code Ends
