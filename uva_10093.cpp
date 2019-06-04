# include <iostream>
# include <string>
using namespace std;
int str2int(string s, int &sum){
    int start=1;
    sum=0;
    for (int i=0; i<s.length(); ++i){
        if (s[i]>='0' && s[i]<='9'){
            if (s[i]-'0'>start)
                start=s[i]-'0';
            sum+=s[i]-'0';
        }
        else if (s[i]>='A' && s[i]<='Z'){
            if (s[i]-'A'+10>start)
                start=s[i]-'A'+10;
            sum+=s[i]-'A'+10;
        }
        else if (s[i]>='a' && s[i]<='z'){
            if (s[i]-'a'+36>start)
                start=s[i]-'a'+36;
            sum+=s[i]-'a'+36;
        }
    }
    return start;
}
int main(void){
    string input;
    int sum=0;
    while(getline(cin, input)){
        int start=str2int(input, sum);
        for (int i=start; i<62; ++i){
            if (!(sum%i)){
                cout << i+1 << endl;
                break;
            }
            else if (i==61)
                cout << "such number is impossible!\n";
        }
    }
    return 0;
}