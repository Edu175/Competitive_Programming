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
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<pair<char,char>>v(n);
		map<ll,map<char,ll>>m;
		ll res=0;
		fore(i,0,n){
			cin>>v[i].fst>>v[i].snd;
			m[v[i].fst][v[i].snd]++;
			for(char j='a'; j<'l';j++){
				if(j!=v[i].snd)res+=m[v[i].fst][j];
			}
			for(char j='a'; j<'l';j++){
				if(j!=v[i].fst)res+=m[j][v[i].snd];
			}
		}
		cout<<res<<"\n";
	}		
	return 0;
}

