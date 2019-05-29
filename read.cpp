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
    //ifstream inp("C:\\Users\\ksaid\\Downloads\\4-1\\algorithm\\sampleData12\\1.inp");
    ifstream inp("read.inp");
    //int maxLen = 0;
    while(inp >> str) {
        //maxLen = max(maxLen, (int)str.size());
        arr.emplace_back(str);
    }
    inp.close();
    sort(arr.begin(), arr.end());
    string cand(arr[0]);
    int cnt1 = 0, cnt2 = 0;
    arr.emplace_back("0000");
    vector<string> ans;

    for(auto it = arr.begin(); it != arr.end(); ++it) {
        if(it == arr.begin()) {
            ++cnt2;
            continue;
        }
        auto it2 = it - 1;
        if(*it2 == *it) {
            ++cnt2;
        }
        else {
            if(cnt1 == cnt2) {
                ans.emplace_back(*it2);
            }
            else if(cnt1 < cnt2) {

                ans.clear();
                cnt1 = cnt2;
                ans.emplace_back(*it2);
            }
            cnt2 = 1;
        }
    }

    ofstream out("read.out");
    out << ans[0] << endl;
    out.close();
    return 0;
}