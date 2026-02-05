#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cerr<<i<<" "; cerr<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
typedef vector<vector<bool>> mat;
ll N=9;
int main(){FIN;
	// vector<vector<mat>> all(9);
	ll n;
	vector<set<ii>> pares(N+1);
	vector<map<ii,mat>> gra(N+1);
	while(cin>>n){
		mat g(n,vector<bool>(n));
		fore(i,0,n)fore(j,0,n){
			bool c; cin>>c;
			g[i][j]=c;
		}
		if(n>N)continue;
		vv wh(n,1);
		fore(i,0,n/2)wh[i]=0;
		vv mx(2);
		do{
			if(wh[0])break;
			vv ids,ids0;
			fore(i,0,n){
				if(wh[i])ids.pb(i);
				else ids0.pb(i);
			}
			do{
				vv c(2);
				fore(i,0,n/2)c[g[ids0[i]][ids[i]]]++;
				mx[0]=max(mx[0],c[0]);
				mx[1]=max(mx[1],c[1]);
			}while(next_permutation(ALL(ids)));
		}while(next_permutation(ALL(wh)));
		ii par={mx[0],mx[1]};
		if(!pares[n].count(par)){
			pares[n].insert(par);
			gra[n][par]=g;
		}
	}
	fore(n,1,N+1){
		cout<<"\n\nn "<<n<<":\n";
		vector<ii> a(ALL(pares[n]));
		vector<ii> b;
		for(auto i:a){
			ll bad=0;
			for(auto j:a)bad|=i!=j&&i.fst>=j.fst&&i.snd>=j.snd;
			if(!bad)b.pb(i);
		}
		for(auto i:b){
			cout<<i.fst<<","<<i.snd<<":\n";
			auto g=gra[n][i];
			fore(i,0,n){
				fore(j,0,n)cout<<g[i][j];
				cout<<"\n";
			}
			cout<<"\n";
		}
	}
	return 0;
}