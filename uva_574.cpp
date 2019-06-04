# include <iostream>
# include <vector>
using namespace std;
int t;
vector<int> data;
vector<int> stack;
vector< vector<int> > ans;
bool comp(vector<int> a, vector<int> b){
    if(a.size()!=b.size())
        return true;
    for (int i=0; i<a.size(); ++i)
        if (data[a[i]]!=data[b[i]])
            return true;
    return false;
}
void comb(int curi){
    int ans_temp=0;
    for (int i=0; i<stack.size(); ++i)
        ans_temp+=data[stack[i]];
    if(ans_temp==t){
        bool check=true;
        for (int i=ans.size()-1; i>=0; --i){
            check=comp(ans[i], stack);
            if (!check)
                return;
        }
        if (check)
            ans.push_back(stack);
        return;
    }
    else if (curi>=data.size() || ans_temp>t)
        return;
    stack.push_back(curi);
    comb(curi+1);
    stack.pop_back();
    comb(curi+1);
}
int main(void){
    int n, temp;
    while(cin >> t >> n){
        if(!t && !n)
            break;
        stack.clear();
        ans.clear();
        data.resize(n);
        for (int i=0; i<n; ++i)
            cin >> data[i];
        comb(0);
        cout << "Sums of " << t << ":\n";
        for (int i=0; i<ans.size(); ++i){
            for (int j=0; j<ans[i].size(); ++j){
                cout << data[ans[i][j]];
                if (j!=ans[i].size()-1)
                    cout << '+';
            }cout << endl;
        }
        if (ans.empty())
            cout << "NONE\n";
    }
    return 0;
}