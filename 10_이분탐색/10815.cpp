#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int BinarySearch(vector <int>& v, int n, int t) {
    int left = 0; int right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (v[mid] == t) {//존재
            return 1; 
        }
        else if (v[mid] < t) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return 0;//존재x
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    vector <int> v(n);
    for (int i = 0; i < n; i++) { //숫자카드 입력
        cin >> v[i];
    }
    sort(v.begin(), v.end()); //이분탐색을 위한 정렬

    int m; cin >> m;
    int t;
    for (int i = 0; i < m; i++) {
        cin >> t;
        cout << BinarySearch(v, n,t) << " "; //검사
    }

    return 0;
}