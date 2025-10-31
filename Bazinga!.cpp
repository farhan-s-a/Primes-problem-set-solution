#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;
typedef long long ll;

ll N=5263698;
vector<bool> prime(N+1, true);
vector<ll> primes;
ll P=10527450;
vector<bool> prod(P+1, false);
vector<ll> prods;

void Prime(){
    prime[0]=prime[1]=false;
    for(ll i=2;i*i<=N;i++){
        if(prime[i]){
            for(ll j=i*i;j<=N;j+=i){
                prime[j]=false;
            }
        }
    }
    for(ll i=2;i<=N;i++){
        if(prime[i]) primes.push_back(i);
    }
}

void Prod(){
    for(ll i=0;i<primes.size();i++){
        for(ll j=i+1;j<primes.size();j++){
            ll product = primes[i] * primes[j];
            if(product <= P){
                prod[product] = true;
            } else {
                break;
            }
        }
    }
    for(ll i=6;i<=P;i++){
        if(prod[i]) prods.push_back(i);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Prime();
    Prod();
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        cout << prods[n-1] << endl;
    }
    return 0;
}