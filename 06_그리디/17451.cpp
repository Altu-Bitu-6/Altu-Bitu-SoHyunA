#include <iostream>
#include <string>
#include <deque>
#include <vector>

using namespace std;

long speed(deque <int>& q) {
    long cmp = 0;
    while (!q.empty()) {
        while (!q.empty() and q.back() > cmp) {
            cmp = q.back();
            q.pop_back();
        }
        if (!q.empty()) {
            if (cmp % q.back() == 0) {
                cmp = q.back() * (cmp / q.back());
            }
            else {
                cmp = q.back() * (cmp / q.back() + 1);
            }
            q.pop_back();
        }
    }
    return cmp;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    deque <int> q; int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        q.push_back(x);
    }
    cout << speed(q);
    return 0;
}
