#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;
typedef long long ll;

ll power(ll b,ll p){
    if(p==0){
        return 1;
    }
    if(p%2==0){
        return power((b*b),(p/2));
    }
    else{
        return (b*power((b*b),(p-1)/2));
    }
}

vector<ll> prime;
ll N=1e8+1;
void sieve(){
    bool isPrime[N];
    for(ll i=0;i<=N;++i){
        isPrime[i]=i%2;
    }
    isPrime[1]=false;
    isPrime[2]=true;
    for(ll i=2;i*i<=N;++i){
        if(isPrime[i]){
            for(ll j=i*i;j<=N;j+=2*i){
                isPrime[j]=false;
            }
        }
    }
    for(ll i=0;i<=N;++i){
        if(isPrime[i]){
            prime.push_back(i);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll t=1;
    cin >> t;
    sieve();
    while(t--){
        ll n;
        cin >> n;
        ll f=n;
        ll output=1;
        for(ll i=0;i<prime.size() && prime[i]*prime[i]<=n;i++){
            if(n%prime[i]==0){
                ll count=0;
                while(n%prime[i]==0){
                    n/=prime[i];
                    count++;
                }
                output*=((power(prime[i],count+1)-1)/(prime[i]-1));
            }
        }
        if(n!=1){
            output*=(n+1);
        }
        cout << output-f << endl;
    }
}