#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int randint(int i, int k){
	if (i>k){
		int j=i;
		i=k;
		k=j;
	}
	return i + rand()%(k-i+1);
}
bool sampling(vector <int> & vec, vector<int> & res, int k ){
	srand(time(NULL));
	int count = vec.size();
	if(count < k)
		return false;
	for(int i=0; i<k; i++){
		res.push_back(vec[i]);
	}
	for(int i=k; i <count; i++){
		int j = randint(0,i);
		if(j < k)
			res[j] = vec[i];
	}
	return true;
}
int main(int argc, char *argv[]) {
	int n, k;
	cin>>n>>k;
	vector<int> vec(n);
	vector<int> res;
	for(int i=0; i<n; i++){
		cin>>vec[i];
	}
	if(sampling(vec, res, k)){
		for(int i=0; i<k; i++)
		cout<<res[i]<<" ";
	}
	
}