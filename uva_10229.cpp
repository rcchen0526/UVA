# include <cmath>
# include <iostream>

using namespace std;
long long int mod;
struct node{
    long long int a[2][2];
    node(){
        a[0][0]=a[0][1]=a[1][0]=a[1][1]=0;
    }
};
node mul(node x,node y){
    node ans;
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            for(int k=0;k<2;k++)
                ans.a[i][k]=(ans.a[i][k]+x.a[i][j]*y.a[j][k])%mod;
    return ans;
}

node find(node a,int n){
    node ans;
    ans.a[0][0]=ans.a[1][1]=1;
    while(n){
        if(n%2)
            ans=mul(ans,a);
        a=mul(a,a);
        n/=2;
    }
    return ans;
}
int main(void){

    node temp;
    int n, m;
    temp.a[0][0]=temp.a[1][0]=temp.a[0][1]=1;
    while(cin>>n>>m){
        mod=pow(2, m);
        node ans=find(temp,n);
        cout<<ans.a[1][0]<<endl;
    }
    return 0;
}