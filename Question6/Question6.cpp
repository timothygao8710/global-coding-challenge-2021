//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<string, int> pii;
 
#define pb push_back
 
#define f first
#define s second
//Could DSU, but brute force works since a * n is around 10^6
//93/100
int maxn = 1e4+6;

int root(int u, vector<int>& par){
    return par[u] == u ? u : par[u] = root(par[u], par);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N, M, mx, mn, am, bm, cm;
    cin >> N >> M >> mn >> mx >> am >> bm >> cm;
    vector<int> par; vector<vector<pii>> groups(N);
    map<string, int> mp;
    for(int i = 0; i<N; i++){
        groups[i].pb(pii("",-1)); 
        cin >> groups[i][0].f >> groups[i][0].s;
        mp[groups[i][0].f] = i;
        par.pb(i);
    }

    while(M--){
        int a, b;
        string temp; cin >> temp; a = root(mp[temp], par);
        cin >> temp; b = root(mp[temp], par);

        vector<pii> ga = groups[a], gb = groups[b];
        if(ga.size() + gb.size() > mx) continue;
        vector<int> cnt(5);
        vector<pii> ret;
        for(pii i : ga) {
            ret.pb(i); cnt[i.s]++;
        }
        for(pii i : gb){
            ret.pb(i); cnt[i.s]++;
        }
        if(cnt[1] > am || cnt[2] > bm || cnt[3] > cm) continue;
        par[b] = a;
        swap(groups[a], ret);
    }
    vector<vector<pii>> best;
    for(int i = 0; i<N; i++){
        if(root(i, par) != i) continue;
        if(mn > groups[i].size()) continue;
        if(!best.empty() && best[0].size() > groups[i].size()) continue;

        if(!best.empty() && best[0].size() < groups[i].size()) best.clear();
        
        sort(groups[i].begin(), groups[i].end()); //sorting array of vectors kinda effy in cpp...
        best.pb(groups[i]);
    }
    if(best.empty()){
        cout << "no groups"; return 0;
    }
    vector<string> all;
    for(auto i : best){
        for(pii j : i){
            all.pb(j.f);
        }
    }
    sort(all.begin(), all.end());
    for(auto i : all){
        cout << i << "\n";
    }
    return 0;
}
