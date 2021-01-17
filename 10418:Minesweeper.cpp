#include <bits/stdc++.h>

using namespace std ;


int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int m,n,f=1;
  stack<pair<int,int> > s;
  while(cin>>m>>n&&m){
    if(f!=1) cout << '\n' ;
    cout << "Field #" << f++ << ":\n" ;
    char mp[m][n] ;
    for(int i=0;i<m;i++){
      cin >> mp[i] ;
    }
    for(int i=0;i<m;i++){
      for(int j=0;j<n;j++){
        if(mp[i][j]=='.'){
          mp[i][j] = '0' ;
        }
        if(mp[i][j]=='*'){
          s.push(pair<int,int>(i,j));
        }
      }
    }
    while(!s.empty()){
      int a , b ;
      a = s.top().first-1 ;
      b = s.top().second-1 ;
      s.pop();
      for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
          if(a+i>=0&&a+i<m&&b+j>=0&&b+j<n){
            if(mp[a+i][b+j]!='*'){
              mp[a+i][b+j] ++ ;
            }
          }
        }
      }
    }
    for(int i=0;i<m;i++){
      for(int j=0;j<n;j++){
        cout << mp[i][j] ;
      }
      cout << endl ;
    }
  }
}
