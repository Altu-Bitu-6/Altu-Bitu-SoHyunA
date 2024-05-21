#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> v_cnt; //초밥의 종류 벡터

int vCount(vector <int> v) {
    int cnt = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i]) {
            cnt++;
        }
    }
    return cnt;
}

int findKind(vector <int>& v, int k, int c) {
    int max = 0;

    for (int i = 0; i < v.size(); i++) {
        if (i > k - 1) {
            v_cnt[v[i - k]]--;
        }
        v_cnt[v[i]]++;
        if (max < vCount(v_cnt)) {
            max = vCount(v_cnt);
        }
    }

    for (int i = 0; i < k-1; i++) {
        v_cnt[v[i]]++;
        v_cnt[v[v.size() - k + i]]--;
        
        if (max < vCount(v_cnt)) {
            max = vCount(v_cnt);
        }
    }

    return max;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, d, k, c; cin >> n >> d >> k >> c;
    v_cnt.assign(d+1, 0); v_cnt[c]++;

    //입력
    vector <int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    cout << findKind(v, k, c);
    return 0;
}