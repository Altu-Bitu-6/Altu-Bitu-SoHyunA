#include <iostream>

using namespace std;

int get_div(int b, int s) {
    if (b < s)
        swap(b, s);
    while (b % s) {
        swap(b, s);
        s = s % b;
    }
    return s;
}

int main()
{
    //입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //분자, 분모 입력 
    int a, b; cin >> a >> b;
    int c, d; cin >> c >> d;
   
    int e, f;
    e = a * d + b * c;
    f = b * d;

    //e와 f의 최대 공약수 찾기
    int div = get_div(e,f);

    cout << e / div << " " << f / div;

    return 0;
}
