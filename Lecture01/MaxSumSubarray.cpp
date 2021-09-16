//solution uploaded to:	http://practice.geeksforgeeks.org/problems/kadanes-algorithm/0




#include<bits/stdc++.h>
using namespace std;



class Solution{
    public:

    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        
        /*
            test cases contain arrays with all negative integers, 
            so I modified Kadane's algorithm accordingly
        */
        
        
        long long local_sum = arr[0];
        long long max = arr[0];
        
        
        for(int i=1; i<n; i++){
            
            //update local sum
            if(local_sum<0 && arr[i]>local_sum){
                local_sum = arr[i];
            }
            else{
                local_sum = local_sum + arr[i];
            }
            
            
            if(local_sum > max){
                max = local_sum;
            }
            
        }
        
        
        return max;
        
    }
};




// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends