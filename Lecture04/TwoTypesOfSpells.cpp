//solution uploaded to: https://codeforces.com/problemset/problem/1398/E

/*
    We should be able to maintain the list of spells (ordered by power) efficiently. 
    A std::map allows for insertion and deletion in logarithmic time.
    Let #lightning be the number of lightning spells available. At each step we 
    double the top #lightning spells. The only exception is verified when all the 
    top #lightning spells are of type lightning, in this case the doubling is 
    given to the top #lightning-1 and to the top fire spell (if it exists). 
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

set<ll> spells; //set of available spells
set<ll> fire_spells; //set of available fire spells
ll fire=0, //#fire spells
   lightning=0, //#lightning spells
   power=0, //sum of spells power
   dpower=0, //sum of doubled spells power
   dmin=LLONG_MAX, //minimum doubled spell power
   dfire=0, //#doubled fire spells
   dspells=0; //#doubled spells


int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, tp, d;
    cin >> n;
    while(n--){
        cin >> tp >> d;
        power+=d;

        if(d>0){
            spells.insert(d);
            if(tp==0) fire_spells.insert(d);
            if(d>dmin){
                dspells++;
                dfire++;
                dpower+=d;
            }
            if(tp==1) lightning++;
            else fire++;
        }
        else{
            spells.erase(-d);
            if(tp==0) fire_spells.erase(-d);
            if(-d>=dmin){
                dspells--;
                dpower+=d;
                if(-d==dmin && dspells>0){
                    auto iter = spells.lower_bound(-d);
                    dmin=*iter;
                }
                else if(dspells==0) dmin=LLONG_MAX;
            }
            if(tp==1) lightning--;
            else fire--;
        }
        while(lightning>dspells){
            auto iter = spells.lower_bound(dmin);
            iter--;
            dpower+=*iter;
            dmin=*iter;
            dspells++;
        }
        while(lightning<dspells){
            if(lightning==0){
                dpower=0;
                dmin=LLONG_MAX;
                dspells=0;
            }
            else{
                auto iter = spells.find(dmin);
                dpower-=dmin;
                dspells--;
                iter++;
                dmin=*iter;
            }
        }

        ll solution = power+dpower;
        if(lightning>0){
            if(fire_spells.empty() || *(fire_spells.rbegin())<dmin){
                solution-=dmin;
                if(!fire_spells.empty()) solution += *(fire_spells.rbegin());
            }
        }
        cout << solution << endl;
    }


    return 0;
}
