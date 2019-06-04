# include <queue>
# include <vector>
# include <iostream>
# include <algorithm>
using namespace std;
vector<int*> MAP;
vector<int*> alpha;
queue<int*> q;
bool cmp(int *a, int *b){
    if (a[0]!=b[0])
        return a[0]>b[0];
    else
        return a[1]<b[1];
}
void bfs(){
    int i=q.front()[0], j=q.front()[1];
    int ALPHA=MAP[i][j];
    ++alpha[ALPHA][0];
    MAP[i][j]=-1;
    while(!q.empty()){
        i=q.front()[0], j=q.front()[1];
        q.pop();
        if(MAP[i-1][j]==ALPHA){
            MAP[i-1][j]=-1;
            int *data=new int[2];
            data[0]=i-1, data[1]=j;
            q.push(data);
        }
        if(MAP[i+1][j]==ALPHA){
            MAP[i+1][j]=-1;
            int *data=new int[2];
            data[0]=i+1, data[1]=j;
            q.push(data);
        }
        if(MAP[i][j-1]==ALPHA){
            MAP[i][j-1]=-1;
            int *data=new int[2];
            data[0]=i, data[1]=j-1;
            q.push(data);
        }
        if(MAP[i][j+1]==ALPHA){
            MAP[i][j+1]=-1;
            int *data=new int[2];
            data[0]=i, data[1]=j+1;
            q.push(data);
        }
    }
}
int main(void){
    int num;
    cin >> num;
    for (int N=1; N<=num;++N){
        int r, w;
        cin >> r >> w;
        alpha.clear();
        MAP.clear();
        for (int a=0; a<26; ++a){
            int *data=new int[2];
            data[0]=0;
            data[1]=a;
            alpha.push_back(data);
        }
        for (int i=0; i<r+2; ++i){
            int *data=new int[w+2];
            for (int j=0; j<w+2; ++j)
                data[j]=-1;
            MAP.push_back(data);
        }
        for (int i=1; i<=r; ++i){
            char c;
            for (int j=1; j<=w; ++j){
                cin >> c;
                MAP[i][j]=c-'a';
            }
        }
        for (int i=1; i<=r; ++i)
            for (int j=1; j<=w; ++j)
                if(MAP[i][j]>=0){
                    int data[2]={i, j};
                    q.push(data);
                    bfs();
                }
        sort(alpha.begin(),alpha.end(),cmp);
        /*for (int i=0; i<MAP.size(); ++i){
            for (int j=0; j<w+2; ++j)
                cout << MAP[i][j]<<' ';
            cout << endl;
        }cout << endl;*/
        cout << "World #" << N << endl;
        for (int i=0; i<alpha.size(); ++i){
            if (alpha[i][0])
                cout << char('a'+alpha[i][1]) << ": " << alpha[i][0] << endl;
        }
    }
    return 0;
}