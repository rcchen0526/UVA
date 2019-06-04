# include <map>
# include <string>
# include <iostream>
#include <sstream>
using namespace std;

string int2str(int val){
    ostringstream out;
    out<<val;
    return out.str();
}
void buble_sort(int* arr){
    for (int i = 4; i > 0; --i)
        for (int j = 0; j < i; ++j)
            if (arr[j]>arr[j+1])
                swap(arr[j], arr[j+1]);
}
int main(void){
    int course[5];
    int num;
    while (cin >> num){
        if (!num)
            break;
        int MAX=1, ans=0;
        map<string, int> course_map;
        map<string, int>::iterator iter;
        while(num--){
            for (int i=0; i<5; ++i)
                cin >> course[i];
            buble_sort(course);
            string temp="";
            for(int i=0; i<5; ++i)
                temp+=int2str(course[i]);
            iter=course_map.find(temp);
            if(iter != course_map.end()){
                ++iter->second;
                MAX=iter->second>MAX?iter->second:MAX;
            }
            else
                course_map[temp]=1;
        }
        for(iter = course_map.begin(); iter != course_map.end(); iter++)
            if (MAX==iter->second)
                ans+=iter->second;
        cout << ans << endl;
    }
    return 0;
}