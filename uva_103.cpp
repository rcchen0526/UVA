# include <vector>
# include <iostream>
# include <algorithm>
using namespace std;

bool cmp(const vector<int> x,const vector<int> y){
    for (int i=0; i<x.size()-1; ++i){
        if(x[i]!=y[i])
            return x[i]<y[i];
    }
    return x[x.size()]<y[x.size()];
}

bool comp(const vector<int> x,const vector<int> y){
    for (int i=0; i<x.size()-1; ++i){
        if(x[i]>=y[i])
            return false;
    }
    return true;
}

int main(void){
    int num, dim;
    vector<vector<int> > box;
    while(cin >> num >> dim){
        box.clear();
        for (int N=0; N<num; ++N){
            vector<int> data;
            data.resize(dim);
            for (int D=0; D<dim; ++D){
                cin >> data[D];
            }
            sort(data.begin(),data.end());
            data.push_back(N+1);
            box.push_back(data);
        }
        sort(box.begin(),box.end(),cmp);

        vector<int> DP(box.size(), 0);
        vector<int> PATH(box.size(), 0);
        vector<int> ans(1, 0);
        int last_index=0;
        for(int i=0;i<box.size();i++){
            DP[i]=1;
            for(int j=0;j<=i;j++)
                if(comp(box[j], box[i]) && DP[i]<DP[j]+1){
                    DP[i]=DP[j]+1;
                    PATH[i]=j;
                }
            if (DP[i]>ans[0]){
                ans[0]=DP[i];
                last_index=i;
            }
        }
        cout << ans[0] << endl;

        for (int k=0; k<ans[0]; ++k){
            ans.push_back(box[last_index][dim] );
            last_index=PATH[last_index];
        }
        for (int i=ans.size()-1; i; --i){
            cout << ans[i];
            if (i!=1)
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}