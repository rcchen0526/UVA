#include <iostream>
using namespace std;

bool Valid(string s){
    for( int i = 0 ; i < s.length()-1 ; ++i )
        if(s[i+1]<=s[i])
            return false;
    return true;
}

int C(int m, int n){
    int ans=1;
    if (n>m/2)
        n=m-n;
    for (int i=0; i<n; ++i){
        ans*=(m-i);
        ans/=(i+1);
    }
    return ans;
}

int main(){
    string word;
    while( cin >> word ){

        if( !Valid(word) ){
            cout << "0\n";
            continue;
        }

        int index = 1;
        for( int i = 1 ; i < word.length() ; ++i )
            index += C(26, i);

        int m=25;
        for (int n=0; n<word.length(); ++n, --m){
            for (char c=(n)?(word[n-1]+1):'a'; c<word[n]; ++c){
                index += C(m, word.length()-1-n);
                --m;
            }
        }

        cout << index << endl;

    }

    return 0;
}