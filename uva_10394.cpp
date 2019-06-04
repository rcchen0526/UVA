# include <vector>
# include <iostream>
#define MAX 20000000
using namespace std;
int main(void){
    vector<bool> prime(20000000, true);
    vector<int> twin;
    for (int i=2; i<MAX; ++i){
        if (prime[i])
            for (int j=2*i; j<MAX; j+=i)
                prime[j]=false;
        if (prime[i-2]&&prime[i])
            twin.push_back(i-2);
    }
    int S;
    while(cin >> S)
        cout << "(" << twin[S+1] << ", " << twin[S+1]+2 << ")\n";
    return 0;
}