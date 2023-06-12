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
template<class x> ostream & operator<<(ostream & out, vector<x> v){
    out<<"{ ";
    for(auto y : v) out<<y<<" ";
    out<<"}";
    return out;
}	

int main(){//FIN;
	string win="win";
	map<char,ll>pos;
	fore(i,0,3)pos[win[i]]=i;
	map<vector<ll>,ll>id;
	set<vector<ll>>st;
	vector<vector<ll>>is;
	vector<ll> pr(4,1); fore(i,1,4)pr[i]=pr[i-1]*3;
	fore(bt,0,pr[3]){
		vector<ll>p(3);
		fore(i,0,3)p[i]=(bt/pr[i])%3;
		sort(ALL(p));
		st.insert(p);
	}
	for(auto i:st)is.pb(i);
	//cout<<is<<"\n";
	fore(i,0,SZ(is))id[is[i]]=i;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		string a[n];
		vector<ll> b[n];
		vector<ll>h[10];
		fore(i,0,n){
			cin>>a[i];
			fore(j,0,3)b[i].pb(pos[a[i][j]]);
			sort(ALL(b[i]));
			vector<ll> oc(3,0);
			for(auto j:b[i])oc[j]++;
			h[id[b[i]]].pb(i);
		}
		//cout<<id[{0,0,0}]<<" "<<id[{1,1,1}]<<" "<<id[{2,2,2}]<<"\n";
		vector<vector<ll>>res;
		imp(h);
		while(SZ(h[0])||SZ(h[6])||SZ(h[9])){
			cout<<SZ(h[0])<<" "<<SZ(h[6])<<" "<<SZ(h[9])<<"\n";
			if(!SZ(h[0])){
				vector<ll>&x=h[6],&y=h[9];
				vector<ll>add={x.back(),1,y.back(),2};
				res.pb(add);
				h[id[{1,1,2}]].pb(y.back());
				h[id[{1,2,2}]].pb(x.back());
				x.pop_back(),y.pop_back();
			}
			else if(!SZ(h[1])){
				vector<ll>&x=h[0],&y=h[9];
				vector<ll>add={x.back(),0,y.back(),2};
				res.pb(add);
				h[id[{0,0,2}]].pb(y.back());
				h[id[{0,2,2}]].pb(x.back());
				x.pop_back(),y.pop_back();
			}
			else if(!SZ(h[2])){
				vector<ll>&x=h[0],&y=h[6];
				vector<ll>add={x.back(),0,y.back(),1};
				res.pb(add);
				h[id[{0,0,1}]].pb(y.back());
				h[id[{0,1,1}]].pb(x.back());
				x.pop_back(),y.pop_back();
			}
		}
		imp(h);
		fore(i,0,SZ(h[1]))vector<ll>add={h[1][i],0,h[8][i],2};
		fore(i,0,SZ(h[2]))vector<ll>add={h[2][i],0,h[7][i],1};
		fore(i,0,SZ(h[3]))vector<ll>add={h[3][i],1,h[5][i],2};
		cout<<SZ(res)<<"\n";
		for(auto v:res){
			cout<<v[0]+1<<" "<<win[v[1]]<<" "<<v[2]+1<<" "<<win[v[3]]<<"\n";
		}
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
