#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;
typedef long long ll;

ll N=8000000;
vector<bool> prime(N+1, true);
vector<int> listofprime;

void is_prime(){
    prime[0]=prime[1]=false;
    for(ll i=2; i*i<=N; i++){
        if(prime[i]){
            for(ll j=i*i; j<=N; j+=i){
                prime[j]=false;
            }
        }
    }
    for(ll i=2; i<=N; i++){
        if(prime[i]){
            listofprime.push_back(i);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    is_prime();
    int num;
    while(cin>>num && num!=0){
        cout << num << " = ";
        int a, b;
        for(int p : listofprime){
            if(prime[p] && prime[num-p]){
                a=p;
                b=num-a;
                break;
            }
        }
        cout << a << " + " << b << "\n";
    }
    return 0;
}