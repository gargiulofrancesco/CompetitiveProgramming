//solution uploaded to: https://codeforces.com/problemset/problem/276/C

/*
    The main idea is to create an array of frequencies F such that
    F[i] contains the number of queries [l,r] such that l<=i<=r. 
    Then associate the maximum value of A to the maximum frequency, 
    and so on. The only problem with this is that, for each query
    [l,r], naively increasing by one each F[i], l<=i<=r would take
    too much time.

    To create F efficiently, use an array B[n]={0}. For each query
    [l,r] update B[l]+=1 and B[r+1]-=1. Then compute F as the prefix
    sums of B. The idea is that the prefix sums will implicitly 
    propagate the +1 from F[l] to F[r]. This allows us to compute
    F in O(n+q).
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,q,l,r;
    cin >> n >> q;
    
    ll A[n];
    for(int i=0; i<n; i++){
        cin >> A[i];
    }

    ll B[n]={0};
    while(q--){
        cin >> l >> r;
        l--; r--;
        B[l]++;
        if(r+1<n) B[r+1]--;
    }

    ll F[n];
    F[0]=B[0];
    for(int i=1; i<n; i++){
        F[i]=F[i-1]+B[i];
    }

    sort(A,A+n,greater<ll>());
    sort(F,F+n,greater<ll>());
    ll res=0;
    for(int i=0; i<n; i++){
        res+=A[i]*F[i];
    }

    cout << res;



    return 0;
}
