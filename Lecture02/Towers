//solution uploaded on: http://codeforces.com/problemset/problem/37/A?locale=en

#include <bits/stdc++.h>
using namespace std;


int main(){

    int n,temp;
    cin >> n;

    int distinct = 0; //total distinct elements in input
    int maxheight = 0;
    unordered_map<int,int> map; // storing pairs (item, frequency)
    for(int i=0; i<n; i++){
        cin >> temp;
        if(map.find(temp)==map.end()){
            map[temp]=1;
            distinct++;
        }
        else{
            map[temp]++;
        }
        if(map[temp]>maxheight) maxheight = map[temp];
    }

    cout << maxheight << " " << distinct;

    return 0;
}
