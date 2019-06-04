# include <string>
# include <iostream>
using namespace std;

bool check(string s, int k){
    for (int i=0; i<k; ++i)
        for (int j=k; i+j<s.length(); j+=k)
            if (s[i]!=s[i+j])
                return false;
    return true;
}
int main(void){
    int num;
    cin >> num;
    while(num--){
        string data="";
        cin >> data;
        for (int i=1; i<=data.length(); ++i){
            if ((data.length()%i)==0)
                if (check(data, i)){
                    cout << i << endl;
                    if (num)
                        cout << endl;
                    break;
                }
        }
    }
    return 0;
}