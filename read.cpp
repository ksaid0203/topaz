//
// Created by ksaid on 2019-05-27.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;
#define endl '\n'

/**
 * 버킷정렬의 한 부분
 * @param arr bucket들
 * @param i 내가 관심있는 index
 */
void radix(vector<queue<string> > & arr, const int i) {
    vector<int> cnt;
    for(int j = 0 ; j < 6 ; j += 1) {
        cnt.emplace_back(arr[j].size());
    }
    for(int j = 0 ; j < 6 ; j += 1) {
        for(int k = 0 ; k < cnt[j] ; k += 1) {
            auto tmp = arr[j].front();
            if(tmp.size() <= i) {
                arr[0].emplace(tmp);
            }
            else if(tmp[i] == 'a') {
                arr[1].emplace(tmp);
            }
            else if(tmp[i] == 'c') {
                arr[2].emplace(tmp);
            }
            else if(tmp[i] == 'g') {
                arr[3].emplace(tmp);
            }
            else if(tmp[i] == 'n') {
                arr[4].emplace(tmp);
            }
            else if(tmp[i] == 't') {
                arr[5].emplace(tmp);
            }
            arr[j].pop();
        }
    }
}

/**
 * bucket 내용을 vector로 전달합니다. 그냥 버킷 채로 해도 되는데, 앞전에 구현해 놓은 함수가 vector를 인자로 해서
 * vector 형태로 합니다.
 * @param arr bucket들
 * @param here 데이터를 전달받을 vector
 */
void queue2vector(vector<queue<string> > & arr, vector<string> & here) {
    for(auto x : arr) {
        while(!x.empty()) {
            here.emplace_back(x.front());
            x.pop();
        }
    }
}

/**
 * 최빈값을 반환
 * @param here 정렬된 배열
 * @return 정렬 결과의 최빈값
 */
string solve(const vector<string> & here) {
    string ans;
    int cnt1 = 0, cnt2 = 1;
    for(auto it = here.begin() + 1 ; it != here.end(); ++it) {
        auto it2 = it - 1;
        if(*it2 == *it) {
            ++cnt2;
        }
        else {
            if(cnt1 < cnt2) {
                cnt1 = cnt2;
                ans = *it2;
            }
            cnt2 = 1;
        }
    }
    return ans;
}

int main() {
    vector<queue<string>> arr(6, queue<string>());
    vector<string> here;
    string str;

    ifstream inp("read.inp");
    ios_base::sync_with_stdio(false);
    inp.tie(NULL);
    int maxLen = 0;
    while(getline(inp, str)) {
        maxLen = max(maxLen, (int)str.size());
        arr[0].emplace(str);
    }
    inp.close();

    for(int i = maxLen - 1 ; i >= 0 ; i -= 1) {
        radix(arr, i);
    }

    queue2vector(arr, here);
    here.emplace_back("0000");

    ofstream out("read.out");
    out << solve(here) << endl;
    out.close();
    return 0;
}