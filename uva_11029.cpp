# include <cmath>
# include <iomanip>
# include <iostream>
using namespace std;

int mod(int n, int k){
    int N=1000, ans, temp;
    if(k%2)
        ans=n;
    else
        ans=1;
    while(k/2){
        k/=2;
        temp=(n*n)%N;
        if (k%2)
            ans=(ans*temp)%N;
        n=temp;
    }
    return ans;
}
int first3digit(int n, int k){
    double f=k*log10(n*1.0)-int(k*log10(n*1.0));
    return (int)pow(10, 2+f);;
}
int main(void){
    int N, n, k;
    cin >> N;
    while(N--){
        cin >> n >> k;
        cout<<first3digit(n, k)<<"..."
        <<setw(3)<<setfill('0')<< mod(n%1000, k)<<endl;
    }
    return 0;
}