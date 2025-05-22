#include <bits/stdc++.h>
using namespace std;

void merge(vector<tuple<int,int,char>>& vec, int left, int mid, int right){
    int leftEnd = mid-left + 1;
    int rightEnd = right-mid;
    vector<tuple<int,int,char>> leftVec(leftEnd), rightVec(rightEnd);
    int i,j,k=left;

    for(i=0;i<leftEnd;i++){
        leftVec[i] = vec[left + i];
    }
    for(j=0;j<rightEnd;j++){
        rightVec[j] = vec[mid + 1 + j];
    }

    i=0;j=0;k=left;

    while(i<leftEnd and j<rightEnd){
        if(get<0>(leftVec[i]) < get<0>(rightVec[j])){
            vec[k] = leftVec[i];
            i++;
        }else{
            vec[k] = rightVec[j];
            j++;
        }
        k++;
    }
    while(i < leftEnd){
        vec[k] = leftVec[i];
        i++;
        k++;
    }
    while(j < rightEnd){
        vec[k] = rightVec[j];
        j++;
        k++;
    }

}

void mergeSort(vector<tuple<int,int,char>>& vec, int left, int right){
    if(left<right){
        int mid = left+(right-left)/2;

        mergeSort(vec,left,mid);
        mergeSort(vec,mid+1,right);

        merge(vec,left,mid,right);
    }
}


int main(){
    string str;
	cin >> str;
	vector<tuple<int,int,char>> vec;
	int pos=1,prefix=0;
	for(int i=0;i<str.size();i++){
		tuple<int,int,char> t(prefix,pos,str[i]);
		vec.push_back(t);

		pos++;
		if(str[i] == '('){
			prefix++;
		}else{
			prefix--;
		}
	}
    mergeSort(vec,0,str.size()-1);
	
    for(tuple<int,int,char> p : vec){
		cout << get<2>(p);
	}
}

