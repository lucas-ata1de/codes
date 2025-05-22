##include <bits/stdc++.h>
using namespace std;
long long maxSubArray(vector<long long> v){
    long long max_current = v[0];
    long long max_global = v[0];
    for(long long j=1;j<v.size();j++){
        max_current = max(v[j], max_current + v[j]);
        max_global = max(max_current,max_global);
    }
    return max_global;
}
void test_case(){
    long long n;
    cin >> n;
    vector<long long> v(n);
    for(long long i=0;i<n;i++){
        cin >> v[i];
    }
    cout << maxSubArray(v) << endl;
}
int main(){
    test_case();
 
}
