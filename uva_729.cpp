# include <iostream>
# include <algorithm>
using namespace std;
int main(void){
    int num, n, h;
    cin >> num;
    while(num--){
        char str[20];
        cin >> n >> h;
        for (int i=0; i<n-h; ++i)
            str[i]='0';
        for (int i=n-h; i<n; ++i)
            str[i]='1';
        str[n]='\0';
        do{
            cout << str << endl;
        }while(next_permutation(str, str + n));
        if (num)
            cout << endl;
    }
    return 0;
}