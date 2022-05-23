//solution uploaded to: https://codeforces.com/problemset/problem/466/C

/*
  Let totalsum define the sum of all elements in A. 
  A necessary (but not sufficient) condition for a solution to exist
  is for totalsum to be divisible by 3.
  The main idea is to find all prefixes A[1,i] whose elements sum to
  totalsum/3, and add to the result the number of ways to split A[i+1,n]
  in two non-empty subarrays both summing to totalsum/3.
  Create a binary array B[n] such that B[i]=1 if A[i...n] sums to n/3.
  Create an array C[n] such that C[i] stores the number of ways it is 
  possible to split A[i,n] in two parts both summing to totalsum/3.
  Finally, scan A from left to right keeping track of the current prefix
  sum. Whenever A[1,i] sums to totalsum/3, add to the result C[i+1].
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    ll n, totalsum=0;
    cin >> n;

    ll A[n];
    for(int i=0; i<n; i++){
        cin >> A[i];
        totalsum+=A[i];
    }

    //sum of elements must be divisible by 3
    if(totalsum%3!=0){
        cout << 0;
        return 0;
    }

    //B[i]=1 if A[i...n] sums to n/3
    ll B[n], curr=0;
    for(int i=n-1; i>=0; i--){
        curr+=A[i];
        if(curr==totalsum/3) B[i]=1;
        else B[i]=0;
    }

    //C[i] stores the number of ways it is possible to 
    //split A[i,n] in two parts both summing to S/3
    ll C[n]={0};
    for(int i=n-2; i>=0; i--){
        C[i]=C[i+1]+B[i+1];
    }

    ll res=0;
    curr=0;
    for(int i=0; i<n-1; i++){
        curr+=A[i];
        if(curr==totalsum/3) res+=C[i+1];
    }

    cout << res;

    return 0;
}
