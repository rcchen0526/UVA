# include <iostream>
# include <iomanip>
using namespace std;
 
int main()
{
    cout.precision(5);
    int p, q, r, s;
    while(cin>>p>>q>>r>>s){
        if(q>p/2)
           q=p-q;
        if(s>r/2)
           s=r-s;
        double ans = 1.0;
        for(int i=0;i<q || i<s; ++i){
            if(i<q)
                ans=ans*(p-i)/(1+i);
            if(i<s)
                ans=ans/(r-i)*(1+i);
        }
        cout << fixed << ans << endl;
    }
    return 0;
}