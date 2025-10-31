#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int N=3001;
vector<bool> prime(N,true);

void is_prime(){
    prime[0]=prime[1]=false;
    for(int i=2;i*i<N;i++){
        if(prime[i]){
            for(int j=i*i;j<N;j+=i) {
                prime[j]=false;
            }
        }
    }
}

bool almost_prime(int y){
    int a=0;
    for(int i=2;i<=y;i++){
        if(prime[i] && y%i==0){
            a++;
            if(a>2){
                return false;
            }
        }
    }
    return (a==2);
}

int cnt(int x){
    int ans=0;
    
    for(int i=6;i<=x;i++){
        if(!prime[i] && almost_prime(i)){
            ans++;
        }
    }

    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    is_prime();

    int n;
    cin >> n;

    int count=cnt(n);

    cout << count << endl;

    return 0;
}