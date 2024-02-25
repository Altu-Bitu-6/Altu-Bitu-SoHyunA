#include <iostream>
#include <unordered_map>

using namespace std;
int main()
{

    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    unordered_map<string, int> um;
    string name, kind;
    while (t--) {
        int n; cin >> n;
        while (n--) {
            cin >> name >> kind;
            if (um.find(kind) != um.end()) 
                um[kind]++;
            else 
                um[kind] = 1;
        }
        int result = 1;
        for (auto iter = um.begin(); iter != um.end(); iter++) {
            result = result * (iter->second + 1);
        }
        cout << result-1 << "\n";
        um.clear();
    }
    return 0;
}
