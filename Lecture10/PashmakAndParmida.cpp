//solution uploaded to: https://codeforces.com/problemset/problem/459/D

#include <bits/stdc++.h>
#include "fenwick_tree.hpp"
using namespace std;
#define ll long long

/*
    Let A[n] be the input array.
    Let psum[n] be an array of integers such that psum[i] = f(1,i,a_i).
    Let ssum[n] be an array of integers such that ssum[i] = f(i,n,a_i).
    
    The solution is similar to the BIT solution of the inversion count problem.
    
    Visit A from right to left and use a BIT B to store the current frequencies of 
    ssum values. For the current index i, add all the pairs (i,j), i<j, such that 
    psum[i]>ssum[j]. This is done with a query B.sum(psum[i]-1). Then update the BIT 
    with a B.add(ssum[i]], 1) query.
*/



int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

  
    ll n;
    cin >> n;
    ll A[n];
    
    for(int i=0; i<n; i++){
        cin >> A[i];
    }

    //computing psum and ssum
    map<ll,ll> pmap, smap;
    ll psum[n], ssum[n];
    for(int i=0; i<n; i++){
        pmap[A[i]]++;
        psum[i]=pmap[A[i]];
    }
    for(int i=n-1; i>=0; i--){
        smap[A[i]]++;
        ssum[i]=smap[A[i]];
    }

    //visit A from right to left
    fenwick_tree<ll> B(n+1);
    ll result=0;
    for(ll i=n-1; i>=0; i--){
        result+=B.sum(psum[i]-1);
        B.add(ssum[i],1);
    }

    cout << result;

    return 0;
}
