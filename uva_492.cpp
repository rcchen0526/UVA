#include <iostream>
#include <string>
using namespace std;
int main(void)
{
    string input_s;
    while(getline(cin, input_s)) {
        bool check_s=true;  //start and space set true
        string output_s="";
        char c='\0';        //replace first char
        for(int i=0; i<input_s.length(); ++i) {
            if(isalpha(input_s[i]) ){
                if(check_s){
                    switch(tolower(input_s[i]) ){
                        case 'a':
                        case 'e':
                        case 'i':
                        case 'o':
                        case 'u':
                            output_s.push_back(input_s[i]);
                            break;
                        default:
                            check_s=false;
                            break;
                    }
                    c=check_s?'\0':input_s[i];
                    check_s=false;
                }
                else
                    output_s.push_back(input_s[i]);
            }
            else{
                if(!check_s){
                    if(c!='\0')
                        output_s.push_back(c);
                    output_s.append("ay");
                    check_s=true;
                }
                output_s.push_back(input_s[i]);
            }
        }
        cout << output_s << endl;
    }
    return 0;
}