//
// Created by ksaid on 2019-06-04.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <stack>
using namespace std;
#define endl '\n'
typedef pair<int, int> pii;
int n = 0, cnt = 0;
vector<pii> arr;

vector<pii> arr2;

// signed area의 또 다른 표현
inline int ccw(const pii & a, const pii & b, const pii & c) {
    int temp = a.first * b.second + b.first * c.second + c.first * a.second;
    temp = temp - a.second * b.first - b.second * c.first - c.second * a.first;
    if (temp > 0) {
        return 1; // clockwise 반시계방향
    } else if (temp < 0) {
        return -1; // clock 시계방향
    } else {
        return 0; // 180도 일직선
    }
}
bool cmp(const pii & a, const pii & b) {
    if(b.second == a.second) {
        return a.first < b.second;
    }
    return a.second < b.second;
}

bool cmp2(const pii & a, const pii & b) {
    if(a.second * b.first != a.first * b.second) {
        return a.second * b.first < a.first * b.second;
    }
    return cmp(a, b);
}

int convexHull() {
    int ret = 0;
    for(int i = 0 ; i < n ; ++i) {
        int tmp = ccw(arr[i % n], arr[(i + 1) % n], arr[(i + 2) % n]);
        if(tmp > 0) {
            ++ret;
        }
    }
    return ret;
//    sort(arr.begin(), arr.end(), cmp);
//    arr2.resize(n);
//    arr2[0] = arr[0];
//    for(int i = 1 ; i < n ; i += 1) {
//        arr2[i].first = arr[i].first - arr[0].first;
//        arr2[i].second = arr[i].second - arr[0].second;
//    }
//    sort(arr2.begin() + 1, arr2.end(), cmp2);
//    stack<int> s;
//    s.push(0);
//    s.push(1);
//    int next = 2;
//    while(next < n) {
//        while(s.size() >= 2) {
//            int first = 0, second = 0;
//            first = s.top(); s.pop();
//            second = s.top();
//            int cand = ccw(arr2[second], arr2[first], arr2[next]);
//            if(cand > 0){
//                s.push(first);
//                break;
//            }
//        }
//        s.push(next);
//        next += 1;
//    }
//    return n - s.size();
}

int main() {
    //ifstream inp("polygon.inp");
    ifstream inp("C:\\Users\\ksaid\\Downloads\\4-1\\algorithm\\sampleData13\\3.inp");
    ios_base::sync_with_stdio(false);
    inp.tie(NULL);

    inp >> n;
    arr.resize(n);
    for(int i = 0 ; i < n ; i += 1) {
        inp >> arr[i].first >> arr[i].second;
    }
    inp.close();

    bool None = false;
    for(int i = 0 ; i < n ; i += 1) {
        //cout << i << ' ' << j << ' ' << k << ' ' << l << endl;
        int j = (i + 1) % n;
        for(int k = (j + 1); k < n ; k += 1) {
            int l = (k + 1) % n;
            if(ccw(arr[i], arr[j], arr[k]) * ccw(arr[i], arr[j], arr[l]) < 0 &&
               ccw(arr[k], arr[l], arr[i]) * ccw(arr[k], arr[l], arr[j]) < 0) {
                None = true;
            }
        }

        //int k = (j + 1) % n;
    }

    ofstream out("polygon.out");
    if(None) {
        out << "None" << endl;
    }
    else {
        auto answer = convexHull();
        if(answer == 0) {
            out << "Convex" << endl;
        }
        else {
            out << "Concave " << answer << endl;
        }
    }
    out.close();
    return 0;
}