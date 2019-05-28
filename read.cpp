//
// Created by ksaid on 2019-05-27.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
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
    vector<vector<string>> radix;
    for(int i = maxLen - 1; i >= 0 ; --i) {
        radix.clear();
        radix.resize(5, vector<string>());
        for(const string x : arr) {
            if(x.size() <= i) {
                radix[0].emplace_back(x);
            }
            else {
                if(x[i] == 'a') {
                    radix[1].emplace_back(x);
                }
                else if(x[i] == 'c') {
                    radix[2].emplace_back(x);
                }
                else if(x[i] == 'g') {
                    radix[3].emplace_back(x);
                }
                else if(x[i] == 't') {
                    radix[4].emplace_back(x);
                }
            }
        }

        arr.clear();
        arr.insert(arr.begin(), radix[0].begin(), radix[0].end());
        arr.insert(arr.begin() + radix[0].size(), radix[1].begin(), radix[1].end());
        arr.insert(arr.begin() + radix[0].size() + radix[1].size(), radix[2].begin(), radix[2].end());
        arr.insert(arr.begin() + radix[0].size() + radix[1].size() + radix[2].size(), radix[3].begin(), radix[3].end());
        arr.insert(arr.begin() + radix[0].size() + radix[1].size() + radix[2].size() + radix[3].size(), radix[4].begin(), radix[4].end());
    }
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