//solution uploaded to:	http://practice.geeksforgeeks.org/problems/next-larger-element/0

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        std::deque<long long> Q; //indices of the window elements
        vector<long long> sol(n,-1); //solution
        for(int i=0; i<n; i++){
            //assign the solution for elements smaller than arr[i]
            //and remove them from the window
            while((!Q.empty()) && arr.at(i)>arr.at(Q.front())){
                sol.at(Q.front())=arr.at(i);
                Q.pop_front();
            }
            //insert the new element's index in the window's front
            Q.push_front(i);
        }
        return sol;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends
