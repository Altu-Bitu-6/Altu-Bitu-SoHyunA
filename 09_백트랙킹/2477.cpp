#include <iostream>
#include <queue>
#include <vector>
#include <set>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    
    int k; cin >> k;
    int t;
    vector <int> v(6);
    int x = 0; int x_idx;
    int y = 0; int y_idx;

    for (int i = 0; i < 6; i++) {
        cin >> t;
        if (t > 2) {//남,북 - 최대길이 x
            cin >> v[i];
            if (v[i] > x) {
                x = v[i]; x_idx = i;
            }
        }
        else {//동,서 - 최대길이 y
            cin >> v[i];
            if (v[i] > y) {
                y = v[i]; y_idx = i;
            }
        }
    }
    //전체 x*y에서 빠지는 사각형의 x,y인덱스 
    x_idx = (x_idx + 3) % 6;
    y_idx = (y_idx + 3) % 6;

    cout << k*(x * y - v[x_idx] * v[y_idx]);

    return 0;
}