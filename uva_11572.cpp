# include <iostream>
# include <vector>
using namespace std;
int lis(vector<int> s){
    if (!s.size())
        return 0;
    int pos[1000001];
    for (int i=0; i<1000001; ++i)
        pos[i]=-1;
    int start=0, MAX=0;
    s.push_back(s.back());
    for(int i=0; i<s.size(); ++i){
        if(pos[s[i]]>=start){
            int tmp=i-start;
            MAX = max(tmp, MAX);
            start = pos[s[i]]+1;
            pos[s[i]]=i;
        }else
            pos[s[i]]=i;
    }
    return MAX;
}
int main(void){
    int Case;
    cin >> Case;
    while(Case--){
        int n;
        cin >> n;
        vector<int> data;
        data.resize(n);
        for (int i=0; i<n; ++i)
            cin >> data[i];
        cout << lis(data) << endl;
    }
    return 0;
}