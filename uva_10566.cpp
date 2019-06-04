# include <cmath>
# include <iomanip>
# include <iostream>
using namespace std;
int main(void){
    double x, y, c;
    double error=1e-10;
    cout.precision(3);
    while (cin >> x >> y >> c){
        double upper=min(x, y), lower=0;
        //c=sqrt(x*x-l*l)*sqrt(y*y-l*l) / sqrt(x*x-l*l) + sqrt(y*y-l*l)
        double l;
        while(upper>lower){
            l=(upper+lower)/2;
            double c_error=sqrt(x*x-l*l)*sqrt(y*y-l*l) / (sqrt(x*x-l*l) + sqrt(y*y-l*l));
            if(fabs(c_error-c)<error)
                break;
            if (c_error<c)
                upper=l;
            else
                lower=l;
        }
        cout << fixed << l << endl;
    }
    return 0;
}