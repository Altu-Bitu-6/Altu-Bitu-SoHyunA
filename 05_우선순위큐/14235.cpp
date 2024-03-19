#include <iostream>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    int a,x;
    priority_queue <int> q;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a == 0) {//아이들
            if (q.empty()) {
                cout << "-1\n";
            }
            else {
                cout << q.top() << "\n";
                q.pop();
            }
        }
        else {//거점지
            while (a--) {
                cin >> x;
                q.push(x);
            }
        }
    }
    return 0;
}


