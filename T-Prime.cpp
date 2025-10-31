#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

typedef long long ll;
using namespace std;
int N=1e6+1;
vector<bool> prime(N,true);

void is_prime(){
    prime[0]=prime[1]=false;
    for(int i=2;i*i<N;i++){
        if(prime[i]){
            for(int j=i*i;j<N;j+=i) {
                prime[j]=false;
            }
        }
    }
}

bool ifT(ll num){
    ll sqrt_num=sqrt(num);

    return (prime[sqrt_num] && (sqrt_num*sqrt_num==num));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    is_prime();

    int n;
    cin >> n;

    vector<ll> x(n);
    vector<int> y(n);

    for(int i=0;i<n;i++){
        cin >> x[i];
        if(ifT(x[i])) y[i]=1;
        else y[i]=0;
    }

    for(int i=0;i<n;i++){
        if(y[i]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}