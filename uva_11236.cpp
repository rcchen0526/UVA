# include <iostream>
# include <iomanip>
using namespace std;
int main(void){
    cout.precision(2);
    for (int i=8; i*i*i*i<=2000000000; ++i)
        for (int j=i; j*j*j<=2000000000/i; ++j) 
            for (int k=j; k*k<=2000000000/(i*j); ++k){
                if (i*j*k>1000000) {
                    long long int m=1000000*(i+j+k)/(i*j*k-1000000);
                    if (k<=m && i+j+k+m <= 2000 && 1000000*(i+j+k+m)==i*j*k*m)
                        cout << fixed << 0.01*i << ' ' << 0.01*j 
                        << ' ' << 0.01*k << ' ' << 0.01*m << endl;
                }
            }
    return 0;
}