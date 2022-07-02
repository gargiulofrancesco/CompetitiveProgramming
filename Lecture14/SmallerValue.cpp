/*
    The algorithm uses a segment tree st[n] and iterates through all possible values [0,n-1]:
    - sort the queries (l,r,X) by increasing value of X
    - sort pairs (value, position), where A[position]=value, by increasing value
    - for i in range [0,n-1]: 
        - perform a st.add(position, 1) for each pair (value=i, position)
        - solve eventual queries (l,r,X=i) with a st.sum(l,r)
*/


#include <bits/stdc++.h>
using namespace std;
#define ll long long


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


struct query{
    ll l;
    ll r;
    ll X;
    ll id;
    ll result;
};




int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m;
    cin >> n >> m;

    ll A[n];
    for(int i=0; i<n; i++){
        cin >> A[i];
    }

    ll l,r,X;
    query Q[m];
    for(int i=0; i<m; i++){
        cin >> l >> r >> X;
        Q[i] = {l,r,X, i, 0};
    }

    //sort queries by increasing value X
    sort(Q, Q+m, [](query q1, query q2){return q1.X<q2.X;});
    
    //sort pairs by increasing value 
    pair<ll,ll> pairs[n];
    for(int i=0; i<n; i++){
        pairs[i] = {A[i], i};
    }
    sort(pairs, pairs+n);

    //for i in range [0, n-1] update the segment tree and process queries 
    ll inp=0, inq=0;
    SegmentTree st(n);
    for(int i=0; i<n; i++){
        while(inp<n && pairs[inp].first==i){
            st.add(pairs[inp].second, 1);
            inp++;
        }
        while(inq<m && Q[inq].X==i){
           Q[inq].result = st.sum(Q[inq].l, Q[inq].r+1);
           inq++;
        }
    }

    //report results
    sort(Q, Q+m, [](query q1, query q2){return q1.id<q2.id;});
    for(int i=0; i<m; i++){
        cout << Q[i].result<<endl;
    }

    return 0;
}
