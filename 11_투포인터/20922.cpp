#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 100000;

vector <int> v_cnt(MAX);

int findLong(vector <int>& v, int k) {
    int max = 0;
    int start_idx = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v_cnt[v[i]] == k) {
            while (v[start_idx] != v[i]) {
                v_cnt[v[start_idx]]--;
                start_idx++;
            }
            start_idx++;
        }
        else {
            v_cnt[v[i]]++;
        }
        //최대 길이 업데이트 
        if (max < i - start_idx+1) {
            max = i - start_idx+1; 
        }
    }
    return max;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k; cin >> n >> k;

    vector <int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    cout << findLong(v, k);
    return 0;
}