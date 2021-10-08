#include <iostream>
#include <vector>

using namespace std;

int main(void){
    int n,result=0;
    vector< vector<int> > v;
    cin>>n;
    for(int i=0;i<=n;i++){
        vector<int> tmp(10);
        v.push_back(tmp);
    }
    for(int i=0;i<10;i++){
        v[0][i]=1;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<10;j++){
            for(int k=j;k<10;k++){
                v[i+1][k] = (v[i+1][k] + v[i][j])%10007;
            }
        }
    }
    for(int i=0;i<10;i++){
        result = (result+v[n-1][i])%10007;
    }
    cout<<result<<endl;
}
