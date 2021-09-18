uploaded to:	http://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k/0


//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

#include <deque>


class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        
        vector<int> results;
        deque<int> Q;
        
        for(int i=0; i<n; i++){
            
            //remove from the head of Q the elements that are no longer in the window
            while(!Q.empty() && Q.front() < i-k+1){
                Q.pop_front();
            }
            
            //remove from the tail of Q the elements that are <= arr[i]
            while(!Q.empty() && arr[Q.back()] <= arr[i]){
                Q.pop_back();
            }
            
            //insert arr[i] to the tail of Q
            Q.push_back(i);
            
            //add the head of Q to the results
            if(i>=k-1){
                results.push_back(arr[Q.front()]);
            }
            
        }
        
        return results;
        
    }
};

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends