# include <vector>
# include <iostream>
# include <cmath>
#define MAX 1000000
using namespace std;
vector<bool> prime(MAX, true);
vector<int> is_prime;

int main(void){
    vector<int> digit_primes(MAX);
    for (int i=2; i<MAX; ++i){
        if (prime[i]){
            for (int j=2*i; j<MAX; j+=i)
                prime[j]=false;
            is_prime.push_back(i);
        }
    }
    long long int num, low, high;
    cin >> num;
    for (int n=0; n<num; ++n){
        cin>>low>>high;
        int ans=0;
        for (int i=0; is_prime[i]<=sqrt(high) && i<is_prime.size(); ++i){
            for (long long int j=pow(is_prime[i],2); j<=high; j*=is_prime[i])
                if (j>=low)
                    ++ans;
        }
        cout << ans << endl;
    }
    return 0;
}
/*
質數，在數學中是一種特別的數，若一個數的因數除了自己和1以外沒有其他因數則稱為質數，也因這個條件，要判斷一個數是否為質數特別的花時間，今天，老師出了一道題目給小明，老師說如果一個不是質數的數但其因數由相同的質數組成那我稱為Almost Prime，例如:8=2*2*2，8不是質數但因數都是相同的數字2，想問小明在區間[L, W]，有幾個Almost Prime，小明一聽完想說終於不用判斷是質數了，開心地接下這道題目了，但他開始寫之後發現，判斷他不是質數同時，還是要判斷他是否為一個質數..請你幫小明寫一個程式完成這個題目
#INPUT
N一開始輸入一個數字代表有幾筆測字
L W每一行兩筆數字代表區間 範圍介於1到10^12
#OUTPUT
印出區間內有多少個almost prime
*/