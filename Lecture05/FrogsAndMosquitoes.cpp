//solution uploaded to: https://codeforces.com/contest/609/problem/F

/*
    Frogs are represented by segments [position, position+tongue] and mosquitoes by points.
    Store frogs in a BBST ordered by frogs positions. When a mosquito lands at position x,
    find the leftmost predecessor of x in the frogs BST that still contains x. This process
    is speeded up by ensuring that at any moment there is no overlap between segments (this
    means that a single predecessor query is needed).

    - Sort the frogs by their starting position and use a sweep line to remove any kind of 
    overlapping. Track the current segment 'scurr' and if another segment 'snext' is found
    while the current one didn't end:  if snext contained in scurr then delete snext. 
    Otherwise set the starting point of snext at the end of scurr, delete all the segments
    between scurr and snext, and set scurr=snext to continue the sweep line algorithm.
    - If a frog f eats a mosquito then delete all the segments that are now contained in f
    and, if it exists, update the starting position of the partially overlapped segment.
    - Keep uneaten mosquitoes in a BBST ordered by their positions. After a frog f eats
    a mosquito and increases its tongue size, check if f is able to reach other uneaten
    mosquitoes. After this process, update the segments to ensure that no overlapping 
    exists.
*/


#include <bits/stdc++.h>
using namespace std;
#define ll long long


struct frog{
    ll id;
    ll pos; //initial position
    ll l; //segment beginning
    ll r; //segment end
    ll eaten; //#eaten mosquitoes
};
vector<frog> frogs; 
auto pcmp = [](pair<ll,ll> a, pair<ll,ll> b) {return a.first < b.first;};
set<pair<ll,ll>, decltype(pcmp)> BSTfrogs(pcmp); //set of pairs (position, frog id)


struct mosquito{
    ll pos;
    ll size;
};
auto mcmp = [](mosquito a, mosquito b) {return a.pos < b.pos;};
multiset<mosquito,decltype(mcmp)> BSTmosquitoes(mcmp);


//update segments after a mosquito gets eaten by curr_frog
void update_segments(ll curr_frog){
    auto succ_frog = BSTfrogs.upper_bound({frogs[curr_frog].l, LLONG_MAX});

    while((succ_frog!=BSTfrogs.end()) && succ_frog->second!=curr_frog){
        //complete overlap
        if(frogs[curr_frog].l <= frogs[succ_frog->second].l && frogs[curr_frog].r >= frogs[succ_frog->second].r){
            BSTfrogs.erase(succ_frog);
            succ_frog=BSTfrogs.upper_bound({frogs[curr_frog].l,LLONG_MAX});
        }
        //partial overlap
        else if(frogs[succ_frog->second].l <= frogs[curr_frog].r && frogs[succ_frog->second].r > frogs[curr_frog].r){
            frogs[succ_frog->second].l = frogs[curr_frog].r+1;
            ll tempid=succ_frog->second;
            BSTfrogs.erase(succ_frog);
            BSTfrogs.insert({frogs[tempid].l, tempid});
            break;
        }
        //no overlap
        else{
            break;
        }
    }
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m,pos,tongue,size;
    cin >> n >> m;

    for(ll i=0; i<n; i++){
        cin >> pos >> tongue;
        frogs.push_back({i,pos,pos,pos+tongue,0});
    }

    //sweep line to modify overlapping frogs
    auto fcmp = [](frog a, frog b) {return a.l < b.l;};
    sort(frogs.begin(), frogs.end(), fcmp);
    bool is_contained[n]={false};
    for(int i=0; i<n; i++) is_contained[i]=false;
    
    ll currt =frogs[0].r;
    for(ll i=1; i<n; i++){

        //total overlap
        if(frogs[i].r<=currt) is_contained[i]=true;
        //partial overlap
        else if(frogs[i].l <= currt && frogs[i].r > currt){
            frogs[i].l=currt+1;
            currt=frogs[i].r;
        }
        //no overlap
        else{
            currt=frogs[i].r;
        }
    }

    //insert non-overlapping segments in a BST
    for(ll i=0; i<n; i++){
        if(!is_contained[i]){
            BSTfrogs.insert({frogs[i].l, frogs[i].id});
        }
    }
    //restore frogs ordering by id
    sort(frogs.begin(), frogs.end(), [](frog a, frog b){return a.id < b.id;});

    //read input for mosquitoes
    for(ll i=0; i<m; i++){
        cin >> pos >> size;
        BSTmosquitoes.insert({pos,size});

        //finding the predecessor of pos in BSTfrogs
        auto pfrogit = BSTfrogs.upper_bound({pos, -1});
        if(pfrogit!=BSTfrogs.begin()) pfrogit--;
        else continue;

        ll pfrogid = pfrogit->second;
        auto smosq = BSTmosquitoes.lower_bound({frogs[pfrogid].l, -1});

        //predecessor frog eat mosquitoes while it can
        while((smosq!=BSTmosquitoes.end()) && smosq->pos<=frogs[pfrogid].r){
            frogs[pfrogid].eaten++;
            frogs[pfrogid].r += smosq->size;
            BSTmosquitoes.erase(smosq);
            smosq=BSTmosquitoes.lower_bound({frogs[pfrogid].l, -1});
        }
        update_segments(pfrogid);
    }

    for(ll i=0; i<n; i++){
        cout << frogs[i].eaten <<" "<<frogs[i].r-frogs[i].pos <<endl;
    }

    return 0;
}
