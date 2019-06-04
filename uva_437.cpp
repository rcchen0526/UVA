# include <vector>
# include <iostream>
# include <algorithm>
using namespace std;
bool cmp(const int x[3],const int y[3]){
    if(x[0]!=y[0]) 
        return x[0]<y[0];
    return x[1]<y[1];
}
int main(void){
    vector<int*> box;
    int num=0;
    int Case=0;
    while(cin >> num){
        if (!num)
            break;
        box.clear();
        for (int n=0; n<num; ++n){
            int *data = new int[3];
            for (int i=0; i<3; ++i)
                cin >> data[i];
            for (int i=0; i<3; ++i){
                int *data_temp = new int[3];
                data_temp[0]=max(data[(i-1+3)%3], data[(i+1)%3] );
                data_temp[1]=min(data[(i-1+3)%3], data[(i+1)%3] );
                data_temp[2]=data[i];
                box.push_back(data_temp);
            }
        }
        sort(box.begin(),box.end(),cmp);
        vector<int> DP(3*num, 0);
        int ans=0;
        for(int i=0;i<box.size();i++){
            DP[i]=box[i][2];
            for(int j=0;j<=i;j++)
                if(box[j][0]<box[i][0] && box[j][1]<box[i][1] && DP[i]<DP[j]+box[i][2])
                    DP[i]=DP[j]+box[i][2];
            ans=max(ans,DP[i]);
        }
        cout << "Case " << ++Case << ": maximum height = " << ans << endl;

    }
    return 0;
}