# include <iostream>
# include <iomanip>
# include <string>
using namespace std;
bool check(int num){
    if(num<10)
        return 0;
    else if (num<100){
        if (num/10==num%10)
            return 0;
    }
    else if (num <1000){
        if (num/100==num%10)
            return 0;
    }
    else{
        int h1=num/1000, h2=(num/100)%10;
        int m=num%100;
        if (h2*10+h1==m)
            return 0;
        else
            return 1;
    }
    return 1;
}
int main(void){
    int num;
    cin >> num;
    while(num--){
        string data;
        int h, m;
        cin >> data;
        h=(data[0]-'0')*10+(data[1]-'0');
        m=(data[3]-'0')*10+(data[4]-'0');
        do{
            m+=1;
            if (m==60)
                m=0, h+=1;
            if (h==24)
                h=0;
        }while(check(h*100+m));
        cout << setw(2) << setfill('0') << h << ':' 
        << setw(2) << setfill('0') << m << endl;
    }
    return 0;
}