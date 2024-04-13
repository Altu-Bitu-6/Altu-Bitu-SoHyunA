#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>


using namespace std;

void bfs(int n, vector <vector<int>>& v, vector <bool>& check) {
    queue <int> q;
    q.push(1);
    check[1] = true;

    while (!q.empty()) {
        int cv = q.front();
        q.pop();
        for (int i = 1; i <= n; i++) {
            if (v[cv][i] == 1 && !check[i]) {
                check[i] = true;
                q.push(i); 
            }
        }
        
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n,k; cin >> n>>k;
    
    vector <vector<int>> v(n+1,vector<int>(n+1,0));
    vector <bool> check(n + 1, false);

    int x, y;
    for (int i = 0; i < k; i++) {
        cin >> x >> y;
        v[x][y] = v[y][x] = 1;
    }
    
    bfs(n,v, check);

    int cnt = 0;
    for (int i = 2; i <= n; i++) {
        if (check[i]) {
            cnt++;
        }
    }
    cout << cnt;

    return 0;
}