#include <iostream>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;
const int MAX = 26;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    int cnt = 0; n--;
    string input; cin >> input;
    map <char, int> input_v;//(알파벳,개수)
    for (int i = 0; i < input.length(); i++) {
        input_v[input[i]]++;
    }

    string str;
    map <char,int> v;//(알파벳,개수)
    while (n--) {
        cin >> str;
        for (int i = 0; i < str.length(); i++) {
            v[str[i]]++;
        }
        bool check = true; //같은 구성
        int check_one = 0; // 한 문자 +-
        int check_1 = 0; int check_2 = 0; //하나의 문자 바꿈

        for (char i = 'A'; i <= 'Z'; i++) {
            if (input_v[i] != v[i]) {
                check = false;
                if (input_v[i] - v[i] == 1) {
                    check_one++; check_1++;
                }
                else if (input_v[i] - v[i] == -1) {
                    check_one++; check_2++;
                }
                else {
                    check_one = 2; check_1 = 2;
                }
                if (check_1 == 2 or check_2 == 2) {
                    break;
                }
            }
        }
        if (check or (check_one<2) or (check_1 - check_2 == 0)) {
            cnt++; 
        }
        v.clear();
    }

    cout << cnt;
    return 0;
}


