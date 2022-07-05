//solution uploaded to: https://practice.geeksforgeeks.org/problems/longest-palindromic-subsequence/0

/*
  Find the length of the longest common subsequence of the input string and its reverse.
*/

// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  
    int lcs(string s1, string s2){
        
        int x = s1.size(), y = s2.size();

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
    
    
    int longestPalinSubseq(string A) {
        
            string Arev = A;
            reverse(Arev.begin(), Arev.end());

            return lcs(A, Arev);
    }
};

// { Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends
