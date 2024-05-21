#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
int cnt = 0;

void clean(vector <vector<int>>& v,int r,int c, int d) {
    if (v[r][c]==0) {//청소 x인 상태
        cnt++;
        v[r][c] = 2;//청소 o
    }
    //주변 검사
    for (int i = 0; i < 4; i++) {
        //반시계 회전
        d--;
        if (d == -1) {
            d = 3;
        }
        //d에 따라서 청소 x인지 확인
        switch (d) {
        case 0:
            if (!v[r - 1][c]) {
                clean(v, r - 1, c, d);
                return;
            }
            break;
        case 1:
            if (!v[r][c + 1]) {
                clean(v, r, c + 1, d);
                return;
            }
            break;
        case 2:
            if (!v[r + 1][c]) {
                clean(v, r + 1, c, d);
                return;
            }
            break;
        case 3:
            if (!v[r][c - 1]) {
                clean(v, r, c - 1, d);
                return;
            }
            break;
        }
    }

    //후진 체크
    switch (d) {
    case 0:
        if (v[r + 1][c]!=1) {
            clean(v, r + 1, c, d);
            return;
        }
        break;
    case 1:
        if (v[r][c - 1] != 1) {
            clean(v, r, c - 1, d);
            return;
        }
        break;
    case 2:
        if (v[r - 1][c] != 1) {
            clean(v, r - 1, c, d);
            return;
        }
        break;
    case 3:
        if (v[r][c + 1] != 1) {
            clean(v, r, c + 1, d);
            return;
        }
        break;
    }

    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    int r, c, d; cin >> r >> c >> d;

    vector <int> vv(m);
    vector <vector<int>> v(n, vv);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    clean(v,r,c,d);
    cout << cnt;

    return 0;
}