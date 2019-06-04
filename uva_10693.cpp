# include <cmath>
# include <iomanip>
# include <iostream>
using namespace std;
int main(void){
    cout.precision(8);
    double l, f;
    while(cin>>l>>f){
        if (!l && !f)
            break;
        double v=sqrt(2*l*f);// v^2/2f=d
        double t=v/f;//least time
        cout << fixed << v << ' ' << 3600/t << endl;//an hour 3600s
    }
    return 0;
}