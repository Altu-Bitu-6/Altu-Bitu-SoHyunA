#include <iostream>
#include <vector>
#include <math.h> 
#include <deque>

using namespace std;

int check_max_p(int b, int s) {
    if (b < s) {
        swap(b, s);
    }
    while (s) {
        swap(b, s);
        s = s % b;
    }
    return b;
}
int main()
{
    //입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    vector <int> v(n);
    cin >> v[0] >> v[1];
    int p = abs(v[0] - v[1]);

    //2개씩 짝지어 차이의 최대공약수 구하기
    for (int i = 2; i < n - 1; i +=2) {
        cin >> v[i] >> v[i + 1];
        p=check_max_p(p, abs(v[i] - v[i + 1]));
    }
    if (n / 2) { //홀수일때 마지막 하나 따로 
        cin >> v[n - 1];
        p = check_max_p(p, abs(v[n-2] - v[n - 1]));
    }
    
    //p의 약수 구하기 
    deque <int> d;
    for (int i = sqrt(p); i >1; i--) {
        if (!(p % i)) {
            if (p == i * i) {
                d.push_front(i);
            }
            else {
                d.push_front(i);
                d.push_back(p / i);
            }
        }
    }
    d.push_back(p);
    
    while (!d.empty()) {
        cout << d.front()<<" "; d.pop_front();
    }

}
