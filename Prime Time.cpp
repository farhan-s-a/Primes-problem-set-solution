#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<vector>

using namespace std;

int N=1e7+2;
vector<bool> prime(N, true);
vector<int> primes;

void is_prime(){
    prime[0]=prime[1]=false;
    for(int i=2;i*i<=N;i++){
        if(prime[i]){
            for(int j=i*i;j<=N;j+=i){
                prime[j]=false;
            }
        }
    }
    for(int i=2;i<=N;i++){
        if(prime[i]) primes.push_back(i);
    }
}

bool prime2(int n){
    if(n<N) return prime[n];
    for(int i:primes){
        if(i*i>n) return true;
        if(n%i==0) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    is_prime();
    int a,b;
    while(cin >> a >> b){
        int t=b-a+1;
        int p=0;
        for(int i=a;i<=b;i++){
            int x=i*i+i+41;
            if(prime2(x)) p++;
        }
        float ans=(p/(float)t)*100;
        cout << fixed << setprecision(2) << ans << "%" << endl;
    }
    return 0;
}