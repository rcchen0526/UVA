# include <iostream>
# include <vector>
# include <cmath>
#define MAXINPUT 1120
#define MAXKIND 14

using namespace std;
vector<int> prime_list(){
    vector<int> prime;
    for(int i=2; i<=MAXINPUT; ++i){
        bool check_prime=true;
        for(int j=2; j<=int(sqrt(i) ) && check_prime; ++j)
            if ( !(i%j) )
                check_prime=false;
        if (check_prime)
            prime.push_back(i);
    }
    return prime;
}
int main(void){

    vector<int> prime=prime_list();
    int ans[MAXINPUT+1][MAXKIND+1] = {0};

    ans[0][0] = 1;
    for (int p = 0; p < prime.size(); ++p) {
        for (int n = MAXINPUT; n >= prime[p]; --n) {
            for (int k = 1; k <= MAXKIND; ++k) {
                ans[n][k] += ans[n-prime[p]][k-1];
            }
        }
    }
 
    int n, k;
    while(cin >> n >> k){
        if(!n&&!k)
            break;
        else
            cout << ans[n][k] << endl;
    }

    return 0;
}