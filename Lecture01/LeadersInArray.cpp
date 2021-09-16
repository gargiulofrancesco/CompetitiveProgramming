//solution uploaded to:	http://practice.geeksforgeeks.org/problems/leaders-in-an-array/0




#include <bits/stdc++.h>
using namespace std;


class Solution{
    
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        
        vector<int> results;
        
        //last element is always a leader
        int current_max = a[n-1];
        results.push_back(a[n-1]);
        
        //visit the array from right to left keeping track of the current maximum        
        for(int i=n-2; i>=0; i--){
            
            if(a[i]>=current_max){
                
                current_max = a[i];
                results.push_back(a[i]);
            }
        }
        
        reverse(results.begin(), results.end());
        
        return results;
    }
};





int main()
{
   long long t;
   cin >> t; //testcases
   while (t--)
   {
       long long n;
       cin >> n;//total size of array
        
        int a[n];
        
        //inserting elements in the array
        for(long long i =0;i<n;i++){
            cin >> a[i];
        }
        Solution obj;
        //calling leaders() function
        vector<int> v = obj.leaders(a, n);
        
        //printing elements of the vector
        for(auto it = v.begin();it!=v.end();it++){
            cout << *it << " ";
        }
        
        cout << endl;

   }
}
