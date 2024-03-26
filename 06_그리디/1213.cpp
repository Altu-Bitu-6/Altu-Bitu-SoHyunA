#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;
string makeP(string p) {
    map<char, int> m;
    int n = p.length();
    vector <char> v(n);
    
    //map에 문자별로 몇개인지 입력
    for (int i = 0; i < n; i++) {
        m[p[i]]++;
    }

    //홀수개인 문자의 갯수
    int odd = 0;
    if (n % 2 == 1) odd = 1;

    int cnt = 0; int pt = 0;
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        cnt = iter->second;
        if (cnt % 2 != 0) {
            odd--;
            v[n / 2] = iter->first;//가운데
        }
        for (int i = 0; i < cnt / 2; i++) {
            v[pt + i] = iter->first;//앞
            v[n - 1 - pt - i] = iter->first;//뒤
        }
        pt += cnt / 2;
    }

    string ans = "";
    if (odd == 0) {
        while (n--) {
            ans +=v[n];
        }
    }
    else {
        ans="I'm Sorry Hansoo";
    }
    return ans;
}
int main()
{
    string p; cin >> p;
    string ans =makeP(p);

    cout << ans;
    return 0;
}
