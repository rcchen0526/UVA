# include <iostream>
# include <vector>
# include <cmath>
using namespace std;
vector<int> prime_list(int Max){
    vector<int> prime;
    for(int i=1; i<=Max; ++i){
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
    int Max, Mid;
    while(cin >> Max >> Mid){
        vector<int> ans=prime_list(Max);
        cout << Max << " " << Mid << ": ";
        if (2*Mid>=ans.size()){
            for(int i=0; i<ans.size(); ++i){
                cout << ans[i];
                if (i!=ans.size()-1)
                    cout << ' ';
            }
            cout << endl;
        }
        else{
            int ans_mid=ans.size()/2;
            int start = ans_mid-Mid+(ans.size()%2);
            int end = ans_mid+Mid-1;
            for(int i=start; i<=end; ++i){
                cout << ans[i];
                if (i!=end)
                    cout << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
