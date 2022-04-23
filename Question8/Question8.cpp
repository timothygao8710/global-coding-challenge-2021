//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second
const int maxn = 5e3 + 90;
ll dp[maxn][maxn];

using namespace std;
//2 2
//100 1
//try m=1, and other extremes
int calculateMaximizedReturns(ll n, ll k, ll d, ll m, vector<ll> returns) {
    // d++;
    //index : how many used so far
    vector<multiset<ll>> best(k+1);
    vector<ll> pref(n); pref[0] = m*returns[0];
    for(int i = 1; i<n; i++){
        pref[i] = pref[i-1] + m*returns[i];
    }
    best[0].insert(pref[n-1]);    
    for(int i = 1; i<=k; i++) dp[n][i] = -1e9;
    for(int i = n-1; i>=0; i--){
        if(i+d+1 <= n){
            for(int j = 0; j<k; j++){
                best[j].erase(best[j].find(dp[i+d+1][j] + pref[i+d]));
                best[j].insert(dp[i+d+1][j] + pref[i+d] - (m-1)*returns[i+d]);
            }
        }
        for(int j = 0; j<=k; j++){
            dp[i][j] = dp[i+1][j]+returns[i];
            if(j-1 >= 0){
                auto it = best[j-1].end(); --it;
                if(i == 1 && j == 1) cout << (*it) << endl;
                dp[i][j] = max(dp[i][j], (*it) - pref[i]);
            }
        }
        for(int j = 0; j<=k; j++){
            ll prev = i == 0 ? 0 : pref[i-1];
            best[j].insert(dp[i][j] + prev);
        }
    }
    ll ret = 0;
    for(ll i : dp[0]) ret = max(ret, i);
    return ret;
}


vector<string> split(const string& str, char delim) {
    vector<string> strings;
    size_t start;
    size_t end = 0;
    while ((start = str.find_first_not_of(delim, end)) != string::npos) {
        end = str.find(delim, start);
        strings.push_back(str.substr(start, end - start));
    }
    return strings;
}

vector<ll> splitStringToInt(const string& str, char delim) {
    vector<ll> strings;
    size_t start;
    size_t end = 0;
    while ((start = str.find_first_not_of(delim, end)) != string::npos) {
        end = str.find(delim, start);
        strings.push_back(stoi(str.substr(start, end - start)));
    }
    return strings;
}


int main() {
    string firstLine;
    getline(cin, firstLine);

    vector<ll> firstLineVec = splitStringToInt(firstLine, ' ');
    ll n = firstLineVec[0];
    ll k = firstLineVec[1];
    ll d = firstLineVec[2];
    ll m = firstLineVec[3];

    string returns;
    getline(cin, returns);

    vector<ll> returnsVec = splitStringToInt(returns, ' ');

    int result = calculateMaximizedReturns(n, k, d, m, returnsVec);

    // Do not remove below line
    cout << result << "\n";
    // Do not print anything after this line

    return 0;
}