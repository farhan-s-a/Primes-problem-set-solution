#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

int N=1e5+1;
vector<bool> prime(N,true);

void is_prime(){
    prime[0]=prime[1]=false;
    for(int i=0;i*i<=N;i++){
        if(prime[i]){
            for(int j=i*i;j<=N;j+=i){
                prime[j]=false;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    is_prime();
    int n;
    cin>>n;

    if(n<3) cout << 1 << endl;
    else cout << 2 << endl;

    for(int i=0;i<n;i++){
        if(prime[i+2]) cout << 1 << " ";
        else cout << 2 << " ";
    }
    return 0;
}