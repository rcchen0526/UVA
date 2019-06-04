# include <string>
# include <iostream>
using namespace std;
int main(void){
    bool prime[100001];
    for (int i=2; i<100001; ++i){
        if (!prime[i]){
            for (int j=2*i; j<100001; j+=i)
                prime[j]=1;
        }
    }
    string input;
    while(cin >> input){
        if (input=="0")
            break;
        int ans=0;
        for (int i=0; i<input.length(); ++i){
            int temp=0;
            for (int j=i; j<input.length(); ++j){
                temp*=10;
                temp+=(input[j]-'0');
                if (temp>100000)
                    break;
                else if (!prime[temp])
                    ans=temp>ans?temp:ans;
            }
        }
        cout << ans << endl;
    }
    return 0;
}