# include <vector>
# include <iostream>
using namespace std;
std::vector<char> ans;
std::vector<int> DAG[30];
int visit[100];
void dfs(int n){
    if (visit[n]==1)
        return;
    visit[n]=1;
    for (vector<int>::iterator it=DAG[n].begin();it!=DAG[n].end(); ++it){
        if (visit[*it] != 2)
            dfs(*it);
    }
    visit[n]=2;
    ans.push_back(n+'A');
}
int main(void){
    string l1="", l2="";
    while(cin >> l1){
        int check[30]={0};//1 means no input, 2 means has input
        for (int i=0; i<100; ++i)
            visit[i]=0;
        for (int i=0; i<30; ++i)
            DAG[i].clear();
        ans.clear();
        check[l1[0]-'A']=1;
        while(cin >> l2)
            if (l2=="#"){
                for (int c='A'-'A'; c<'Z'-'A'; ++c){
                    if (check[c]==1)
                        dfs(c);
                }
                for (int i=ans.size()-1; i>=0; --i)
                    cout << ans[i];
                cout << endl;
                break;
            }
            else{
                int l=l1.length()>l2.length()?l2.length():l1.length();
                for (int i=0; i<l; ++i){
                    if (!check[l1[i]-'A'])
                        check[l1[i]-'A']=1;
                    if (!check[l2[i]-'A'])
                        check[l2[i]-'A']=1;
                    if (l1[i]!=l2[i]){
                        DAG[l1[i]-'A'].push_back(l2[i]-'A');
                        check[l2[i]-'A']=2;
                        break;
                    }
                }
                l1=l2;
        }
    }
    return 0;
}