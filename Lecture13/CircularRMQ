//solution uploaded to: https://codeforces.com/contest/52/problem/C

/*
    Use a segment tree with lazy propagation in order to perform efficient
    range updates/queries. The circularity of the array is significant only
    when a query interval [i,j] is such that i>j: 
    - add(i,j,v) is solved as add(i,n,v) and add(0,j,v)
    - RMQ(i,j) is solved as min(RMQ(i,n), RMQ(0,j)) 
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long


//code adapted from https://codeforces.com/blog/entry/18051
class SegmentTree {
public:
    SegmentTree(ll n) : n(n) {
        data.resize(2*n);
        lazy.resize(n);
        //highest significant bit in n
        height = sizeof(ll)*8 - __builtin_clz(n);
    }
    SegmentTree(vector<ll> A) : n(A.size()){
        data.resize(2*n);
        lazy.resize(n);
        height=sizeof(ll)*8 - __builtin_clz(n);

        //setting up leafs
        for(ll i=0; i<n; i++){
            data.at(n+i) = A.at(i);
        }
        //setting up internal nodes
        for(ll i=n-1; i>0; i--){
            data.at(i) = min(data.at(i<<1), data.at(i<<1|1));
        }
    }
 
    //the interval is [l,r)
    void add(ll l, ll r, ll val){
        l+=n, r+=n;
        ll l0=l, r0=r;
        while(l<r){
            if (l&1) apply(l++, val);
            if (r&1) apply(--r, val);
            l >>= 1, r >>= 1;
        }
        build(l0);
        build(r0 - 1);
    }
 
    //the interval is [l,r)
    ll rmq(ll l, ll r) {
        l+=n, r+=n;
        push(l);
        push(r-1);
        ll res=LLONG_MAX;
        while(l<r){
            if(l&1) res = min(res, data.at(l++));
            if(r&1) res = min(res, data.at(--r));
            l>>=1, r>>=1;
        }
        return res;
    }

private:
    ll n;
    ll height;
    vector<ll> data;
    vector<ll> lazy;

    void apply(ll node, ll value){
        data.at(node) += value;
        if(node<n) lazy.at(node) += value;
    }

    //updates all parents of node
    void build(ll node) {
        while (node > 1){
            node >>= 1;
            data.at(node) = min(data.at(node<<1), data.at(node<<1|1)) + lazy.at(node);
        }
    }

    //propagates changes from the root down to node
    void push(ll node){
        for(ll s=height; s>0; --s){
            ll i = node >> s;
            if(lazy.at(i) != 0){
                apply(i<<1, lazy.at(i));
                apply(i<<1|1, lazy.at(i));
                lazy.at(i)=0;
            }
        }
    }

};


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, temp, m;
    cin >> n;
    vector<ll> A;
    for(ll i=0; i<n; i++){
        cin >> temp;
        A.push_back(temp);
    }

    SegmentTree st(A);

    cin >> m;
    string line;

    while(getline(cin,line)){
        if(line.empty()) continue;

        vector<ll> input;
        stringstream stream(line);
        while(stream >> temp){
            input.push_back(temp);
        }

        ll l=input.at(0), r=input.at(1);
    
        if(l>r){
            if(input.size()==2){
                cout << min(st.rmq(l, n), st.rmq(0, r+1)) << endl;
            }
            else{
                st.add(l, n, input.at(2));
                st.add(0, r+1, input.at(2));
            }
        }
        else{
            if(input.size()==2){
                cout << st.rmq(l, r+1) << endl;
            }
            else{
                st.add(l, r+1, input.at(2));
            }
        }

    }

    return 0;
}
