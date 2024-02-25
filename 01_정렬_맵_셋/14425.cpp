#include <iostream>
#include <unordered_map>

using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    
    unordered_map <string,int> u_map;
    unordered_map <string,int>::iterator findIter;
    string input;
    int sum=0;
    
    for (int i=0;i<n;i++){
        cin >> input;
        u_map[input]=i;
    }
    while(m--){
        cin >> input;
        findIter = u_map.find(input);
        if(findIter != u_map.end())
            sum++;
    }
    cout<< sum;

    return 0;
}