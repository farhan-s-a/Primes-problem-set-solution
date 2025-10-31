#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;
typedef long long ll;

const ll N=5000001;
vector<bool> prime(N,true);
vector<ll> listofprime;

void is_prime(){
    prime[0]=prime[1]=false;
    for(ll i=2;i*i<N;i++){
        if(prime[i]){
            for(ll j=i*i;j<N;j+=i) {
                prime[j]=false;
            }
        }
    }
    for(ll i=2;i<N;i++){
        if(prime[i]){
            listofprime.push_back(i);
        }
    }
}

const ll MOD=100000007;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	is_prime();

	int n,len=listofprime.size();
	while(cin >> n && n){
		ll result=1;
		for(int i=0;i<len && listofprime[i]<=n;i++){
			ll divisorSum=0;
			int temp=n,div=listofprime[i];
			while(temp/listofprime[i]){
				ll a=temp/listofprime[i];
				divisorSum += a*(n%div+1)+(a)*(a-1)/2*div;
				temp/=listofprime[i];
				div*=listofprime[i];
			}
			if(divisorSum>=MOD)
				divisorSum%=MOD;
			result=result*(divisorSum+1);
			if(result>=MOD)
				result%=MOD;
		}
		cout << result << endl;
	}
	return 0;
}