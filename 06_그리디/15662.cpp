#include <iostream>
#include <string>
#include <deque>
#include <vector>

using namespace std;
typedef pair<int, int> ci;
void changeR(string &v, int n) {//1-시계, -1-반시계
    int t;
    if (n == 1) {
        t = v[7];
        for (int i = 7; i >0; i--) {
            v[i] = v[i - 1];
        }
        v[0] = t;
    }
    else {
        t = v[0];
        for (int i = 0; i <7; i++) {
            v[i] = v[i + 1];
        }
        v[7] = t;
    }
}
int circle(vector<string> &v, vector<ci> &vc) {
    for (int i = 0; i < vc.size(); i++) {
        //왼쪽으로 
        int left = 0; int leftIdx = v[vc[i].first - left][6];
        int left_dir = -vc[i].second;
        while (vc[i].first -left!= 1) {//존재 확인
            if (leftIdx != v[vc[i].first - left - 1][2]) {
                leftIdx = v[vc[i].first - left - 1][6];//회전 전 저장
                changeR(v[vc[i].first -left- 1], left_dir);//회전
                left++; left_dir = -left_dir; //한칸 + +, 방향 반대로 
            }
            else {
                left = vc[i].first - 1;
            }
        }
        //오른쪽으로
        int right = 0;  int rightIdx = v[vc[i].first + right][2];
        int right_dir = -vc[i].second;
        while (vc[i].first +right!= v.size() - 1) {//존재 확인
            if (rightIdx != v[vc[i].first + right + 1][6]) {
                rightIdx = v[vc[i].first + right + 1][2]; //회전 전 저장
                changeR(v[vc[i].first+right + 1], right_dir);//반대로 회전
                right++; right_dir = -right_dir;//한칸 + +, 방향 반대로
            }
            else {
                right = v.size() - 1 - vc[i].first;
            }
        }
        //회전 바퀴
        changeR(v[vc[i].first], vc[i].second);
        
    }
    int cnt = 0;
    for (int i = 1; i < v.size(); i++) {
        if (v[i][0] == '1') {
            cnt++; 
        }
    }
    
    return cnt;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    vector<string> v(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    cin >> n;
    vector<ci> vc(n);
    for (int i = 0; i < n; i++) {
        cin >> vc[i].first >> vc[i].second;
    }
    cout << circle(v,vc);
    return 0;
}
