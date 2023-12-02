#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

bool check(vector<ll>a){
	vector<ll>vis(9);
	fore(i,0,SZ(a))vis[a[i]]=1;
	for(auto i:vis)if(!i)return 0;
	return 1;
}

int main(){FIN;
	vector<vector<ll>>a(9,vector<ll>(9));
	fore(i,0,9)fore(j,0,9){
		cin>>a[i][j];
		a[i][j]--;
	}
	ll res=1;
	fore(i,0,9){
		vector<ll>b;
		fore(j,0,9)b.pb(a[i][j]);
		res&=check(b);
	}
	fore(j,0,9){
		vector<ll>b;
		fore(i,0,9)b.pb(a[i][j]);
		res&=check(b);
	}
	fore(_i,0,3)fore(_j,0,3){	
		vector<ll>b;
		fore(i,_i*3,_i*3+3)fore(j,_j*3,_j*3+3)b.pb(a[i][j]);
		res&=check(b);
	}
	if(res)cout<<"Yes\n";
	else cout<<"No\n";
	return 0;
}
