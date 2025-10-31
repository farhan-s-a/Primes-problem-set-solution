#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;
typedef long long ll;

const int N = 46343;
vector<bool> prime(N, true);
vector<int> listofprime;

void is_prime() {
    prime[0] = prime[1] = false;
    for (int i = 2; i * i < N; ++i) {
        if (prime[i]) {
            for (int j = i * i; j < N; j += i) {
                prime[j] = false;
            }
        }
    }
    for (int i = 2; i < N; ++i) {
        if (prime[i]) {
            listofprime.push_back(i);
        }
    }
}

bool isPrimeLarge(ll n) {
    if (n < N) return prime[n];
    for (int p : listofprime) {
        if (1LL * p * p > n) break;
        if (n % p == 0) return false;
    }
    return true;
}

void distance(ll L, ll U) {
    vector<ll> range;

    for(ll i=L;i<=U;++i){
        if(isPrimeLarge(i)){
            range.push_back(i);
        }
    }

    if(range.size()<2){
        cout << "There are no adjacent primes." << endl;
        return;
    }

    ll min=1LL*N*N, max = 0;
    pair<ll,ll> minp,maxp;

    int len=range.size()-1;
    for (int i=0;i<len;i++) {
        int diff=range[i+1]-range[i];
        if (diff<min) {
            min=diff;
            minp={range[i],range[i+1]};
        }
        if(diff>max){
            max=diff;
            maxp={range[i],range[i+1]};
        }
    }

    cout << minp.first << "," << minp.second << " are closest, ";
    cout << maxp.first << "," << maxp.second << " are most distant." << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    is_prime();

    ll L,U;
    while(cin >> L >> U) {
        distance(L,U);
    }

    return 0;
}
