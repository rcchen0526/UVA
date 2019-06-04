# include <map>
# include <string>
#include <iomanip>
# include <iostream>
using namespace std;
int main(void){
    int num=0;
    string temp;
    cin >> num;
    getline(cin, temp);
    getline(cin, temp);
    cout.precision(4);
    while (num--){
        float total=0.0;
        string specy;
        map<string, float> specy_map;
        map<string, float>::iterator it;
        while(getline(cin, specy) ){
            if (specy.length()==0)
                break;
            total+=1.0;
            it = specy_map.find(specy);
            if (it != specy_map.end())
                it->second+=1.0;
            else
                specy_map[specy] = 1.0;
        }
        for (it=specy_map.begin(); it!=specy_map.end(); ++it){
            double per=(it->second/total)*100;
            cout << it->first << " " << fixed << per << '\n';
        }
        if(num)
            cout << endl;
    }
    return 0;
}