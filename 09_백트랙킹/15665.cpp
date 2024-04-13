#include <iostream>
#include <queue>
#include <vector>
#include <set>

using namespace std;

int n,m;
set <int> s;
vector <int> v;   

void backtracking(int cnt) {
    if (cnt == m) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << "\n";
        return;
    }
    for (auto iter = s.begin(); iter != s.end(); iter++) {
        v.push_back(*iter);
        backtracking(cnt+1);
        v.pop_back();
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    //v.assign(n,0);
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        s.insert(x);
    }
    backtracking(0);
    return 0;
}