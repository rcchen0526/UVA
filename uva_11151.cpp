# include <iostream>
# include <vector>
# include <string>
using namespace std;
int main(void){
    int num=0;
    string temp;
    cin >> num;
    getline(cin, temp);
    while(num--){
        vector<char> L1, L2;
        int length=0;
        string input_s="";
        getline(cin, input_s);
        length = input_s.length();
        if (length==0){
            cout << "0" << endl;
            continue;
        }
        for (int i=0; i<length; ++i)
            L1.push_back(input_s[i]);
        for (int i=length-1; i>=0; --i)
            L2.push_back(L1[i]);
        int LCS[1001][1001]={0};
        for (int i=1; i<=length; ++i){
            for (int j=1; j<=length; ++j)
                if (L1[j-1]==L2[i-1])
                    LCS[i][j]=LCS[i-1][j-1]+1;
                else 
                    LCS[i][j]=max(LCS[i-1][j], LCS[i][j-1]);
        }
        cout << LCS[length][length] << endl;
    }
    return 0;
}