# include <cmath>
# include <iomanip>
# include <iostream>
using namespace std;
int main(void){
    int N, n;
    double a;
    cout.precision(3);
    cin >> N;
    for (int Case=1; Case<=N; ++Case){
        double ans=0, c=0;
        cin >> n;
        for (int i=0; i<n; ++i){
            cin >> a;
            if (a<0)
                ans-=exp(c+log(-a)-(n-1)*log(2));
            else
                ans+=exp(c+log(a)-(n-1)*log(2));
            c+=log(n-1-i)-log(i+1);
        }
        cout<<fixed<<"Case #"<<Case<<": "<<ans<<endl;
    }
    return 0;
}