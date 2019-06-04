#include <iostream>
#include <string>
using namespace std;
int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string months[13] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

int Find_Month(string &m){
    for (int i=1; i<=12; ++i)
        if (m==months[i])
            return i;
    return 0;
}
bool leap(int year){
    int day=0;
    day+=(year%4)?0:1;
    day-=(year%100)?0:1;
    day+=(year%400)?0:1;
    return day;
}
int main(void){
    int year,day,month, add;
    int num;
    string data, M;
    cin >> num;
    for (int N=1; N<=num; ++N){
        cin >> data;
        cin >> add;
        year=0, M="", day=0;
        for (int i=0; i<4; ++i){
            year*=10;
            year+=data[i]-'0';
        }
        for (int i=5; i<data.length()-3; ++i)
            M+=data[i];
        month=Find_Month(M);
        for (int i=data.length()-2; i<data.length(); ++i){
            day*=10;
            day+=data[i]-'0';
        }
        for(int y=year;add; ++y){
            for(int M=month; M<=12 && add; M++){
                int l=days[M];
                if(M==2)
                    l+=leap(y);
                for(int d=day+1; d<=l; d++){
                    add--;
                    if(!add){
                        cout<<"Case "<<N<<": "<<y<<"-"<<months[M]<<"-";
                        printf("%.2d\n",d);
                        break;
                    }
                }
                day=0;
            }
            month=1;
        }
    }
    return 0;
}