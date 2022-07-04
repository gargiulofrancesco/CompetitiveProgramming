//solution uploaded to: https://codeforces.com/problemset/problem/320/A

/*
    Scan the string s[1...n] from left to right. Given the current pointer at 
    position i, try to match a prefix of s[i...n] with the largest between 
    "144", "14", "1" and move the pointer after it. If at any moment it is 
    impossible to match a prefix, then the number is not magic. 
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    bool ismagic = true;
    for(int i=0; i<s.size(); i++){
        if(s[i]!='1'){
            ismagic=false;
            break;
        }

        if(i<s.size()-2 &&  s[i+1]=='4' && s[i+2]=='4'){
            i+=2;
        }
        else if(i<s.size()-1 && s[i+1]=='4'){
            i++;
        }
    }

    if(ismagic) cout << "YES";
    else cout << "NO";

    return 0;
}
