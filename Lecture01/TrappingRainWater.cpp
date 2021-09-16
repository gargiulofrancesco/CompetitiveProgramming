//solution uploaded to:	http://practice.geeksforgeeks.org/problems/trapping-rain-water/0



#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        
        long long result = 0;
        
        int* RL = right_leaders(arr,n);
        int* LL = left_leaders(arr,n);

	//the local solution a[i] = min(RL[i], LL[i])
        for(int i=1; i<n-1; i++){
            result = result + (min(RL[i], LL[i])-arr[i]);
        }

        
        return result;
    }
    




    //utils
    int* right_leaders(int arr[], int n){
        
        int *RL = new int[n];
        RL[n-1]=arr[n-1];
        int curr_max=arr[n-1];
        
        for(int i=n-2; i>=0; i--){
            if(arr[i]>curr_max){
                curr_max=arr[i];
            }
            RL[i]=curr_max;
        }
        
        return RL;
    }
    
    int* left_leaders(int arr[], int n){
                
        int *LL = new int[n];
        LL[0]=arr[0];
        int curr_max=arr[0];
        
        for(int i=1; i<n; i++){
            if(arr[i]>curr_max){
                curr_max=arr[i];
            }
            LL[i]=curr_max;
        }
        
        return LL;
    }
    
    int min(int a, int b){
        
        if(a<b){
            return a;
        }
        else{
            return b;
        }
    }
    
 
};





// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends