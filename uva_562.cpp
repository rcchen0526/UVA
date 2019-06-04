# include <vector>
# include <iostream> 
using namespace std;
int main(void){
    int num;
    vector<int> money;
    vector<int> balance;
    cin >> num;
    while(num--){
        int m, total=0, half;
        cin >> m;
        money.resize(m);
        for (int i=0; i<m; ++i){
            cin >> money[i];
            total+=money[i];
        }
        half=total/2;
        balance.resize(half+1);
        for (int i=0; i<m && balance[half]!=half; ++i)
            for (int j=half; j>=money[i] && balance[half]!=half; --j)
                balance[j]=max(balance[j], balance[j-money[i]]+money[i]);
        cout << total - 2*balance[half] << endl;;
        money.clear();
        balance.clear();
    }
    return 0;
}