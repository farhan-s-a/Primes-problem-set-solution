#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        bool allsame=true;
        for(int i=0;i<n;i++){
            cin >> a[i];
            if(a[i]!=a[0]){
                allsame=false;
            }
        }
        if(allsame){
            cout << 1 << endl;
            continue;
        }
        int ans=1;
        for(int i=0;i<n-1;i++){
			//++ cout << "i: " << i << "ans: " << ans << endl;
            if(a[i]>a[i+1]){
                for(int j=i+1;j<n-1;j++){
					i=j;
					//++ cout << "j: " << j << "ans: " << ans << endl;
                    if(a[j]<a[j+1]){
                        ans++;
                        break;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}