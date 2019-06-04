# include <vector>
# include <string>
# include <iostream>
using namespace std;
int main(void){
    vector<vector<int> > v;
    v.resize(10);
    v[0].push_back(0);
    v[1].push_back(1);
    v[4].push_back(6);
    v[5].push_back(5);
    v[6].push_back(6);
    v[9].push_back(9);
    v[2].push_back(4), v[2].push_back(6);
    v[3].push_back(7), v[3].push_back(3);
    v[7].push_back(3), v[7].push_back(7);
    v[8].push_back(6), v[8].push_back(4);
    string N;
    int n;
    while(getline(cin, N)){
        if (!(N[0]-'0'))
            break;
        if (N.length()==1)
            n=(N[0]-'0');
        else
            n=(N[N.length()-2]-'0')*10+N[N.length()-1]-'0';
        int sum=0;
        for (int i=1; i<=n; ++i)
            sum+=v[i%10][(i/10)%v[i%10].size()];
        cout << sum%10 << endl;
    }
    return 0;
}