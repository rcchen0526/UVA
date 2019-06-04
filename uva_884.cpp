# include <iostream>
using namespace std;
int main(void){
    int MAX=1000001;
    int f[1000001];
    f[1]=0;
    for (int i=2; i<MAX; ++i)
        f[i]=1;
    for (int i=2; i<MAX; ++i)
        if (f[i]==1)
            for (int j=2; i*j<MAX; ++j)
                f[i*j]=f[i]+f[j];
    for (int i=2; i<MAX; ++i)
        f[i]+=f[i-1];
    int n;
    while(cin >> n)
        cout << f[n] << endl;
    return 0;
}