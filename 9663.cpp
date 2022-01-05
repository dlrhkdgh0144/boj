#include <vector>
#include <string>
#include <iostream>

using namespace std;

int cnt=0;
vector<vector<int> > mark;

void check(int n, int t){
    for(int i=0;i<n;i++){
        int flag=1;
        for(int j=0;j<t;j++){
            if(mark[j][i]>0||(i+j>=t&&mark[j][i-t+j]>0)||(i+t-j<n&&mark[j][i+t-j]>0)){//check
                flag=0;
                break;
            }
        }
        if(flag==1){
            if(t<n-1){
                mark[t][i]=1;
                check(n,t+1);
                mark[t][i]=0;
            }
            else{
                cnt++;
            }
        }
    }
}

int main(void){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        vector<int> v(n);
        mark.push_back(v);
    }
    check(n,0);
    cout<<cnt<<endl;
    return 0;
}
