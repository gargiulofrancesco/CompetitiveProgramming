//solution uploaded to: https://codeforces.com/problemset/problem/652/D

#include <bits/stdc++.h>
using namespace std;
#define ll long long


//code adapted from https://codeforces.com/blog/entry/18051
class SegmentTree {
public:
    SegmentTree(int n) : n(n) {
        data.resize(2*n);
    }
    SegmentTree(vector<int> A) : n(A.size()){
        data.resize(2*n);
        //setting up leafs
        for(int i=0; i<n; i++){
            data.at(n+i)=A.at(i);
        }
        //setting up internal nodes
        for(int i=n-1; i>0; i--){
            data.at(i) = data.at(i<<1) + data.at(i<<1|1);
        }
    }

    void add(int leaf, int val) {
        for(int tnode=leaf+n; tnode>1; tnode>>=1){
            data.at(tnode)+=val;
        }
    }
 
    //the interval is [l,r)
    int sum(int l, int r) {
        int res=0;
        for (l+=n, r+=n; l<r; l>>=1, r>>=1){
            if (l&1){
                res += data.at(l);
                l++;
            }
            if (r&1){
                r--;
                res += data.at(r);
            }
        }
        return res;
    }

private:
    int n;
    vector<int> data;

};


struct interval{ 
    ll id;
    ll left;
    ll right;
    ll res;
};


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,l,r;
    cin >> n;
    interval A[n];

    for(int i=0; i<n; i++){
        cin >> l >> r;
        A[i]={i,l,r,0};
    }

    //sort intervals by their right end to compute ranks
    sort(A, A+n, [](interval p1, interval p2){return p1.right<p2.right;});
    map<ll,ll> rank;
    for(int i=0; i<n; i++){
        rank[A[i].right]=i;
    }

    //sort intervals by their left end to process them
    sort(A, A+n, [](interval p1, interval p2){return p1.left<p2.left;});
    SegmentTree st(n);
    for(int i=n-1; i>=0; i--){
        ll trank = rank[A[i].right];
        A[i].res = st.sum(0,trank);
        st.add(trank,1);
    }

    //sort intervals by id to print the results
    sort(A, A+n, [](interval p1, interval p2){return p1.id<p2.id;});
    for(int i=0; i<n; i++){
        cout << A[i].res << endl;
    }

    return 0;
}
