# include <iostream>
using namespace std;

int main(void){
    int num;
    cin >> num;
    while(num--){
        int n, k, ans=0;
        bool sign=true;
        cin >> n >> k;
        while(n){
            ans+=sign?n:-n;
            n/=k;
            sign=sign?false:true;
        }
        cout << ans << endl;
    }
    return 0;
}