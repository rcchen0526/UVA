# include <vector>
# include <string>
# include <iostream>
using namespace std;
int main(void){
    int length=0;
    int temp=0;
    cin >> length;
    std::vector<int> ans;
    std::vector<int> test;
    ans.resize(length);
    test.resize(length);
    for (int i=1; i<=length; ++i){
        cin >> temp;
        ans[temp-1]=i;
    }
    int student_ans=0;
    int num=0;
    int LCS[25][25]={0};
    while(cin >> temp){
        test[temp-1]=++num;
        if (num/length){
            for (int i=1; i<=length; ++i){
                for (int j=1; j<=length; ++j)
                    if (ans[j-1]==test[i-1])
                        LCS[i][j]=LCS[i-1][j-1]+1;
                    else 
                        LCS[i][j]=max(LCS[i-1][j], LCS[i][j-1]);
            }
            cout << LCS[length][length] << endl;
            for (int i=0; i<=length; ++i){
                LCS[i][0]=0;
                LCS[0][i]=0;
            }
            num=0;
        }
    }
}
