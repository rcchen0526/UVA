# include <vector>
# include <iostream>
#define MAX 1000000
using namespace std;
vector<bool> prime(MAX, true);

bool is_digit_prime(int n){
    int sum = 0;
    while (n){
        sum+=n%10;
        n/=10;
    }
    if (prime[sum])
        return true;
    else
        return false;
}
int main(void){
    vector<int> digit_primes(MAX);
    for (int i=2; i<MAX; ++i){
        if (prime[i])
            for (int j=2*i; j<MAX; j+=i)
                prime[j]=false;
        if (prime[i] && is_digit_prime(i))
            digit_primes[i]=digit_primes[i-1]+1;
        else
            digit_primes[i]=digit_primes[i-1];
    }
    int num, t1, t2;
    cin >> num;
    for (int i=0; i<num; ++i){
        cin>>t1>>t2;
        cout << digit_primes[t2]-digit_primes[t1-1] << endl;
    }
    return 0;
}