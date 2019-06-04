# include <iostream>
using namespace std;

int main(void){
    int n, t;
    int CD[30];
    int dp[1024][30];
    while(cin >> n >> t){
        for (int i=1; i<=t; ++i)
            cin >> CD[i];

        for (int i=0; i<1024; ++i)
            for(int j=0; j<30; ++j)
                dp[i][j]=0;
        for( int i = 1 ; i <= n ; i++ )
            for( int j = 1 ; j <= t ; j++ )
                dp[i][j] = (CD[j] <= i)?max(dp[i][j-1], dp[i-CD[j]][j-1]+CD[j]):dp[i][j-1];
        int _n=n, _t=t;
        while(_n && _t){
            if(dp[_n][_t] == dp[_n][_t-1])
                --_t;
            else{
                cout << CD[_t] << " ";
                _n-=CD[_t];
                --_t;
            }
        }
        cout << "sum:" << dp[n][t] << endl;
    }
    return 0;
}