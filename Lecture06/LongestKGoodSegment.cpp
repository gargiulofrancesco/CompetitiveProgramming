//solution uploaded on: https://codeforces.com/problemset/problem/616/D

/*
  use the two pointers technique: keep two pointers "left" and "right"
  to track the current interval. Moreover, keep a dictionary to store
  the #occurrences of each integer in the current interval.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
 
int main(){
 
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
 
    ll n,k;
    cin >> n >> k;
    ll A[n];
    for(int i=0; i<n; i++){
        cin >> A[i];
    }
 
    unordered_map<int,int> occurrences;
    ll left=0, right=-1; //current two pointers
    ll sol_l=0, sol_r=0; //solution segment
    ll counter=0; //#distinct elements
 
    while(right<n){
        if(counter<=k){
            if(right-left+1>sol_r-sol_l+1){
                sol_r=right;
                sol_l=left;
            }
            right++;
            ll value=A[right];
            if(occurrences.find(value)==occurrences.end()) occurrences[value]=1;
            else occurrences[value]++;
 
            if(occurrences[value]==1) counter++;
        }
        else{
            ll value=A[left];
            occurrences[value]--;
            left+=1;
            if(occurrences[value]==0) counter--;
        }
    }
 
    cout << sol_l+1 << " "<<sol_r+1;
 

    return 0;
}
