# include <iomanip>
# include <iostream>
using namespace std;
int E[1000001];
double value[1000001];
int main(void){
    cout.precision(3);
    E[0]=0;
    value[0]=1.0;
    for (int i=1; i<1000001; ++i){
        value[i]=value[i-1]/2.0;
        E[i]=E[i-1];
        if (value[i]<1){
            value[i]*=10;
            --E[i];
        }
    }
    int num;
    while(cin >> num)
        cout<<"2^-"<<num<<" = "<<fixed<<value[num]<<"e"<<E[num]<<endl;
    return 0;
}