# include <vector>
# include <string>
# include <iostream>
# include <algorithm>
using namespace std;
bool comp(string a, string b){
return (a+b) > (b+a);
}
int main(void){
    int num;
    while(cin >> num){
        if(!num)
            break;
        vector<string> input;
        for (int i=0; i<num; ++i){
            string item="";
            cin >> item;
            input.push_back(item);
        }
        sort(input.begin(), input.end(), comp);
        for (int i=0; i<input.size(); ++i)
            cout << input[i];
        cout << endl;
    }
    return 0;
}