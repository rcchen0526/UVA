# include <iostream>
# include <iomanip>
# include <vector>
# include <cmath>
# include <algorithm>
using namespace std;
double area(double a, double b, double c){
    double s = (a+b+c)/2;
    return s*(s-a)*(s-b)*(s-c);
}
int main(void){
    cout.precision(2);
    int num;
    cin >> num;
    while(num--){
        int N;
        cin >> N;
        vector<double> v;
        v.resize(N);
        for (int i=0; i<N;++i)
            cin >> v[i];
        sort(v.begin(), v.end());
        double ans=0;
        for (int i=0; i+2<v.size(); ++i){
            if (v[i]+v[i+1]<=v[i+2])
                continue;
            double temp=area(v[i], v[i+1], v[i+2]);
            ans=temp>ans?temp:ans;
        }
        cout << fixed << sqrt(ans) << endl;
    }
    return 0;
}