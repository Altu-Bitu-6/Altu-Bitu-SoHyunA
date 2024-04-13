#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>


using namespace std;
const int MAX = 19;

int ans_x, ans_y;

bool checkRight(vector <vector<int>>& v,int x, int y, int i,int cnt) {
    if (x == MAX) {
        if (cnt == 5) {
            return true;
        }
        return false;
    }
    if (v[x][y] == i) {
        if (checkRight(v, x+1, y , v[x][y], cnt + 1)) {
            return true;
        }
    }
    else if (cnt == 5) {
        return true;
    }
    return false;
}
bool checkRDia(vector <vector<int>>& v, int x, int y, int i, int cnt) {
    if (x == MAX or y == MAX) {
        if (cnt == 5) {
            return true;
        }
        return false;
    }
    //cout << "cnt" << cnt << "  " << x << " " << y;
    if (v[x][y] == i) {
        //cout <<"cnt" << cnt << "  " << x<<" " << y<<"\n";
        if (checkRDia(v, x + 1, y + 1, v[x][y], cnt+1)) {
            return true;
        }
    }
    else if (cnt == 5) {
        //cout << "?";
        return true;
    }
    return false;
}
bool checkLDia(vector <vector<int>>& v, int x, int y, int i, int cnt) {
    //cout << x;
    if (x == -1 or y == MAX) {
        if (cnt == 5) {
            return true;
        }
        return false;
    }
    //cout << "cnt" << cnt << "  " << x << " " << y;
    if (v[x][y] == i) {
        //cout <<"cnt" << cnt << "  " << x<<" " << y<<"\n";
        if (checkLDia(v, x -1, y +1, v[x][y], cnt + 1)) {
            return true;
        }
    }
    else if (cnt == 5) {
        return true;
    }
    return false;
}
bool checkDown (vector <vector<int>>& v, int x, int y, int i, int cnt) {
    if (y == MAX) {
        if (cnt == 5) {
            return true;
        }
        return false;
    }
    if (v[x][y] == i) {
        if (checkDown(v, x, y + 1, v[x][y], cnt+1)) {
            return true;
        }
    }
    else if (cnt == 5) {
        return true;
    }
    return false;
}

void findWinner(int &w,vector <vector<int>>& v) {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (v[i][j] != 0) {
                if (checkRight(v, i + 1, j, v[i][j], 1)){
                    if (i != 0) {//존재
                        if (v[i - 1][j] != v[i][j]) {
                             w= v[i][j];
                             ans_x = i+1; ans_y = j+1;
                            return ;
                        }
                    }
                    else {
                        w = v[i][j];
                        ans_x = i + 1; ans_y = j + 1;
                        return;
                    }
                }


                if (checkRDia(v, i + 1, j + 1, v[i][j], 1)) {
                    if (i != 0 and j != 0) {
                        if (v[i - 1][j - 1] != v[i][j]) {
                            w = v[i][j];
                            ans_x = i + 1; ans_y = j + 1;
                            return;
                        }
                    }
                    else {
                        w = v[i][j];
                        ans_x = i + 1; ans_y = j + 1;
                        return;
                    }
                }
                if (checkLDia(v, i - 1, j + 1, v[i][j], 1)) {
                    if (i != MAX - 1 and j != 0) {
                        if (v[i + 1][j - 1] != v[i][j]) {
                            w = v[i][j];
                            ans_x = i + 1; ans_y = j + 1;
                            return;
                        }
                    }
                    else {
                        w = v[i][j];
                        ans_x = i + 1; ans_y = j + 1;
                        return;
                    }
                }
                if(checkDown(v, i, j + 1, v[i][j], 1)){
                    if (j != 0) {
                        if (v[i][j - 1] != v[i][j]) {
                            w = v[i][j];
                            ans_x = i + 1; ans_y = j + 1;
                            return;

                        }
                    }
                    else {
                        w = v[i][j];
                        ans_x = i + 1; ans_y = j + 1;
                        return;

                    }
                }
            }
        }
    }
    return ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    vector <vector<int>> v(MAX,vector<int>(MAX,0));

    int x, y;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cin >> v[i][j];
        }
    }
    int winner = 0;
    ans_x = 0; ans_y = 0;
    findWinner(winner,v);

    cout << winner << "\n";
    if (winner) {
        cout << ans_x << " " << ans_y;
    }

    return 0;
}