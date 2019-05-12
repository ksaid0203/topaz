#include <iostream>
#include <fstream>
#define endl '\n'
using namespace std;

int minNuturious[6];
int arr[25][6];
int n;

void input();
int solve();
void output(const int answer);

int main() {
    input();
    auto answer = solve();
    output(answer);
    for(int i = 0 ; i < 100000000; i += 1) {
        ;
    }
    return 0;
}

void input() {
    ifstream inp("diet.inp");
    ios_base::sync_with_stdio(false);
    inp.tie(NULL);

    inp >> n;

    for(int i = 0 ; i < 4; i += 1) {
        inp >> minNuturious[i];
    }
    for(int i = 0 ; i < n ; i += 1) {
        for(int j = 0 ; j < 5 ; j += 1) {
            inp >> arr[i][j];
        }
    }

    inp.close();
}

int solve() {
    bool flag = true;
    int cost = 987654321;
    int ret = 0, j = 0, tmp = 0, cnt = 0, cand = 0;
    for(int i = 1 ; i < ((1 << n) - 1) ; i += 1) {
        tmp = i; cnt = 0; cand = 0;
        int arr2[5] = {0,};
        while(tmp > 0) {
            if(tmp % 2 == 1) {
                for(j = 0 ; j < 4; j += 1)
                    arr2[j] += arr[cnt][j];
                cand += arr[cnt][4];
            }
            tmp >>= 1;
            cnt += 1;
        }
        flag = true;
        for(j = 0 ; j < 4 ; j += 1) {
            if(minNuturious[j] > arr2[j]) {
                flag = false;
                break;
            }
        }
        if(flag && cost > cand) {
            cost = cand;
            ret = i;
        }
    }
    return ret;
}

void output(const int answer) {
    ofstream out("diet.out");
    int tmp = answer, cnt = 1;
    while(tmp > 0 || cnt <= n) {
        if(tmp % 2 == 1) {
            out << cnt << ' ';
        }
        tmp >>= 1;
        cnt += 1;
    }
    out.close();
}