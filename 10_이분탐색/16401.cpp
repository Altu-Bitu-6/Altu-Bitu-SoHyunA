#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int checkSnack(vector <int> v,int m, int k) {
    //m명에게 k길이 만큼 줄 수 있는지
    for (int i = 0; i < v.size(); i++) {
        while ((v[i] - k) >= 0) {
            v[i] -= k;
            m--;
            if (m == 0) {
                return 1;
            }
        }
    }
    return 0;
}

int BinarySearch(vector <int>& v, int n,int m) {
    int left = 0; int right = v[n-1];
    while (left <= right) {
        if (right == 0) {//막대 과자를 나눠줄 수 없을 때
            return 0;
        }
        int mid = (left + right) / 2;
        int snack = checkSnack(v, m, mid); 
        if (snack) {//가능 -> 최대
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return left -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n,m; cin >> m >> n;
    vector <int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    cout << BinarySearch(v, n,m);

    return 0;
}