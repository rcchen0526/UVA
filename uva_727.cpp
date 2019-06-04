# include <iostream>
# include <stack>
# include <string>
using namespace std;

int op2num(char op) {
    switch (op){
        case '(':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
    }
    return -1;
}

int main(void){
    stack<char> op;     //store operator
    int N=0;            //N means N tests
    string temp;        // temp means newline
    string input;
    cin >> N;
    getline(cin, temp);
    getline(cin, temp);
    while(N--){
        string output="";
        int num=0;          //means()
        while(true){
            getline(cin, input);
            if (input.length()==0)
                break;
            if(input[0]=='(')
                op.push(input[0]);
            else if(input[0]==')'){
                while (op.top() != '(') {
                    output.push_back(op.top());
                    op.pop();
                }
                op.pop();
            }
            else if(!isdigit(input[0])){
                if(op.empty() || op2num(input[0]) > op2num(op.top()) )
                    op.push(input[0]);
                else{
                    while(op2num(op.top()) >= op2num(input[0])){
                        output.push_back(op.top());
                        op.pop();
                        if(op.empty())
                            break;
                    }
                    op.push(input[0]);
                }
            }
            else
                output.push_back(input[0]);
        }
        while(!op.empty()){
            output.push_back(op.top());
            op.pop();
        }
        cout << output << endl;
        if(N)
            cout << endl;
    }
    return 0;
}
