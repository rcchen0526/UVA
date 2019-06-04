# include <cmath>
# include <vector>
# include <climits>
# include <iostream>
using namespace std;
int main(void){
    int n, Case=0;
    int prime_length=46340+5;//sqrt(INT_MAX)+5
    bool prime[46345]={false, false, true};
    vector<int> prime_list;
    for(int i=2; i<prime_length; ++i)
        prime[i]=true;
    for (int i=2; i<prime_length; ++i)
        if (prime[i]){
            prime_list.push_back(i);
            for (int j=2*i; j<prime_length; j+=i)
                prime[j]=false;
        }
    while(cin >> n){
        int ans=0, temp_n=n;
        if (!n)
            break;
        if (n==INT_MAX)
            cout << "Case "<< ++Case<<": " << "2147483648\n";
        else if(n==1)
            cout << "Case "<< ++Case<<": " << "2\n";
        else{
            for (int i=0; i<prime_list.size() && prime_list[i]<=n; ++i){
                int temp=1;
                while(!(n%prime_list[i])){
                    n/=prime_list[i];
                    temp*=prime_list[i];
                }
                if (temp!=1)
                    ans+=temp;
            }
            if (ans==temp_n || !ans)
                ++ans;
            if (n!=1)
                ans+=n;
            cout << "Case "<< ++Case<<": " << ans << endl;
        }
    }
    return 0;
}