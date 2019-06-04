# include <iostream>
# include <vector>
# include <string>
using namespace std;
int str2int(string s){
    int ans=0;
    for (int i=0; i<s.length(); ++i){
        ans*=10;
        ans+=(s[i]-'0');
    }
    return ans;
}
int main(void){
    int num;
    cin >> num;
    string temp;
    getline(cin, temp);
    getline(cin, temp);
    vector<int> data;
    while(num--){
        data.clear();
        while(getline(cin, temp)){
            if (temp.length()==0)
                break;
            data.push_back(str2int(temp) );
        }
        vector<int> PATH(data.size(), 0);
        vector<int> DP(data.size(), 0);
        vector<int> ans(1, 0);
        int last_index=0;
        for(int i=0;i<data.size();i++){
            DP[i]=1;
            for(int j=0;j<=i;j++)
                if(data[j]< data[i] && DP[i]<DP[j]+1){
                    DP[i]=DP[j]+1;
                    PATH[i]=j;
                }
            if (DP[i]>ans[0]){
                ans[0]=DP[i];
                last_index=i;
            }
        }
        cout << "Max hits: " << ans[0] << endl;

        for (int k=0; k<ans[0]; ++k){
            ans.push_back(data[last_index] );
            last_index=PATH[last_index];
        }
        for (int i=ans.size()-1; i; --i){
            cout << ans[i] << endl;
        }
        if (num)
            cout << endl;
    }
    return 0;
}