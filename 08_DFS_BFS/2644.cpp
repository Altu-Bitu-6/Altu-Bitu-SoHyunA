#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;
int n, a, b;
vector <bool> check;
int ans = -1;

void dfs(int index, int cnt,vector <vector<int>>& v) {
    if (index == b) {
        ans = cnt;
        return ;
    }
    check[index] = true;
    for (int i = 1; i <= n; i++) {
        if (v[index][i] == 1 and !check[i]) {
            dfs(i, cnt + 1, v);
        }
    }
    return ;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int k; cin >> n>>a>>b>>k;
    
    vector <vector<int>> v(n+1,vector<int>(n+1,0));
    check.assign(n + 1, false);

    int x, y;
    for (int i = 0; i < k; i++) {
        cin >> x >> y;
        v[x][y] = v[y][x] = 1;
    }
    dfs(a,0,v);

    cout << ans;

    return 0;
}