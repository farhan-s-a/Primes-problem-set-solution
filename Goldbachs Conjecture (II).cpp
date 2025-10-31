#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;
typedef long long ll;

ll N=31622778;
vector<bool> prime(N+1,true);
vector<ll> primes;

void is_prime(){
    prime[0]=prime[1]=false;
    for(ll i=2;i*i<=N;i++){
        if(prime[i]){
            for(ll j=i*i;j<=N;j+=i){
                prime[j]=false;
            }
        }
    }
    for(ll i=2;i<=N;i++){
        if(prime[i]){
            primes.push_back(i);
        }
    }
}

bool prime2(ll n){
    if(n<=N) return prime[n];
    for(ll p:primes){
        if(p*p>N)  break;
        if(n%p==0) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    is_prime();

    ll n;
    while(cin>>n && n){
        ll ans=0;
        if(prime2(n-2)){
            ans++;
        }
        for(ll i=3;i<=n/2;i+=2){
            if(i>n/2) break;
            if(prime2(i) && prime2(n-i)){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
}