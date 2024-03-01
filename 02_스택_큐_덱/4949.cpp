#include <iostream>
#include <string>
#include <stack>

using namespace std;

void checkBalance(string &str) {
    stack <char> s;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(')
            s.push('(');
        else if (str[i] == ')') {
            if (s.empty() or (s.top() != '(')) {
                s.push(')'); break; //s.empty()를 false로 하기위함
            }
            else
                s.pop();
        }
        else if (str[i] == '[')
            s.push('[');
        else if (str[i] == ']') {
            if (s.empty() or (s.top() != '[')) {
                s.push(']'); break; //s.empty()를 false로 하기위함
            }
            else
                s.pop();
        }
    }
    if (s.empty())
        cout << "yes\n";
    else
        cout << "no\n";

    while (!s.empty())//다음 입력 전, stack 비우기
        s.pop();
}


int main()
{
    while (true) {
        string str; getline(cin, str, '.'); //개행문자 '.'
        if (str.length() == 1)//'.'입력시 종료
            return 0;
        checkBalance(str);
    }
    return 0;
}
