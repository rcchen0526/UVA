# include <string>
# include <sstream>
# include <iostream>
using namespace std;
int main(void){
    string lineA, lineB;
    while(getline(cin, lineA)){
        getline(cin, lineB);
        int setA[100], setB[100];
        int countA=0, totalA=-1, countB=0, totalB=-1;
        stringstream ss;
        ss<<lineA;
        while(ss>>setA[++totalA]);
        ss.str("");
        ss.clear();
        ss<<lineB;
        while(ss>>setB[++totalB]);
        for (int i=0; i<totalA; ++i)
            for (int j=0; j<totalB; ++j)
                if (setA[i]==setB[j]){
                    ++countA;
                    break;
                }
        for (int i=0; i<totalB; ++i)
            for (int j=0; j<totalA; ++j)
                if (setB[i]==setA[j]){
                    ++countB;
                    break;
                }
        if (countA==totalA && totalA<totalB)
            cout << "A is a proper subset of B\n";
        else if (countB==totalB && totalB<totalA)
            cout << "B is a proper subset of A\n";
        else if (!countA && !countB)
            cout << "A and B are disjoint\n";
        else if (countA==totalA && countB==totalB && totalA==totalB)
            cout << "A equals B\n";
        else
            cout << "I'm confused!\n";
    }
    return 0;
}