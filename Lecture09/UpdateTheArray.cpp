//solution uploaded to: https://www.spoj.com/problems/UPDATEIT/

/*
    Use a BIT B such that Access(i) = Sum(i), i.e. Access(i) is 
    given by the prefix sum up to i. A query Update(l,r,v) is 
    implemented with two Add operations: Add(l,v) and Add(r+1,-v). 
*/


#include <bits/stdc++.h>
#include "fenwick_tree.hpp"
using namespace std;
#define ll long long


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    
    while(t--){
        ll n,u,l,r,v;
        cin >> n >> u;
        fenwick_tree<ll> B(n+1);
        
        for(int i=0; i<u; i++){
            cin >> l >> r >> v;
            B.add(l,v);
            if(r<n) B.add(r+1,-v);
        }


        ll q, pos;
        cin >> q;
        for(int i=0; i<q; i++){
            cin >> pos;
            cout << B.sum(pos) << endl;
        }
    }


    return 0;
}
