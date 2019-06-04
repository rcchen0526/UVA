# include <queue>
# include <iostream>
using namespace std;
int MAP[102][102];
queue<int*> q;

int char2int(char c){
    if (c=='@')
        return 1;
    else
        return 0;
}
void bfs(int i, int j){
    MAP[i][j]=0;
    while (!q.empty()){
        i=q.front()[0], j=q.front()[1];
        q.pop();
        if(MAP[i-1][j-1]){
           MAP[i-1][j-1]=0;
           int *data=new int[2];
           data[0]=i-1, data[1]=j-1;
           q.push(data);
        }
        if(MAP[i-1][j]){
            MAP[i-1][j]=0;
            int *data=new int[2];
            data[0]=i-1, data[1]=j;
            q.push(data);
        }
        if(MAP[i-1][j+1]){
            MAP[i-1][j+1]=0;
            int *data=new int[2];
            data[0]=i-1, data[1]=j+1;
            q.push(data);
        }
        if(MAP[i][j-1]){
            MAP[i][j-1]=0;
            int *data=new int[2];
            data[0]=i, data[1]=j-1;
            q.push(data);
        }
        if(MAP[i][j+1]){
            MAP[i][j+1]=0;
            int *data=new int[2];
            data[0]=i, data[1]=j+1;
            q.push(data);
        }
        if(MAP[i+1][j-1]){
            MAP[i+1][j-1]=0;
            int *data=new int[2];
            data[0]=i+1, data[1]=j-1;
            q.push(data);
        }
        if(MAP[i+1][j]){
            MAP[i+1][j]=0;
            int *data=new int[2];
            data[0]=i+1, data[1]=j;
            q.push(data);
        }
        if(MAP[i+1][j+1]){
            MAP[i+1][j+1]=0;
            int *data=new int[2];
            data[0]=i+1, data[1]=j+1;
            q.push(data);
        }
    }
}

int main(void){
    int r, c, n;
    char C;
    while(cin >>r>>c){
        if (!r && !c)
            break;
        n=0;
        for (int i=0; i<102; ++i)
            for (int j=0; j<102; ++j)
                MAP[i][j]=0;

        for (int i=1; i<=r; ++i){
            for (int j=1; j<=c; ++j){
                cin >> C;
                MAP[i][j]=char2int(C);
            }
        }

        for (int i=1; i<=r; ++i)
            for (int j=1; j<=c; ++j)
                if(MAP[i][j]){
                    ++n;
                    int data[2]={i, j};
                    q.push(data);
                    bfs(i, j);
                }
        cout << n << endl;

    }
    return 0;
}