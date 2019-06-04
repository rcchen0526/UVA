# include <iostream>
# include <vector>
using namespace std;
int main(void){
    int N1=0, N2=0;
    int num=0;
    while(cin>>N1>>N2){
        vector<int> L1, L2;
        if (!N1||!N2)
            break;
        L1.resize(N1);
        L2.resize(N2);
        for (int i=0; i<N1; ++i)
            cin >> L1[i];
        for (int i=0; i<N2; ++i)
            cin >> L2[i];
        if (N1>N2){
            swap(L1, L2), swap(N1, N2);
        }
        int LCS[101][101]={0};
        for (int i=1; i<=N2; ++i){
            for (int j=1; j<=N1; ++j)
                if (L1[j-1]==L2[i-1])
                    LCS[i][j]=LCS[i-1][j-1]+1;
                else 
                    LCS[i][j]=max(LCS[i-1][j], LCS[i][j-1]);
        }
        cout << "Twin Towers #" << ++num << endl;
        cout << "Number of Tiles : " << LCS[N2][N1] << endl;
        cout << "\n";
    }
    return 0;
}