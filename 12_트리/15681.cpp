#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
vector <bool> visited; 
vector <int> cnt; //서브트리에 속한 정점의 수 

int makeTree(vector <vector<int>> &v,int k) {
    visited[k] = true;
    int c = 0;
    for (int i : v[k]) {
        if (!visited[i]) {
            visited[i] = true;
            int p = makeTree(v,i);
            c += p+1;
        }
    }
    cnt[k] = c;
    return c;//자식 노드의 수 반환
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, r, q; cin >> n >> r >> q;
    vector <vector<int>> v(n + 1);
    int x, y;
    for (int i = 0; i < n-1; i++) {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    visited.assign(n + 1,false);
    cnt.assign(n + 1, 0);
    makeTree(v,r);
    
    for (int i = 0; i < q; i++) {
        cin >> x;
        cout << cnt[x]+1 << "\n";
    }
    return 0;
}