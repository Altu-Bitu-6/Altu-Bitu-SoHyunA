#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack <int> plusAB(string& a, string& b) {
    stack <int> a_s; stack <int> b_s; 
    stack <int> ab;//a+b값을 반환할 stack

    //a,b-일의 자리수부터 int형으로 스택에 push
    for (int i = 0; i < a.length(); i++)
        a_s.push(a[i]-'0');
    for (int i = 0; i < b.length(); i++)
        b_s.push(b[i]-'0');
    
    int up = 0;//올림수
    while (true) {
        if (a_s.empty() && b_s.empty()) { 
            if(up!=0)
                ab.push(up);
            return ab;
        }
        else if (a_s.empty()) {
            ab.push((b_s.top() + up) % 10);
            up = (b_s.top() + up) / 10;
            b_s.pop();
        }
        else if (b_s.empty()) {
            ab.push((a_s.top() + up) % 10);
            up = (a_s.top() + up) / 10;
            a_s.pop();
        }
        else {
            ab.push((a_s.top() + b_s.top() + up) % 10);
            up = (a_s.top() + b_s.top() + up) / 10;
            a_s.pop(); b_s.pop();
        }
    }

}
int main()
{
    string a, b; cin >> a >> b;
    stack <int> ab = plusAB(a, b);
    
    while (!ab.empty()) {
        cout << ab.top();
        ab.pop();
    }
    return 0;
}
