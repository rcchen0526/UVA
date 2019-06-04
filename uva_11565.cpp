# include <iostream>
using namespace std;
int main(void){
    int num;
    cin >> num;
    while(num--){
        int A, B, C;
        bool check=true;
        cin >> A >> B >> C;
        for (int x=-100; 3*x<A && check; ++x){
            if (!x)
                continue;
            if (x*x>C || B%x)
                continue;
            for (int y=x+1; x+2*y<A && check; ++y){
                int z=A-x-y;
                if (y < z && x*y*z == B && x*x+y*y+z*z == C){
                    check=false;
                    cout << x << ' ' << y << ' ' << z << endl;
                }
            }
        }
        if (check)
            cout << "No solution." << endl;
    }
    return 0;
}