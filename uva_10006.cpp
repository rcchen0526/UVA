# include <iostream>
using namespace std;
long long int mod(long long int a, long long int n){
    long long int N=n, ans, temp;
    if(n%2)
        ans=a;
    else
        ans=1;
    while(n/2){
        //cout << n/2 << endl;
        n/=2;
        temp=(a*a)%N;
        if (n%2)
            ans=(ans*temp)%N;
        a=temp;

    }
    return ans;
}
bool check(long long int a, long long int n){
    if(mod(a, n)==a)
        return true;
    else
        return false;
}
int main(void){
    long long int n;
    bool prime[65001] = {true, true, false};
    for (int i = 2; i <= 65000; ++i)
        if (!prime[i])
            for (int j = i+i; j <= 65000; j+=i)
                prime[j] = true;
    while(cin >> n){
        if (!n)
            break;
        bool isCarmichael = true;
        if (!prime[n])
            isCarmichael = false;

        for(long long int i=2; i < n && isCarmichael; ++i)
            isCarmichael = isCarmichael && check(i, n);  

        if(isCarmichael)
            cout << "The number " << n << " is a Carmichael number.\n";
        else
            cout << n << " is normal.\n";
    }
    return 0;
}