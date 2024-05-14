#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
int checkLight(vector <int>& v,int n, int k) {
    //가능 -> 1 , 불가능 -> 0
    for (int i = 0; i < v.size(); i++) {
        if (i == 0) {
            if((v[i]-k)>0){
                return 0;
            }
        }
        if (i == v.size() - 1) {
            if (v[i] + k < n) {
                return 0;
            }
        }
        else {
            if (v[i+1] - v[i] > 2 * k) {
                return 0;
            }
        }
    }
    return 1;
}

int BinarySearch(vector <int>& v, int n) {
    int left = 0; int right = n;
    while (left <= right) {
        int mid = (left + right) / 2;
        int light = checkLight(v,n, mid);
        if (light) {//가능 -> 최소
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return right +1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n,m; cin >> n >> m;
    vector <int> v(m);
    for (int i = 0; i < m; i++) {
        cin >> v[i];
    }
    cout << BinarySearch(v, n);

    return 0;
}