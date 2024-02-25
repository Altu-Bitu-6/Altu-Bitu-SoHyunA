#include <iostream>
#include <map>

using namespace std;
int main()
{

    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;

    map<int, int> rank;
    int a, b;
    while (t--) {
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a >> b;
            rank[a] = b;
        }
        int i = 1;        
        int sum = 0;
        for (int j = i + 1; j < n + 1; j++) {
            if (rank[i] > rank[j]) {
                i = j; sum++;
            }
        }
        cout << sum + 1 << "\n";
    }
    return 0;
}
