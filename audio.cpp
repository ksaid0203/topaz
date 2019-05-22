//
// Created by ksaid on 2019-05-17.
//

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

set<int> adj[15];

const int INF = 987654321;

int solve(const vector<int> & arr, const int ans) {
    int ret = 0;
    for(int i = 0 ; i < arr.size() ; i += 1) {
        for(int j = i + 1 ; j < arr.size(); j += 1) {
            if(adj[arr[i]].find(arr[j]) != adj[arr[i]].end()) {
                ret += j - i;
                if(ans < ret) {
                    return INF;
                }
            }
        }
    }

    return ret = min(ret, ans);
}


int main() {
    ios_base::sync_with_stdio(false);
    ifstream inp("audio.inp");
    inp.tie(NULL);
    int n;
    inp >> n;
    for(int i = 0 ; i < n ; ++i) {
        int x;
        inp >> x;
        int tmp = -1;
        while(true) {
            inp >> tmp;
            if(tmp == 0) {
                break;
            }
            adj[x].insert(tmp);
        }
    }

    inp.close();

    vector<int> arr;
    vector<int> ans_V;
    for(int i = 1 ; i <= n ; ++i) {
        arr.emplace_back(i);
        ans_V.emplace_back(i);
    }

    int ans = INF;

    do {
        auto cand = solve(arr, ans);
        if(ans > cand) {
            ans = cand;
            for(int i = 0 ; i < n; ++i) {
                ans_V[i] = arr[i];
            }
        }
    } while(next_permutation(arr.begin(), arr.end()));

    ofstream out("audio.out");
    out << ans << endl;
    for(auto x : ans_V) {
        out << x << ' ';
    }
    out.close();
    return 0;
}
