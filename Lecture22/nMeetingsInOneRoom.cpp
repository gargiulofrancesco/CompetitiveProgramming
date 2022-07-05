//solution uploaded to: https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

/*
  Sort meetings by increasing end-time and process them in this order. At each step
  add the current meeting if starts after the end of the last meeting added to the 
  solution.
*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        pair<int, int> meetings[n];
        for(int i=0; i<n; i++){
            meetings[i] = {start[i], end[i]};
        }
        
        //sort meetings by end time
        sort(meetings, meetings+n, [](pair<int,int> p1, pair<int,int> p2){return p1.second<p2.second;});
        
        int res=0, time=-1;
        for(int i=0; i<n; i++){
            if(meetings[i].first > time){
                res++;
                time = meetings[i].second;
            }
        }
        
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends
