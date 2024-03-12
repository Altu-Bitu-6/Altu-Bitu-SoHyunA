#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    string input; int x;
    long s = 0;
    for (int i = 0; i < n; i++) {
        cin >> input;
        if (input == "add") {
            cin >> x;
            s = s | (long)1 << x;
        }
        else if (input == "remove") {
            cin >> x;
            s = s & ~((long)1 << x);
        }
        else if (input == "check") {
            cin >> x;
            if (s & ((long)1 << x)) {
                cout << "1\n";
            }
            else {
                cout << "0\n";
            }
        }
        else if (input == "toggle") {
            cin >> x;
            if (s & ((long)1 << x)) {
                s = s & ~((long)1 << x);
            }
            else {
                s = s | ((long)1 << x);
            }
        }
        else if (input == "all") {
            s = ~(long)0;
            
        }
        else if (input == "empty") {
            s = (long)0;
        }
        
    }
}
