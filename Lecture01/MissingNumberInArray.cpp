//solution uploaded to:	http://practice.geeksforgeeks.org/problems/missing-number-in-array/0




#include <bits/stdc++.h>
using namespace std;




class Solution{
  public:
    int MissingNumber(vector<int>& array, int n) {
        
        int result=0;
        
        //xor every element from 1 to n
        for(int i=1; i<=n; i++){
            result = result ^ i;
        }
        
        //delete duplicates from the first array, leaving only the missing number
        for(auto i=array.begin(); i!=array.end(); i++){
            result = result ^ (*i);
        }
        
        
        return result;
    }
};




// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> array(n - 1);
        for (int i = 0; i < n - 1; ++i) cin >> array[i];
        Solution obj;
        cout << obj.MissingNumber(array, n) << "\n";
    }
    return 0;
}  // } Driver Code Ends