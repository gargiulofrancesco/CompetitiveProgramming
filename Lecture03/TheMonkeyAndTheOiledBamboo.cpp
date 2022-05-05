//solution uploaded to: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=3183

/*
    given the array A[n], let tmax be the maximum height distance needed to 
    jump on the next rung. The solution is either tmax or tmax+1, so we can 
    simulate the algorithm and choose the smallest possible solution.
*/

#include <bits/stdc++.h>
using namespace std;
 
#define ll long long

int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t,n;
    cin >> t;
    for(int tcase=1; tcase<=t; tcase++){
        cin >> n;
        ll A[n];
        for(ll i=0; i<n; i++){
            cin >> A[i];
        }

        //find the maximum height distance tmax
        ll tmax = A[0];
        for(int i=1; i<n; i++){
            if(A[i]-A[i-1]>tmax) tmax=A[i]-A[i-1];
        }

        //simulate the algorithm with k=tmax
        ll k=tmax;
        bool is_enough = true;
        if(A[0]==k) k--;
        for(int i=1; i<n; i++){
            if(A[i]-A[i-1] > k) is_enough=false;
            else if(A[i]-A[i-1]==k) k--;
        }

        if(!is_enough) tmax++;
        cout << "Case " << tcase << ": "<< tmax<<endl;
    }

    return 0;
}
