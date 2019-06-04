# include <iostream>
#define MAX_M 200
#define MAX_C 20
#define MAX_K 20
using namespace std;
int main(void){
    int test_num=0;
    cin >> test_num;
    while(test_num--){
        int M=0, C=0;
        int kind[MAX_C+1][MAX_K+1]={0};
        int price[MAX_M+2][MAX_C+1]={0};
        int Max=0;
        cin >> M >> C;
        for (int __c=0; __c<C; ++__c){
            cin >> kind[__c][0];
            for (int i=1; i<=kind[__c][0]; ++i)
                cin >> kind[__c][i];
        }
        //DP
        price[0][0]=1;
        for (int __c = 0; __c < C; ++__c){
            for (int k=1; k<=kind[__c][0]; ++k){
                for (int p=0; p+kind[__c][k]<=M;++p){
                    if(price[p][__c]){
                        price[p+kind[__c][k] ][__c+1]=1;
                    }
                }
            }
        }
        for (int i=M; i>=0 && !price[i+1][C]; --i)
            if (price[i][C])
                Max=i;
        if (Max)
            cout << Max << endl;
        else
            cout << "no solution\n";
    }
    return 0;
}