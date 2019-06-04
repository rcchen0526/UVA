# include <cmath>
# include <iomanip>
# include <iostream>
using namespace std;
int main(void){
    int num, Case=0;
    double x[202], y[202];
    double MAP[202][202]={0};
    cout.precision(3);
    while(cin >> num){
        if (!num)
            break;
        for (int i=0; i<202; ++i)
            for (int j=0; j<202; ++j)
                MAP[i][j]=0;
        for (int i=0; i<num; ++i)
            cin >> x[i] >> y[i];
        for (int i=1; i<num; ++i)
            for (int j=0; j<i; ++j){
                double dis=sqrt(pow((x[i]-x[j]), 2)+pow((y[i]-y[j]), 2));
                MAP[j][i]=MAP[i][j]=dis;
            }
        /*for (int i=0; i<num; ++i){
            for (int j=0; j<num; ++j){
                cout << MAP[i][j] << ' ';
            }cout << endl;
        }cout << endl;*/
        for (int k=2; k<num; ++k)
            for (int i=0; i<num; ++i)
                for(int j=1; j<num; ++j){
                    double MAX = max(MAP[i][k], MAP[k][j]);
                    if (MAP[i][j]>MAX)
                        MAP[i][j]=MAX;
                }

        cout << "Scenario #" << ++Case;
        cout << endl << "Frog Distance = " << fixed << MAP[0][1] << endl << endl;
    }
    return 0;
}