# include <cstdio>
# include <vector>
# include <string>
# include <iostream>

using namespace std;
vector<int> stack;
vector<string> paper;
int M;
void comb(int n, int curi){
    if(n==stack.size()){
        for (int i=0; i<stack.size(); ++i){
            cout << paper[stack[i]];
            if (i!=stack.size()-1)
                cout << ", ";
        }
        cout << endl;
        return;
    }
    else if (curi>=paper.size())
        return;
    stack.push_back(curi);
    comb(n, curi+1);
    stack.pop_back();
    comb(n, curi+1);
}
int main(){
    int r1, r2, num;
    char buf[16];
    string input_s="";
    cin >> num;
    getline(cin, input_s);
    getline(cin, input_s);
    while(num--){
        stack.clear();
        paper.clear();
        r1=-1, r2=-1;
        cin.getline(buf,16);
        if(buf[0]=='*')
            r1=0;
        else{
            sscanf(buf,"%d %d",&r1,&r2);
            if(r2==-1)r2=r1;
        }
        while(1){
            getline(cin, input_s);
            if (!input_s.length())
                break;
            paper.push_back(input_s);
            input_s="";
        }
        if(r1==0){
            r1=1;
            r2=paper.size();
        }

        for (int i=r1; i<=r2; ++i){
            cout << "Size "<< i << endl;
            comb(i, 0);
            cout << endl;
        }
        if(num)
            cout << endl;
    }
    
    return 0;
}