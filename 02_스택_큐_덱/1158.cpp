#include <iostream>
#include <queue>

using namespace std;
int main()
{
    int n, k; cin >> n >> k;

    queue <int> q;
    //큐에 1~n값 push
    for (int i = 1; i < n+1; i++) {
        q.push(i);
    }
    cout << "<";
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < k - 1; j++) { //k-1개 만큼 큐에 다시 push하고 pop
            q.push(q.front());
            q.pop();
        }
        cout << q.front()<<", "; //k번째 값 출력 후 pop
        q.pop();
    }
    cout << q.front() << ">";
    return 0;
}
