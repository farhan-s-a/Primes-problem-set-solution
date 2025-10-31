#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;
typedef long long ll;

ll N=31624;
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

bool is_prime2(ll n) {

    if (n < N) return prime[n];

    for (int p : listofprime) {
        if (1LL * p * p > n) break;
        if (n % p == 0) return false;
    }
    return true;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout.tie(NULL);

    int s;
    cin >> s;

    while(s--){
        ll n;
        cin >> n;

        if(!is_prime2(n) || n>100000000L){
            cout << "-1" << endl;
            continue;
        }

        else if(n==1){
            cout << "1" << endl;
            continue;
        }
        
        int ans=0;
        bool valid=true;
        while(n>1){
            bool divided=false;
            for(int i=9;i>1;i--){
                if(n%i==0){
                    ans=ans*10+i;
                    n/=i;
                    divided=true;
                    break;
                }
            }
            if(!divided){
                cout << "-1" << endl;
                valid=false;
                break;
            }
        }

        if(valid){
            int finalAns=0;
            while(ans>0){
                finalAns=finalAns*10+(ans%10);
                ans /= 10;
            }
            cout << finalAns << endl;
        }
    }
    return 0;
}