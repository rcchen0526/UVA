# include <cmath>
# include <iostream>
using namespace std;

long long int cal(double n, double k){//calculate root
    double root1=(-3*k+sqrt(12*n/k-3*pow(k, 2)) )/6;
    double root2=(-3*k-sqrt(12*n/k-3*pow(k, 2)) )/6;
    if(root1<0)
        return (long long int)root2;
    else
        return (long long int)root1;

}

int main(void){
    long long int n, k;
    while(cin >> n){
        if (!n)
            break;
        k = (long long int)ceil(pow(n, (double)1/3)) + 1;
        bool solution = false;
        for (long long int i=1; i<=k; ++i){
            long long int y = cal((double)n, (double)i);
            long long int x = y+i;
            if(x>=0 && y>=0 && x*x*x-y*y*y==n){
                cout << x << " " << y << endl;
                solution = true;
                break;
            }
        }
        if (!solution)
            cout << "No solution\n";
    }
    return 0;
}
