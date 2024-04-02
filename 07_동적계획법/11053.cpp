#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int longG(vector <int>& v,int n) {
    //v[i]를 포함하는 수열의 최대 길이
    vector <int> dp(n + 1); 
    int total_max = 0; dp[1] = 1; 
    for (int i = 2; i <= n; i++) {
        //초기화 
        int max = 0; int one=1;
        for (int j = i-1; j > 0; j--) {
            if (v[j] < v[i]) {
                one= dp[j] + 1; 
            }
            if (max < one) {
                max = one;
            }
        }
        dp[i] = max; //저장

        //최대 길이 반영
        if (total_max < dp[i]) {
            total_max = dp[i];
        }
    }
    return total_max;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n ;
    vector <int> v(n+1,0);
    for (int i = 1; i < n+1; i++) {
        cin >> v[i];
    }

    cout << longG(v,n);
    return 0;
}
