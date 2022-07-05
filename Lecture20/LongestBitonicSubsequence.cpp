//solution uploaded to: https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence/0

/*
  Given the input sequence A[n], compute its table LIS[n] and LDS[n]. 
  The solution is max(LIS[i]+LDS[i]-1), 0<=i<n.
  LDS[n] is computed as the LIS of the inverse input sequence A.
*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	
	vector<int> lis(vector<int> A){
        int n = A.size();
        vector<int> res(n);
        map<int, int> dpos;
    
        for(int i=0; i<n; i++){
            auto pred = dpos.lower_bound(A.at(i));
    
            res.at(i)=1;
            if(pred!=dpos.begin()){
                pred--;
                res.at(i)+=(res.at((*pred).second));
            }
                
            auto succ=dpos.lower_bound(A.at(i));
            if(succ!=dpos.end() && res.at(i)>=res.at((*succ).second)){
                dpos.erase(succ);
            }
        
            dpos[A.at(i)]=i;
        }
            
        return res;
    }
    
	int LongestBitonicSequence(vector<int>nums){
        vector<int> LIS = lis(nums);
        reverse(nums.begin(), nums.end());
        vector<int> LDS = lis(nums);
        reverse(LDS.begin(), LDS.end());
    
        int res = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            res=max(res, LIS.at(i)+LDS.at(i)-1);
        }
        
        return res;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
