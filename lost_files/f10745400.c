#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;


int main(){FIN;
	ll t; cin>>t;ll te=t;
	while(t--){
		cout<<"Case #"<<te-t<<": ";
		ll n; cin>>n;
		string a[n];
		set<char> imp;
		set<char> implr;
		set<char> l;
		set<char> r;
		bool flag=1;
		map<string,ll>m;
		set<ll>au;
		fore(i,0,n){
			cin>>a[i];
			au.insert(i);
			fore(j,0,SZ(s[i])){
				if(j!=0){
					if(s[i][j]==s[i][j-1]){
						continue;
					}
				}
				else if(implr.count(s[i][j])||implr.count(s[i][0]))flag=0;
				if(imp.count(s[i][j]))flag=0;
				if(j==0){
					if(r.count(s[i][j]))implr.insert(s[i][j]);
					else l.insert(s[i][j]);
				}
				else if(j!=SZ(s[i])-1) imp.insert(s[i][j]);
				else{
					if(l.count(s[i][j]))implr.insert(s[i][j]);
					else r.insert(s[i][j]);
				}
			}
			m[s[i][0]+"0"]=i;
			m[s[i][SZ(s[i])-1]+"1"]=i;
		}
		vector<string> res;
		if(flag){
			fore(i,0,n){
			string r;
				while(r){
				
				if(au.count(i)!=0){
					if(m[s[i][SZ(s[i])-1]+'0'])
				}
			}
		}
		else cout<<"IMPOSSIBLE";
	}
	return 0;
}
