#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
 
using namespace std;
 
int N=1e8-1;
vector<bool> prime(N+1,true);
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
 
void where_is_it(int x) {
    int row=1;
    int start_of_row=0;
    int len=listofprime.size();
    while(start_of_row+row<=len) {
        int end_of_row=start_of_row+row;
 
        if(listofprime[end_of_row-1]>=x){
            auto it=find(listofprime.begin()+start_of_row, listofprime.begin()+end_of_row,x);
            int col=distance(listofprime.begin()+start_of_row,it) + 1;
            cout << row << " " << col << endl;
            return;
        }
 
        start_of_row += row;
        row++;
    }
}
        
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    is_prime();
 
    int t;
    cin >> t;
 
    while(t--){
        int x;
        cin >> x;
        if(!prime[x]){
            cout << "-1" << endl;
            continue;
        }
        else{
            where_is_it(x);
        }
    }
    return 0;
}