//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second

using namespace std;

const int maxa = 1e6+9;
const int mod = 1e9+7;

//O(10^6 log(log(10^6)) + N) --> harmonic series + prime distribution, then bipartite check

//draw an edge between numbers that share a prime factor, then find the number of distinct components
//each component is not guaranteed to be bipartite

//special case: duplicate numbers
/*
3
6
6
3

4
2
6
9
7

3
1
1
1

4
7 7 21 6

2*3 = 6
2*5 = 10
3*5 = 15
3
6
10
15
*/
//problem is ambiguous about if divison of two numbers if they are equal counts as 2 cases or 1
//assuming its 2 cases

int binpow(ll base, ll pow)
{
    if (pow == 0) return 1;
    ll half = binpow(base, pow / 2);
    ll ret = (half * half) % mod;
    if (pow % 2 == 1) ret *= base;
    return ret%mod;
}

struct DSU{
    vector<int> par, sz;
    int tot;
    DSU(int n, int a){
       tot = a;
        par.reserve(n); sz.reserve(n);
        for(int i = 0; i<n; i++) {
            par.pb(i); sz.pb(1);
        }
    }

    int root(int u){
        return par[u] == u ? u : par[u] = root(par[u]);
    }

    void unite(int u, int v){
        int ru = root(u); int rv = root(v);
        if(ru == rv) return;
        tot--;
        if(sz[rv] > sz[ru]) swap(ru, rv);
        sz[ru] += rv;
        par[rv] = ru;
    }

};
//AC
void countStablePartitions(int n, vector<int>& nums) {
   vector<int> comp(maxa), occ(maxa);
   int comps = 0, ret = 1;
   fill(occ.begin(), occ.end(), -1);
   for(int i =  0; i<n; i++){
       if(nums[i] == 1){
           ret *= 2; continue;
       }
       if(occ[nums[i]] == -1){
           comps++;
       }
      occ[nums[i]] = i;
   }
   DSU dsu(n, comps);
   for(int i = 2; i<maxa; i++){
      int last = -1;
      for(int j = i; j<maxa; j+=i){
         if(occ[j] == -1) continue;
         if(last != -1) dsu.unite(occ[j], last);
         last = occ[j];
      }
   }
   ret *= binpow(2, dsu.tot); ret -= 2;
   if(ret){
       cout << "YES\n";
   }else{
       cout << "NO\n";
   }
   cout << ret;
}

int main(){
   int n;
   cin >> n;
   vector<int> values(n);
   for (int i = 0; i < n; ++i) {
        cin >> values[i];
   }
   countStablePartitions(n, values);
   return 0;
}
