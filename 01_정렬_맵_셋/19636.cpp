#include <iostream>

using namespace std;
int main()
{
    int W0, I0, T, D, I, A;
    cin >> W0 >> I0 >> T >> D >> I >> A;

    int W1=W0;
    int D1=D;
    bool danger1 = true;
    while (D1--) {
        W1 += (I - A - I0);
        if (W1 <= 0) {
            cout << "Danger Diet" << "\n";
            danger1 = false; break;
        }     
    }
    if(danger1)
        cout << W1 << " " << I0 << "\n";

    int I2 = I0;
    int D2 = D;
    bool danger2 = true;
    while (D2--) {
        W0 += (I - A - I2);
        if (abs(I - A - I2) > T) {
            if(((I - A - I2) < 0) and (-(I - A - I2)%2==1))
                I2 += ((I - A - I2) / 2 - 1);
            else
                I2 += (I - A - I2) / 2;
        }
        if ((W0 <= 0) or (I2 <= 0)) {
            cout << "Danger Diet";
            danger2 = false; break;
        }
    }

    if(danger2){
        cout << W0 << " " << I2 ;
        if ((I0 - I2) > 0)
            cout << " YOYO";
        else
            cout << " NO";
    }
    return 0;
}
