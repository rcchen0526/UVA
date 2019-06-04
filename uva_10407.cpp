# include <iostream>
# include <vector>
using namespace std;

int gcd(int a,int b){
    while(b){
        int temp=a%b;
        a=b;
        b=temp;
    }
    return a;
}
int main(void){
    int data;
    vector<int> d;
    int first;
    while(true){
        d.clear();
        while(cin >> data){
            if (data){
                if (d.empty())
                    first=data;
                d.push_back(abs(data-first));
            }
            else 
                break;
        }
        int ans=0;
        if (d.empty())
            break;
        else
            for(int i = 0;i <d.size();i++)
                ans = gcd(d[i],ans);
        cout << ans << endl;
    }
    return 0;
}