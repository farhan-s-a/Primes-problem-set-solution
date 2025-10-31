#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<set>
using namespace std;

const int N=10000000;
vector<bool> prime(N, true);

void is_primes() {
    prime[0]=prime[1]=false;
    for(int i=2;i*i<N;++i){
        if(prime[i]){
            for(int j=i*i;j<N;j+=i){
                prime[j]=false;
            }
        }
    }
}

bool is_anagrammatic_prime(int num){
    string s=to_string(num);
    sort(s.begin(),s.end());
    do{
        if(!prime[stoi(s)]) return false;
    }
    while(next_permutation(s.begin(),s.end()));
    return true;
}

int next_power_of_10(int n) {
    int p=10;
    while(p<=n) p*=10; 
    return p;
}

int main() {
    is_primes();
    int n;
    while(cin >> n && n != 0){
        int upper=next_power_of_10(n);
        bool found=false;
        for(int i=n+1;i<upper;++i){
            if(prime[i] && is_anagrammatic_prime(i)){
                cout << i << endl;
                found=true;
                break;
            }
        }
        if(!found) cout << 0 << endl;
    }
    return 0;
}
