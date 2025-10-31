#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;
typedef long long ll;

const ll N=31626;
vector<bool> prime(N,true);
vector<int> listofprime;

void is_prime(){
    prime[0]=prime[1]=false;
    for(int i=2;i*i<N;i++){
        if(prime[i]){
            for(int j=i*i;j<N;j+=i) {
                prime[j]=false;
            }
        }
    }

    for(int i=2;i<N;i++){
        if(prime[i]){
            listofprime.push_back(i);
        }
    }
}


int numDivisor(int n){
    int ans=1;
    for(int i=0;i<listofprime.size()&&listofprime[i]*listofprime[i]<=n;i++){
        int cnt=0;
        while(n%listofprime[i]==0){
            n/=listofprime[i];
            cnt++;
        }
        ans*=(cnt+1);
    }
    if(n!=1) ans*=2;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    is_prime();
    int t, l, u;
    cin >> t;
    while(t--) {
        cin >> l >> u;
        int ans=-1,highest=-1;
        for(int i=l;i<=u;i++) {
            int count=numDivisor(i);
            if(count>highest) {
                ans=i;
                highest=count;
            }
        }
        cout << "Between " << l << " and " << u << ", " << ans << " has a maximum of " << highest << " divisors." << endl;
    }
}