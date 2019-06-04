# include <iostream>
using namespace std;
int main(void){
    int S[1001];
    int n, Case=0;
    for (int i=1; i<1001; ++i)
        S[i]=1;
    for (int i=2; i<1001; ++i){
        for (int j=i; j<1001; j+=i)
            S[j]+=i;
    }
    while (cin >> n){
        if (!n)
            break;
        int p=-1;
        for (int i=1000; i; --i)
            if (S[i]==n){
                p=i;
                break;
            }
        cout << "Case " << ++Case << ": " << p << endl;
    }
    return 0;
}