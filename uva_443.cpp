# include <vector>
# include <string>
# include <iostream>
# include <algorithm> 

using namespace std;
vector<int> create_table(){
    vector<int> table(1,1);
    vector<int>::iterator it_2, it_3, it_5, it_7;
    int Min=0;
    for (int i=1; i<5842; ++i){
        for(it_2=table.begin();*it_2*2<=table[i-1]; ++it_2);
        for(it_3=table.begin();*it_3*3<=table[i-1]; ++it_3);
        for(it_5=table.begin();*it_5*5<=table[i-1]; ++it_5);
        for(it_7=table.begin();*it_7*7<=table[i-1]; ++it_7);

        Min=min( min(*it_2*2, *it_3*3), min(*it_5*5, *it_7*7) );
        table.push_back(Min);
    }
    return table;
}
int main(void){
    vector<int> table=create_table();
    int rank=0;
    while(cin >> rank){
        if (!rank)
            break;
        string order="";
        if ((rank%10)==1 && ((rank%100)>20 || (rank%100)<10))
            order="st humble number is ";
        else if ((rank%10)==2 && ((rank%100)>20 || (rank%100)<10))
            order="nd humble number is ";
        else if ((rank%10)==3 && ((rank%100)>20 || (rank%100)<10))
            order="rd humble number is ";
        else
            order="th humble number is ";
        cout << "The " << rank << order << table[rank-1] << ".\n";

    }
    return 0;
}