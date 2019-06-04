# include <iostream>
# include <climits>
#define M 15
#define N 105
using namespace std;
int main(void){
    int m, n;
    while(cin >> m >> n){
        long int graph[M+1][N+1]={0};
        int path[M+1][N+1]={0};
        
        for (int i=0; i<m; ++i){
            for (int j=0; j<n; ++j){
                cin >> graph[i][j];
            }
        }
        long int dp[M+1][N+1]={0};
        for (int col=n-1; col>=0; --col){
            for (int row=0; row<m; ++row){
                int up=(row-1+m)%m;
                int mid=row;
                int down=(row+1)%m;
                int min;
                if(dp[up][col+1]<dp[mid][col+1])
                    min=up;
                else if (dp[up][col+1]==dp[mid][col+1])
                    min=up<mid?up:mid;
                else 
                    min=mid;
                if(dp[min][col+1]>dp[down][col+1])
                    min=down;
                else if(dp[min][col+1]==dp[down][col+1])
                    min=down<min?down:min;
                path[row][col]=min;
                dp[row][col]=dp[min][col+1]+graph[row][col];
            }
        }
        int ans=0;
        for (int i=0; i<m; ++i){
            if(dp[i][0]<dp[ans][0])
                ans=i;
        }
        int output = dp[ans][0];
        for (int i = 0; i < n ; ++i){
            cout << ans+1;
            if (i!=n-1)
                cout << ' ';
            ans = path[ans][i];
        }
        cout << endl;
        cout << output << endl;
    }
    return 0;
}