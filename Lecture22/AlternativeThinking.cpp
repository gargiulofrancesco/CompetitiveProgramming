//solution uploaded to: https://codeforces.com/contest/603/problem/A

/*
    Consider the number of occurrences of "00" or "11" in the string:
    - if it's zero (e.g. 1010101 -> 0101010) then the result is n because by
      inverting the whole string the result doesn't change
    - if it's one (e.g. 1101 -> 1010) then the result is n because we can invert 
      the suffix starting from the second element of the unique substring "00" or "11" 
    - if it's two or more then the result increases by two: (00...00 -> 01...10), 
      (000 -> 010), (11...00 -> 10...10) etc.
    This means that the result is either n or the "original" result plus two
*/ 

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    string s;
    cin >> n >> s;

    ll res = 1;
    for(int i=1; i<n; i++){
        if(s[i]!=s[i-1]) res++;
    }

    cout << min(n, res+2);

    return 0;
}
