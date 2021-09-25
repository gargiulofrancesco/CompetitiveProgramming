//solution uploaded to:	http://codeforces.com/problemset/problem/579/B?locale=en




#include <bits/stdc++.h>

using namespace std;



int main(){


    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<int> p_queue;
    map<int, pair<int,int>> teams;

    int n;
    cin >> n;

    //order team pairs by their strength in a priority queue
    //store team pairs in a map to access them later using their strength as a key
    for(int i=2; i<=2*n; i++){
        for(int j=1; j<i;j++) {

            int team_strength;
            cin>>team_strength;

            p_queue.push(team_strength);
            teams[team_strength] = pair<int,int>(i,j);
        }
    }


    int* solution = new int[2*n]();
    int chosen_pairs=0;



    //choose team pairs greedily (if both components are still free)
    while(chosen_pairs!=n){
        int team_strenght=p_queue.top();
        p_queue.pop();
        pair<int,int> t = teams[team_strenght];
        if(solution[t.first-1]==0 && solution[t.second-1]==0){
            solution[t.first-1]=t.second;
            solution[t.second-1]=t.first;
            chosen_pairs++;
        }

    }

    for(int i=0;i<2*n;i++){
        cout << solution[i]<<" ";
    }


    return 0;
}
