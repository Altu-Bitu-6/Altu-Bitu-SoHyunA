#include <iostream>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;
//minHeap
struct cmp {
    bool operator() (const int& a, const int& b) {
        return a > b;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;

    priority_queue <int,vector <int>,cmp> v; int x;
    for (int i = 0; i < n*n; i++) {
        cin >> x;
        v.push(x);
        while (v.size() > n) {
            v.pop();
        }
    }
    cout << v.top();
    return 0;
}



