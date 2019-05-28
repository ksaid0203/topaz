//
// Created by ksaid on 2019-05-27.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'

int main() {
    vector<string> arr;
    string str;
    ifstream inp("read.inp");
    int maxLen = 0;
    while(inp >> str) {
        maxLen = max(maxLen, (int)str.size());
        arr.emplace_back(str);
    }
    inp.close();
    sort(arr.begin(), arr.end());
    string cand, ans;
    int cnt1 = 0, cnt2 = 0;
    arr.emplace_back("0000");
    for(const string x : arr) {
        if(cand.empty()) {
            cand = x;
        }
        if(x == cand) {
            ++cnt2;
        }
        else {
            //cout << x << ' ' << cnt1 << ' ' << cnt2 << endl;
            if(cnt1 < cnt2) {
                cnt1 = cnt2;
                cnt2 = 1;
                ans = cand;
            }
            cand = x;
        }
    }

    ofstream out("read.out");
    out << ans << endl;
    out.close();
//    cout << ans << endl;
    return 0;
}