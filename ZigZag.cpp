//https://arena.topcoder.com/#/u/practiceCode/1239/1209/1259/1/1239
#include <bits/stdc++.h>
using namespace std;
int longestZigZag(vector <int> seq){
 	if(seq.size()<3)
 		return seq.size();
 	vector<int> temp;
 	temp.push_back(0);
 	temp.push_back(seq[0]);
 	int i=1;
 	while(i<seq.size() && seq[i] == seq[0])i++;
 	if(i==seq.size())return 1;
 	temp.push_back(seq[i]);
 	if(seq[i]>seq[0])
 		temp[0]=0;
 	else
 		temp[0]=1;
 	i++;
 	while(i<seq.size()){
 		if(seq[i]==temp[temp.size()-1]){
 			i++;
 			continue;
 		}
 		if(temp[0]==0 && seq[i]<temp[temp.size()-1]){
 			temp.push_back(seq[i]);
 			temp[0]=1;
 		}
 		else if(temp[0]==0 && seq[i]>temp[temp.size()-1])
 			temp[temp.size()-1]=seq[i];
 		else if(temp[0]==1 && seq[i]>temp[temp.size()-1]){
 			temp.push_back(seq[i]);
 			temp[0]=0;
 		}
 		else if(temp[0]==1 && seq[i]<temp[temp.size()-1])
 			temp[temp.size()-1]=seq[i];
 		i++;
 	}
 	return temp.size()-1;
 }
int main() {
	int n;
	cin>>n;
	vector<int> v(n);
	int i=0;
	while(n--){
		cin>>v[i++];
	}
	cout<<longestZigZag(v);
	return 0;
}

 
