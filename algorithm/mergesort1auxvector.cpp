#include<bits/stdc++.h>
using namespace std;

int n;
void merge(vector<int> &v,int i,int m,int j){
    vector<int> Vaux(j-i+1);
    for(int k=i;k<=m;k++){
        Vaux[k]=v[k];
    }
    for(int k=m+1;k<=j;k++){
        Vaux[j-k+m+1]=v[k];
    }
    int l=i,r=j;
    for(int k=i;k<=j;k++){
        if(Vaux[l]<=Vaux[r] and l<=m){
            v[k]=Vaux[l];
            l++;
        }else{
            v[k]=Vaux[r];
            r--;
        }
    }
}

void mergesort(vector<int> &v,int i,int j){
    if(i<j){
        int m = (i+j)/2;
        mergesort(v,i,m);
        mergesort(v,m+1,j);
        merge(v,i,m,j);
    }
}

void test_case(){
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    for(int i=0;i<n;i++) cout << v[i] << " ";
    cout << endl;
    mergesort(v,0,n-1);
    for(int i=0;i<n;i++) cout << v[i] << " ";
    cout << endl;
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	test_case();
}

