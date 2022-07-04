//solution uploaded to: https://codeforces.com/problemset/problem/596/B

/*
    Scan the array from left to right while keeping track of the current value: 
    at step i, variable curr contains the value of elements in suffix A[i,n].
    At step i change curr so that A[i]=curr and move on to step i+1.
*/


#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
  
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    
    ll A[n];
    for(int i=0; i<n; i++){
        cin >> A[i];
    }

    ll curr=0, res=0;
    for(int i=0; i<n; i++){
        ll diff = abs(curr-A[i]);
        res += diff;
        curr = A[i];
    }

    cout << res;


    return 0;
}
