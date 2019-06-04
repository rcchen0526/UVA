# include <iostream>
# include <cmath>
# include <iomanip>
using namespace std;
int main(void){
    cout.precision(4);
    int num;
    cin >> num;
    while(num--){
        double r, m1, n1, m2, n2, m3, n3;
        cin >> r;
        cin >> m1 >> n1;
        cin >> m2 >> n2;
        cin >> m3 >> n3;
        double a = 1.0;
        double b = n1*(m2+n2)/(m2*(m1+n1));
        double c = m1*(m3+n3)/(n3*(m1+n1));
        double k = r*sqrt((a+b+c)/(a+b-c)/(a+c-b)/(b+c-a));
        cout << fixed << (a+b+c)*r*k << endl;
    }
    return 0;
}