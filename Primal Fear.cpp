#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int N=1000001;
vector<bool>prime(N,true);
vector<int> feared(N,0);

void is_prime(){
    prime[0]=prime[1]=false;
    for (int i=2;i*i<N;i++){
        if(prime[i]){
            for(int j=i*i;j<N;j+=i){
                prime[j]=false;
            }
        }
    }
}

bool isAfraidPrime(int x){
    int temp=x, div=1;
    while(temp>0){
        if(temp%10==0) return false;
        temp/=10;
        div*=10;
    }

    while(div>1){
        if(!prime[x%div]) return false;
        div/=10;
    }
    return true;
}

int cnt(){
	for(int i = 2;i < N; i++){
		feared[i] = feared[i-1];

		if(prime[i] && isAfraidPrime(i)){
				feared[i]++;
		}
	}
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    is_prime();
    cnt();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

            cout << feared[n] << endl;

        }
    return 0;
}