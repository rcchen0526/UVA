# include <map>
# include <string>
# include <iostream>
using namespace std;
char str2int(char c){
    switch(c){
        case 'A': case 'B': case 'C':
            return '2';
        case 'D': case 'E': case 'F': 
            return '3';
        case 'G': case 'H': case 'I':
            return '4';
        case 'J': case 'K': case 'L':
            return '5';
        case 'M': case 'N': case 'O':
            return '6';
        case 'P': case 'R': case 'S':
            return '7';
        case 'T': case 'U': case 'V':
            return '8';
        case 'W': case 'X': case 'Y':
            return '9';
    }
    return 0;
}
string Std(string s){
    string STD="";
    for (int i=0; i<7; ++i){
        if (i==3)
            STD.push_back('-');
        STD.push_back(s[i]);
    }
    return STD;
}
int main(void){
    int num;
    cin >> num;
    while(num--){
        map<string, int> mapnumber;
        map<string, int>::iterator iter;
        int N;
        string temp;
        cin >> N;
        getline(cin, temp);
        while(N--){
            getline(cin, temp);
            string number="";
            for (int i=0; i<temp.length(); ++i){
                if (isdigit(temp[i]))
                    number.push_back(temp[i]);
                if (isalpha(temp[i]))
                    number.push_back(str2int(temp[i]));
            }
            iter = mapnumber.find(number);
            if(iter != mapnumber.end())
                ++iter->second;
            else
                mapnumber[number]=1;
        }
        bool duplicates=true;
        for(iter=mapnumber.begin(); iter!=mapnumber.end(); iter++)
            if(iter->second>1)
                cout << Std(iter->first) << ' ' << iter->second << endl, duplicates=false;
        if (duplicates)
            cout << "No duplicates.\n";
        if (num)
            cout << endl;
    }
    return 0;
}