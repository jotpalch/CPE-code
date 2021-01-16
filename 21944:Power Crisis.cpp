#include <bits/stdc++.h>

using namespace std ;

int main(){

  int n;
  while(cin>>n&&n){
    for(int j=1;;j++){
      int pl = 0;
      vector<int> p  ;
      for(int i=1;i<=n;i++){
        p.push_back(i);
      }
      while((int)p.size()>1){
        p.erase(p.begin()+pl);
        pl = pl+j-1;
        while(pl>=(int)p.size()){
          pl -= (int)p.size();
        }
      }
      if(p[0]==13){
        cout << j << endl ;
        break;
      }
    }
  }

}
