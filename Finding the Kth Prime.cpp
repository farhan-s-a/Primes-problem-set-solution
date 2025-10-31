#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;
typedef long long ll;

const ll N=9e7;
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


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    is_prime();

    int Q;
    cin >> Q;
    while(Q--){
        int k;
        cin >> k;
        cout << listofprime[k-1] << endl;
    }
    return 0;
}