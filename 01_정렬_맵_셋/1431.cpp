#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int sumNumber(string st){
    int sum =0;
    for(int i=0; i<st.length();i++){
        if(st[i]<65)
            sum+=(int)st[i]-48;
    }
    return sum;
}

bool cmp(string x,string y){
    if(x.length()!=y.length())
        return x.length() < y.length();
        
    int x_sum = sumNumber(x);
    int y_sum = sumNumber(y);
    if(x_sum!=y_sum)
       return x_sum < y_sum; 
    else
        return x < y;
}

int main()
{
    int n;
    cin >> n;
    vector <string> num (n,"0");
    for(int i=0; i<n;i++){
        cin >> num[i];
    }
    sort(num.begin(),num.end(),cmp);
    for(int i=0; i<n;i++){
        cout << num[i] << '\n';
    }
    return 0;
}