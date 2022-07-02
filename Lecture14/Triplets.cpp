/*
  Given the input A[n], use two segment trees to compute the arrays F[n] and P[n] such that:
  - F[i] = #indices k>i such that A[i]<A[k]
  - P[i] = #indices k<i such that A[k]<A[i]
  The result is given by the sum, over all indices i, of F[i]*P[i]
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




int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    ll A[n];
    for(int i=0; i<n; i++){
        cin >> A[i];
    }

    ll F[n];
    SegmentTree st1(n);
    for(int i=n-1; i>=0; i--){
        F[i] = st1.sum(A[i]+1, n);
        st1.add(A[i], 1);
    }

    ll P[n];
    SegmentTree st2(n);
    for(int i=0; i<n; i++){
        P[i] = st2.sum(0, A[i]);
        st2.add(A[i], 1);
    }

    ll res=0;
    for(int i=0; i<n; i++){
        res += F[i]*P[i];
    }

    cout << res;

    return 0;
}
