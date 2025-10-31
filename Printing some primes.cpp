#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int N=1e8-1;
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

    int len=listofprime.size();

    for(int i=0;i<len;i+=100){
        cout << listofprime[i] << endl;
    }

    return 0;
}