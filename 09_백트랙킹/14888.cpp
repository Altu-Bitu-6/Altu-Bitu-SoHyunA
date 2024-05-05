#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;
int n;
vector <int> v;    //n개의 수
vector <int> c(4); //연산자의 개수 

long long max_s = -1000000000;
long long min_s = 1000000000;

long long calculate(long long sum, int i, int idx) {
    switch (i) {
    case 0:
        sum = sum + v[idx];
        break;
    case 1:
        sum = sum - v[idx];
        break;
    case 2:
        sum = sum * v[idx];
        break;
    case 3:
        sum = sum / v[idx]; 
        break;
    }
    return sum;
}

void findMinMax(long long sum, int idx) {
    if (idx == n) {
        if (sum < min_s) {
            min_s = sum;
        }
        if (sum > max_s) {
            max_s = sum;
        }
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (!c[i]) {//연산자 사용 불가
            continue;
        }
        else {
            c[i]--;
            findMinMax(calculate(sum, i,idx),idx+1);
            c[i]++; //원상복귀
        }
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    v.assign(n,0);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> c[i];
    }
    findMinMax(v[0],1);

    cout << max_s << "\n" << min_s;
    return 0;
}