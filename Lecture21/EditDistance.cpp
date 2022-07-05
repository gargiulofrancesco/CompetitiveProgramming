//solution uploaded to: https://practice.geeksforgeeks.org/problems/edit-distance3702/1

/*
  Given the input strings S of size n and T of size m, build a matrix M[n+1][m+1].
  The first row corresponds to the empty S prefix and the first column to the empty
  T prefix. Each entry M[i][j] contains the solution for the problem on prefixes 
  S[1..i] and T[1..j]. Given the solution for all the subproblems, let's compute M[i][j].
  If S[i]=T[j] then M[i][j] = M[i-1][j-1]. Otherwise the result is 1 plus the minimum
  between these operations:
  - align S[1..i] with B[1..j-1]
  - align S[1..i-1] with B[1..j]
  - align S[1..i-1] with B[1..j-1]
*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int editDistance(string s, string t) {
        // Code here
        int n = s.size(), m = t.size();
        int M[n+1][m+1];
        
        for(int i=0; i<n+1; i++){
            M[i][0] = i;
        }
        for(int i=0; i<m+1; i++){
            M[0][i] = i;
        }
        
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(s[i-1]==t[j-1]) M[i][j] = M[i-1][j-1];
                else M[i][j] = 1 + min(min(M[i-1][j], M[i][j-1]), M[i-1][j-1]);
            }
        }
        
        return M[n][m];
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends
