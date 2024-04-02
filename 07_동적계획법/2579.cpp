#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int stair(vector <int>& v,int n) {
    vector <int> dp(n+1);
    dp[0] = 0;dp[1]= v[1]; dp[2] = v[1] + v[2];//최댓값 저장
    for (int i = 3; i <= n; i++) {
        dp[i] = max(dp[i - 3]+v[i-1], dp[i - 2]) + v[i];
    }
    return dp[n];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n ;
    vector <int> v(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    cout << stair(v,n);
    return 0;
}
