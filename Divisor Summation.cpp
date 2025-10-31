#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;
typedef long long ll;

int N=709;
vector<bool> prime(N,true);
vector<int> primes;

void is_prime(){
    prime[0]=prime[1]=false;
    for(int i=2;i<N;i++){
        if(prime[i]){
            for(int j=i*i;j<N;j+=i){
                prime[j]=false;
            }
        }
    }
    for(int i=0;i<N;i++){
        if(prime[i]) primes.push_back(i);
    }
}

int sum_of_divisors(int n){
    int sum=1;
    for(int i:primes){
        if(i*i>n)
            break;
        if(n%i==0){
            int p=0;
            while(n%i==0){
                n/=i;
                p++;
            }
            int temp1=ceil(pow(i,p+1))-1;
            int temp2=i-1;
            //++ cout << "p: " << p << " i: " << i << " temp1: " << temp1 << " temp2: " << temp2 << endl;
            sum*=(temp1/temp2);
            //++ cout << sum << endl << endl;
        }
    }
    int temp1=ceil(pow(n,2))-1;
    int temp2=n-1;
    if(n>1) sum*=(temp1/temp2);
    //++ cout << "n: " << n << " temp1: " << temp1 << " temp2: " << temp2 << endl;
    //++ cout << sum << endl << endl;
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    is_prime();
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        cout << sum_of_divisors(n)-n << endl;
    }
    return 0;
}