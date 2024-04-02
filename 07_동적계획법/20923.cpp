#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

void checkCard(deque <int> &ddg, deque <int> &dsg, deque <int>& dd, deque<int>& ds) {
        //도도가 종을 치는 경우
        if ((!ddg.empty() and ddg.front() == 5) or (!dsg.empty() and dsg.front() == 5)) {
            //수연이의 그라운드 카드를 도도의 덱으로
            while (!dsg.empty()) {
                dd.push_back(dsg.back());
                dsg.pop_back();
            }
            while (!ddg.empty()) {
                dd.push_back(ddg.back());
                ddg.pop_back();
            }
        }
        //수연이가 종을 치는 경우 
        else if (!dsg.empty() and !ddg.empty() and ddg.front() + dsg.front() == 5) {
            //도도의 그라운드 카드를 수연이의 덱으로
            while (!ddg.empty()) {
                ds.push_back(ddg.back());
                ddg.pop_back();
            }
            while (!dsg.empty()) {
                ds.push_back(dsg.back());
                dsg.pop_back();
            }
        }
}
string playGame(deque <int>& dd, deque<int>& ds, int m) {
    //도도의 그라운드 카드, 수연이의 그라운드 카드 
    deque <int> ddg; deque<int> dsg;
    int i = 0;
    while(i<m) {
        ddg.push_front(dd.front()); dd.pop_front();
        if (dd.size() == 0) {
            return "su";
        }
        checkCard(ddg, dsg, dd, ds);
        i++;

        if (i == m) {
            break;
        }

        dsg.push_front(ds.front()); ds.pop_front();
        if (ds.size() == 0) {
            return "do";
        }
        checkCard(ddg, dsg, dd, ds);
        i++;
    }
    //덱에 있는 카드의 개수 비교
    if (dd.size() == ds.size()) {
        return "dosu";
    }
    else if (dd.size() > ds.size()) {
        return "do";
    }
    else {
        return "su";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n,m; cin >> n >>m;
    deque <int> dd;
    deque <int> ds;

    int d, s;
    for (int i = 0; i < n; i++) {
        cin >> d >>s;
        dd.push_front(d);
        ds.push_front(s);
    }
    cout << playGame(dd, ds, m);

    return 0;
}
