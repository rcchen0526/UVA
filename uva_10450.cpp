# include <iostream>
using namespace std;
int main(void){
    long long int f[55]={1, 1};
    int n, Case;
    for (int i=2; i<55; ++i)
        f[i]=f[i-1]+f[i-2];
    cin >> Case;
    for (int i=1; i<=Case; ++i){
        cin >> n;
        cout << "Scenario #"<< i <<":\n";
        cout << f[n+1] << endl << endl;
    }
    return 0;
}