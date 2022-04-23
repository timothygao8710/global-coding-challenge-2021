//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second

//O(2^B * B^2 * C)
//A factor of B can be optimized out, but this suffices
//AC
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int C, B; cin >> C >> B;
    vector<vector<int>> costs(B, vector<int>(C+1));
    for(int i=0; i<B; i++){
        for(int j=1; j<=C; j++){
            cin >> costs[i][j];
        }
    }
    //index, used bankers, current banker
    int dp[C+1][1<<B][B];
    for(int i = 0; i<C; i++) for(int j = 0; j<(1<<B); j++) for(int k = 0; k<B; k++) dp[i][j][k] = 0;
    
    for(int i = 1; i<=C; i++){
        for(int j = 0; j<(1<<B); j++){
            for(int c = 0; c<B; c++){
                if(((j>>c)&1) == 0) continue;
                //not switch:
                dp[i][j][c] = dp[i-1][j][c];
                //switch:
                for(int l = 0; l<B; l++){ //this part can be optimized
                    if(c == l || ((j>>l)&1) == 0) continue;
                    dp[i][j][c] = min(dp[i][j][c],
                        dp[i-1][j^(1<<c)][l]
                    );
                }
                dp[i][j][c] += costs[c][i];
            }
        }
    }
    int ret = 1e9;
    for(int i = 0; i<B; i++){
        ret = min(ret, dp[C][(1<<B)-1][i]);
    } 
    cout << ret;
    return 0;
}
/*
20 10
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
*/