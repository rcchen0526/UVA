# include <vector>
# include <iostream>
# include <algorithm>

using namespace std;

vector<int> base_2(int num){
    vector<int> output;
    while(num){
        output.push_back(num%(-2));
        num/=(-2);
        if(output[output.size()-1]==-1){
            output[output.size()-1]*=(-1);
            ++num;
        }
    }
    if(output.empty())
        output.push_back(0);
    return output;
}

int main(void){
    int num=0;
    cin >> num;
    for (int index=0; index<num; ++index){
        int input=0;
        cin >> input;
        vector<int> output;
        output = base_2(input);
        cout << "Case #" << index+1 << ": ";
        for(int i=output.size()-1; i>=0; --i)
            cout << output[i];
        cout << endl;
    }
    return 0;
}
