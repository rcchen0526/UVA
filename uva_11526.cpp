# include <iostream>
# include <cmath>
using namespace std;
long long H(int n){
    long long ans=0, tmp=sqrt(n);
    for(int i=1; i<=tmp;i++)
        ans+=(n/i);
    return 2*ans-tmp*tmp;
}
int main(void){
    int n, num;
    cin >> num;
    while(num--){
        cin >> n;
        cout << H(n) << endl;
    }
    return 0;
}