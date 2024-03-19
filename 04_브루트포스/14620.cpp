#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    int n; cin >> n;

    vector <vector<int>> v1(n);
    vector<int> v2(n);
    //좌표 -> 2차원 벡터 대입
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v2[j];
        }
        v1[i] = v2;
    }
    // 5평 땅의 비용 x, 씨앗 위치 i,j
    struct setting {
        int x;
        int i;
        int j;
    };
    vector <setting> v;

    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            int x= v1[i - 1][j] + v1[i][j - 1] + v1[i][j] + v1[i][j + 1] + v1[i + 1][j];
            v.push_back({x,i,j});
        }
    } 
    
    //겹치지 않는 선에서 가능한 모든 땅 세개 경우의 수 
    //그때의 비용 x를 합해서 set에 대입
    set <int> s;
    for (int i = 0; i <v.size(); i++) {
        for (int j = i+1; j < v.size(); j++) {
            for (int p = j + 1; p < v.size(); p++) {
                if ((abs(v[i].i - v[j].i) + abs(v[i].j - v[j].j)) >= 3 && (abs(v[p].i - v[j].i) + abs(v[p].j - v[j].j)) >= 3 && (abs(v[i].i - v[p].i) + abs(v[i].j - v[p].j)) >= 3) {
                    s.insert(v[i].x + v[j].x + v[p].x);
                }
            }
        }
    }

    // 그중 최소 비용 출력
    cout << *s.begin();




}