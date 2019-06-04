# include <vector>
# include <string>
# include <iostream>
using namespace std;
int main(void){
    int K, E, Case=0;
    while(cin >> K >> E){
        int max_num=0;
        string temp;
        vector<string> raw_data;
        vector<string> data;
        vector<string> keyword;
        vector<int> excuse_num;
        for (int i=0; i<K; ++i){
            cin >> temp;
            keyword.push_back(temp);
        }
        getline(cin, temp);
        for (int i=0; i<E; ++i){
            getline(cin, temp);
            raw_data.push_back(temp);
        }
        for (int i=0; i<raw_data.size(); ++i){
            bool new_word=true;
            string word="";
            for (int j=0; j<raw_data[i].length(); ++j){
                if(isalpha(raw_data[i][j])){
                    word.push_back(tolower(raw_data[i][j]));
                    new_word=true;
                    if (j==raw_data[i].length()-1)
                        data.push_back(word);
                }
                else if (new_word){
                    new_word=false;
                    data.push_back(word);
                    word="";
                }
            }
            excuse_num.push_back(0);
            for (int j=0; j<data.size(); ++j)
                for (int k=0; k<keyword.size(); ++k)
                    if (data[j]==keyword[k])
                        ++excuse_num[i];

            max_num=max(max_num, excuse_num[i]);
            data.clear();
        }
        cout << "Excuse Set #" << ++Case << endl;
        for (int i=0; i<excuse_num.size(); ++i){
            if (excuse_num[i]==max_num)
                cout << raw_data[i] << endl;
        }
        cout << endl;
    }
    return 0;
}