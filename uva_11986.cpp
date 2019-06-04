# include <iostream>
using namespace std;
int main(void){
    int num;
    cin >> num;
    for (int n=1; n<=num; ++n){
        int ans=0;
        long long int N=0;
        cin >> N;
        while(N){
            ++ans;
            N/=2;
        }
        cout << "Case " << n << ": " << ans << endl;
    }
    return 0;
}