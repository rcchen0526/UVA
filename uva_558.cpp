# include <vector>
# include <iostream>

using namespace std;
int main(void){
    int num;
    vector<int*> v;
    cin >> num;
    while(num--){
        int n, m;
        while(cin >> n >> m){
            v.clear();
            vector<int> dis(1, 0);
            for (int i=0; i<m; ++i){
                int *data=new int[3];
                cin >> data[0]>>data[1]>>data[2];
                v.push_back(data);
            }
            for (int i=1; i<n; ++i)
                dis.push_back(1000000000);

            for (int i=0; i<n; ++i)
                for (int j=0; j<m; ++j)
                    dis[v[j][1]]=min( dis[v[j][1]], dis[v[j][0]]+v[j][2] );

            bool check=true;
            for (int i=0; i<m ; ++i)
                if( dis[v[i][1]] > dis[v[i][0]]+v[i][2]) {
                    check=false;
                    cout << "possible\n";
                    break;
                }
            if (check)
                cout << "not possible\n";
        }
    }
    return 0;
}