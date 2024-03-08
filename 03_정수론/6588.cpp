#include <iostream>
#include <vector>
#include <math.h> 

const int MAX_SIZE = 1000000;
using namespace std;

int main()
{
    //입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector <bool> v(MAX_SIZE, true);
    int check = 2;
    bool prt = true;
    while (true) {
        int n; cin >> n;
        if (!n) { //0 입력시 종료
            return 0;
        } 
        if (n > check) { 
            for (int i = check+1; i <= sqrt(MAX_SIZE); i += 2) {//홀수만 체크함 => 3부터
                if (v[i]) {
                    for (int j = i * i; j < MAX_SIZE; j += i * 2) {
                        v[j] = false;
                    }
                }
            }
        }
        
        check = n; // n까지 소수 검사 완료

        // 3 n-3, 5, n-5,..., n/2 n/2
        // 둘다 소수 = > true 
        for (int i = 3; i <= n / 2; i += 2) {
            if (v[i] and v[n - i]) {
                cout << n << " = " << i << " + " << n - i << "\n";
                prt = false;  break;
            }
        }
        if (prt) {
            cout << "Goldbach's conjecture is wrong.";
        }
    }
}
