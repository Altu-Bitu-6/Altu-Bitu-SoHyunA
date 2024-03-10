#include <iostream>

using namespace std;

int checkSIX(int i) {
    int a = 0;
    while (i / 10) {
        if (i % 10 == 6) {
            a++;
            if (a == 3) {
                return 1;
            }
        }
        else {
            a=0;
        }
        i /= 10;
    }
    if (i % 10 == 6) {
        a++;
        if (a == 3) {
            return 1;
        }
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    int check; int cnt=0;
    for (int i = 666; ; i++) {
        check =checkSIX(i);
        if (check) {
            cnt++; 
            if (cnt == n) {
                cout << i;
                return 0;

            }
        }
    }
}
