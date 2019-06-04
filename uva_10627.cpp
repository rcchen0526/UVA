# include <cmath>
# include <iostream>
using namespace std;

int gcd(int a,int b){
    if (a<b)
        swap(a, b);
    while(b){
        int temp=a%b;
        a=b;
        b=temp;
    }
    return a;
}

int main(void){
    long long int L, u, v, t;
    while(cin>>L>>u>>v>>t){
        if (L+u+v+t){
            if (!u && !v){
                cout << 0 << endl;
                continue;
            }
            long long int ans=0;
            ans+=((u+v)*t+L)/(2*L);//confort, L means first distance
            ans+=(abs(u-v)*t+L)/(2*L);//catch
            int edge=gcd(u, v);

            if((abs(u-v)/edge)&1) //if meet on the edge
                ans-=(edge*t+L)/(2*L);//it will repeat
            cout << ans << endl;
        }
        else
            break;
    }
    return 0;
}