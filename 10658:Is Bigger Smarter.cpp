#include <bits/stdc++.h>
using namespace std;

struct e{
	int id;
	int weight;
	int IQ;
};

bool cmp(const e &e1,const e &e2){
	if(e1.weight==e2.weight)
		return e1.IQ < e2.IQ ;
	return e1.weight > e2.weight ;
}

int main(){
	int n , m, id=1;
	vector<e> v;
	while(cin>>n>>m){
		e tmp ;
		tmp.id = id++ ;
		tmp.weight = n ;
		tmp.IQ = m ;
		v.push_back(tmp);
	}
	sort(v.begin(),v.end(),cmp);
	/*
	for(int i=0;i<v.size()-1;i++){
		if(v[i].weight==v[i+1].weight){
			v.erase(v.begin()+i+1);
			i--;
		}
	}
	*/
	int dp[(int)v.size()],re[(int)v.size()];
	for(int i=0 ; i<(int)v.size();i++){
		dp[i] = 1;
		re[i] = -1;
	}
	for(int i=1;i<(int)v.size();i++){
		int j=0;
		while(j<i){
			if(v[i].IQ>v[j].IQ && v[i].weight<v[j].weight){
				if(dp[i]<dp[j]+1){
					dp[i] = dp[j] +1 ;
					re[i] = j ;
				}
			}
			j++;
		}
	}
	int mi=0,ma=dp[0];
	for(int i=0 ; i<(int)v.size();i++){
		if(dp[i]>=ma){
			mi=i;
			ma=dp[i];
		}
		//cout << v[i].id << " " <<  v[i].weight << " " << v[i].IQ << endl;
	}
	cout << dp[mi] << endl ;
	while(1){
		cout << v[mi].id << endl ;
		mi = re[mi] ;
		if(mi==-1) break ;
	}
}
