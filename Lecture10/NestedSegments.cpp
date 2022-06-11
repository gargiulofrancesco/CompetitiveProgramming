//solution uploaded to: https://codeforces.com/problemset/problem/652/D

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include "fenwick_tree.hpp"

/*
    For each interval (l_i,r_i) we want to print the number of intervals
    (l_j, r_j) it contains, i.e. such thatl_i < l_j AND r_i > r_j. 
    We can check these two conditions as follows:

    - l_i < l_j: sort intervals based on their left-end points, then process 
    them from right to left. In this way, every time we are processing (l_i,r_i),
    we are sure that the previously processed intervals (l_j,r_j) are such that
    l_i < l_j. 
    - r_i > r_j: maintain a BIT B storing the right-ends of already processed
    intervals. Sort the right-ends and assign to each of them its rank in this 
    ordering. Segment (l_i,r_i) is mapped to B[rank(r_i)]. After processing
    (l_i,r_i) add one to B[rank(r_i)].

    The result of the current segment (l_i,r_i) is given by Sum(rank(r_i)).
*/

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
        rank[A[i].right]=i+1;
    }

    //sort intervals by their left end to process them
    sort(A, A+n, [](interval p1, interval p2){return p1.left<p2.left;});
    fenwick_tree<ll> B(n+1);
    for(int i=n-1; i>=0; i--){
        ll trank = rank[A[i].right];
        A[i].res = B.sum(trank);
        B.add(trank,1);
    }

    //sort intervals by id to print the results
    sort(A, A+n, [](interval p1, interval p2){return p1.id<p2.id;});
    for(int i=0; i<n; i++){
        cout << A[i].res << endl;
    }

    return 0;
}
