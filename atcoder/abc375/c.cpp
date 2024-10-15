#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

ll n;
string go(vector<ii> pos, string h){
	// cout<<"go ";
	// for(auto [x,y]:pos)cout<<x<<","<<y<<" ";;cout<<"| "<<h<<":\n";
	string r=h;
	ll c=n+5;
	fore(i,0,4)c=min({c,pos[i].fst,n-1-pos[i].fst,pos[i].snd,n-1-pos[i].snd});
	c++;
	fore(i,0,c%4){
		string hi=h;
		fore(i,0,4)h[(i+1)%4]=hi[i];
	}
	// cout<<c<<": "<<h<<"\n";
	return h;
}

int main(){FIN;
	cin>>n;
	vector<vector<char>>a(n,vector<char>(n));
	fore(i,0,n)fore(j,0,n)cin>>a[i][j];
	vector<vv> vis(n,vv(n,0));
	fore(i,0,n)fore(j,0,n)if(!vis[i][j]){
		ll r=i,c=j;
		vector<ii>pos; string s;
		while(SZ(pos)<4){
			pos.pb({r,c});
			s.pb(a[r][c]);
			vis[r][c]=1;
			ll ri=c,ci=n-1-r;
			r=ri,c=ci;
		}
		s=go(pos,s);
		fore(i,0,4)a[pos[i].fst][pos[i].snd]=s[i];
	}
	fore(i,0,n){
		fore(j,0,n)cout<<a[i][j];
		cout<<"\n";	
	}
	return 0;
}
