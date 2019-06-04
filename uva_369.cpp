# include <iostream>
using namespace std;
int main(void){
    int m=0, n=0;
    while (cin >> m >> n){
        if(!m && !n){
            break;
        }
        long long int ans=1;
        int _n=n;
        if (n>m/2)
            _n=m-n;
        for (int i=0; i<_n; ++i){
            ans*=(m-i);
            ans/=(1+i);
        }
        cout << m << " things taken " << n << " at a time is " << ans << " exactly.\n";
    }
    return 0;
}