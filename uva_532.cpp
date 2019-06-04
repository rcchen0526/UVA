# include <queue>
# include <iostream>
using namespace std;
int map[32][32][32];
int L, R, C;
queue<int*> q;
int bfs(int end_i, int end_j, int end_k){
    int i, j, k, n;
    while (!q.empty()){
        i=q.front()[0], j=q.front()[1], k=q.front()[2], n=q.front()[3];
        q.pop();
        if (i==end_i && j==end_j && k==end_k){
            while (!q.empty())
                q.pop();
            return n;
        }
        else {
            n+=1;
            if ( (i+1)<L )
                if( map[i+1][j][k]){
                    map[i+1][j][k]=0;
                    int *data=new int[4];
                    data[0]=i+1, data[1]=j, data[2]=k, data[3]=n;
                    q.push(data);
            }
            if ( (i-1)>=0 )
                if( map[i-1][j][k]){
                    map[i-1][j][k]=0;
                    int *data=new int[4];
                    data[0]=i-1, data[1]=j, data[2]=k, data[3]=n;
                    q.push(data);
            }
            if ( (j+1)<R )
                if( map[i][j+1][k]){
                    map[i][j+1][k]=0;
                    int *data=new int[4];
                    data[0]=i, data[1]=j+1, data[2]=k, data[3]=n;
                    q.push(data);
            }
            if ((j-1)>=0 )
                if( map[i][j-1][k]){
                    map[i][j-1][k]=0;
                    int *data=new int[4];
                    data[0]=i, data[1]=j-1, data[2]=k, data[3]=n;
                    q.push(data);
            }
            if ((k+1)<C )
                if( map[i][j][k+1]){
                    map[i][j][k+1]=0;
                    int *data=new int[4];
                    data[0]=i, data[1]=j, data[2]=k+1, data[3]=n;
                    q.push(data);
            }
            if ((k-1)>=0 )
                if( map[i][j][k-1]){
                    map[i][j][k-1]=0;
                    int *data=new int[4];
                    data[0]=i, data[1]=j, data[2]=k-1, data[3]=n;
                    q.push(data);
            }
        }

    }
    return 0;
}
int char2int(char c){
    switch(c){
        case 'E':
        case '.':
            return 1;
        case 'S':
        case '#':
            return 0;
    }
    return 0;
}
int main(void){
    char c;
    int end_i, end_j, end_k;
    while(cin >> L >> R >> C){
        if (!L && !R && !C)
            break;
        for(int i=0; i<32; ++i)
            for(int j=0; j<32; ++j)
                for (int k=0; k<32; ++k)
                    map[i][j][k]=0;
        for(int i=0; i<L; ++i)
            for(int j=0; j<R; ++j)
                for (int k=0; k<C; ++k){
                    cin >> c;
                    map[i][j][k]=char2int(c);
                    if (c=='S'){
                        int data[4]={i, j, k, 0};
                        q.push(data);
                    }
                    if (c=='E')
                        end_i=i, end_j=j, end_k=k;
                }
        int ans=bfs(end_i, end_j, end_k);
        if (ans)
            cout << "Escaped in "<< ans << " minute(s).\n";
        else
            cout << "Trapped!\n";
    }
    return 0;
}