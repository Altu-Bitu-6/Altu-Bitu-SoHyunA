#include <iostream>
#include <vector>
#include <math.h> 
#include <set>

using namespace std;

bool check_s(int a, set <int>& s) {
    int sum = 0;
    //자릿수 분해 후 + sum 값
    while (a / 10) {
        sum += (a % 10) * (a % 10);
        a /= 10;
    }
    sum += (a % 10) * (a % 10);

    //상근수
    if (sum == 1) {
        return true;
    }
    //상근수 x
    int ss = s.size();
    s.insert(sum); 
    if (s.size() == ss) {
        return false;
    }
    
    return check_s(sum, s);
}
int main()
{
    //입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    vector <bool> v(n + 1, true);
    for (int i = 2; i <= sqrt(n); i++) {
        if (v[i]) {
            for (int j = i * i; j < n + 1; j += i) {
                v[j] = false;
            }
        }
    }
    set <int> s; //set이 검색 연산에서 벡터보다 빠름
    for (int i = 7; i < n + 1; i++) {
        if (v[i] and check_s(i, s)) {
            cout << i << '\n';
        }
        s.clear();
    }
}
