//solution uploaded to: https://www.spoj.com/problems/KNAPSACK/

/*
  Given N items and a capacity S, buil a table M[N+1][S+1]. Each entry M[i][j] will contain
  the solution considering only the first i items and capacity j. The first row is the empty set 
  and the first column is S=0. initialize the first row and column with zeroes and, for each .
  remaining entry M[i][j], evaluate if it's better to pick item i or not. 
  
  The recurrence is: M[i][j] = 
  - 0                                        if i=0 OR j=0
  - max(M[i-1][j], M[i-1][j-w_i] + v_i)        otherwise
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

    int S,N;
    cin >> S >> N;

    int weight[N], value[N];

    for(int i=0; i<N; i++){
        cin >> weight[i] >> value[i];
    }

    int M[N+1][S+1];
    for(int i=0; i<N+1; i++){
        M[i][0]=0;
    }
    for(int i=0; i<S+1; i++){
        M[0][i]=0;
    }

    for(int i=1; i<N+1; i++){
        for(int j=1; j<S+1; j++){
            M[i][j] = M[i-1][j];
            int rem = j-weight[i-1];
            if((rem>=0) && M[i-1][rem]+value[i-1]>M[i][j]){
                M[i][j] = M[i-1][rem]+value[i-1];
            }
        }
    }

    cout << M[N][S];

    return 0;
}
