# include <iostream>
# define MAX 9876543210
using namespace std;
bool check(long long int n){
    int digit[10]={0};
    while(n){
        if (!digit[n%10])
            digit[n%10]=true;
        else
            return false;
        n/=10;
    }
    return true;
}
int main(void){
    int num;
    cin >> num;
    while(num--){
        long long int S1=0, S2, N;
        cin >> N;
        for (S2=1; S2<MAX; ++S2){
            S1=S2*N;
            if (check(S1) && check(S2))
                cout << S1<<" / "<<S2<<" = "<<N<<endl;
            if (S1>MAX)
                break;
        }
        if (num)
            cout << endl;
    }
    return 0;
}