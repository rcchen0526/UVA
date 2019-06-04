# include <iostream>
using namespace std;
int decide_days(int year, int month){
    switch (month){
        case 1: case 3:
        case 5: case 7:
        case 8: case 10:
        case 12:
            return 31;
        case 4: case 6:
        case 9: case 11:
        return 30;
        case 2:
            if (year<=1752){
                int day=28;
                day+=(year%4)?0:1;
                return day;
            }
            else{
                int day=28;
                day+=(year%4)?0:1;
                day-=(year%100)?0:1;
                day+=(year%400)?0:1;
                return day;
            }
    }
    return 0;
}

int main(void){
    int Day, Month, Year;
    while(true){
        cin >> Month >> Day >> Year;
        if (!Year && !Month && !Day)
            break;
        if (Year==1752 && Month==9 && (Day>2 && Day<14) ){
            cout << Month << "/" << Day << "/" << Year << " is an invalid date.\n";
        }
        else{
            if (!decide_days(Year, Month))
                cout << Month << "/" << Day << "/" << Year << " is an invalid date.\n";
            else if(decide_days(Year, Month)-Day<0)
                cout << Month << "/" << Day << "/" << Year << " is an invalid date.\n";
            else if (Month<1 || Day<1)
                cout << Month << "/" << Day << "/" << Year << " is an invalid date.\n";
            else{
                int output=6;
                output+=Year-1;
                for(int i=1; i<Month; ++i)
                    output+=decide_days(Year, i);
                output+=(Day-1);
                output+=((Year-1)/4);
                if(Year==1752&&Month==9&&Day>13)
                    output-=4;
                else if (Year==1752&&Month>9)
                    output-=4;
                else if(Year>1752){
                    output-=4;
                    output-=((Year-1701)/100);
                    output+=((Year-1601)/400);
                }
                string Month_voc="";
                switch(Month){
                    case 1: Month_voc="January"; break; case 2: Month_voc="February"; break;
                    case 3: Month_voc="March"; break; case 4: Month_voc="April"; break;
                    case 5: Month_voc="May"; break; case 6: Month_voc="June"; break;
                    case 7: Month_voc="July"; break; case 8: Month_voc="August"; break;
                    case 9: Month_voc="September"; break; case 10: Month_voc="October"; break;
                    case 11: Month_voc="November"; break; case 12: Month_voc="December"; break;
                }
                string Day_voc="";
                output%=7;
                switch(output){
                    case 0: Day_voc="Sunday"; break; case 1: Day_voc="Monday"; break;
                    case 2: Day_voc="Tuesday"; break; case 3: Day_voc="Wednesday"; break;
                    case 4: Day_voc="Thursday"; break; case 5: Day_voc="Friday"; break;
                    case 6: Day_voc="Saturday"; break;
                }
                cout << Month_voc << " " << Day << ", " <<  Year << " is a " << Day_voc << endl;

            }
        }
    }
    return 0;
}
