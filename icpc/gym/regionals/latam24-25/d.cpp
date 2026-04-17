#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=1005;
bool g[MAXN][MAXN];
ll ig(ll i, ll j){
	if(i==-1)return 0;
	return i==j;
}
bool comp(ii &a, ii &b){
	if(a.fst==-1) return true;
	vv c={a.fst,a.snd};
	vv d={b.fst,b.snd};
	assert(b.snd==-1);
	fore(i,0,2)fore(j,0,2){
		if(ig(c[i],d[j]))return 0;
	}
	return 1;
	// return !ig(a.fst,)
	// return a.fst!=b.fst&&a.fst!=b.snd;
}
void ania(ii &a, ll &pos){
	if(a.fst==-1) {a.fst=pos; return;}
	assert(a.snd==-1);
	a.snd=pos;
}
int main(){
	JET
	ll n; cin>>n;
	fore(i,0,n)fore(j,0,n){
		char x; cin>>x;
		g[i][j]=x=='1';
	}
	vector<ii> cliq(n,ii({-1,-1}));
	ll pos=0;
	fore(i,0,n){
		ll u=-1;
		if(cliq[i].fst!=-1&&cliq[i].snd!=-1) continue;
		bool ve=false;
		fore(j,0,n){
			ve|=g[i][j];
			if(g[i][j]&&comp(cliq[i],cliq[j])){
				u=j; break;
			}
		}
		if(!ve) {cliq[i].fst=pos++; continue;}
		if(u<i) continue;
		ania(cliq[i],pos);
		ania(cliq[u],pos);
		//cout<<"i "<<i<<"\n";
		fore(j,u+1,n){
			if(g[i][j]&&g[u][j]){
				assert(comp(cliq[i],cliq[j])&&comp(cliq[u],cliq[j]));
				ania(cliq[j],pos);
			}
		}
		pos++;
		if(cliq[i].snd!=-1) continue;
		ve=false;
		fore(j,u+1,n){
			if(g[i][j]&&comp(cliq[i],cliq[j])){
				u=j; ve=true; break;
			}
		}
		if(!ve) continue;
		ania(cliq[i],pos);
		ania(cliq[u],pos);
		fore(j,u+1,n){
			if(g[i][j]&&g[u][j]){
				ania(cliq[j],pos);
			}
		}
		pos++;
	}
	cout<<pos<<"\n";
	//fore(i,0,n)cout<<cliq[i].fst<<" "<<cliq[i].snd<<"\n";
	return 0;
}
/*
3
010
101
010
i 0
1
0 -1
0 -1
-1 -1
*/