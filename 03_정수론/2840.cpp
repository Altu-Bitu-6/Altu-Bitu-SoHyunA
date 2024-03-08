#include <iostream>
#include <vector>
using namespace std;

int main()
{
    //입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k; cin >> n >> k;
    vector <char> v(n,'?');
    int p = 0; //화살표가 현재 가르키고 있는 인덱스
    while(k--){
        int s; cin >> s;
        char c; cin >> c;
        p = (p + s) % n;

        //비어있으면 중복 확인하고 입력, 존재하면 일치하는 지 확인
        if (v[p] == '?') {
            for (int i = 1; i < n; i++) {
                if (v[(p - i + n) % n] == c) {
                    cout << "!";
                    return 0;
                }
            }
            v[p] = c;
        }
        else if (v[p] != c) {
            cout << "!";
            return 0;
        }
    }
    for (int i = 0; i <n; i++) {
        cout << v[(p - i + n) % n];
    }
    return 0;
}
