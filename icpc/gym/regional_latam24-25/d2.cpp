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
	//assert(b.snd==-1);
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
bool comp2(ii &a, ii &b){
	if((ig(a.fst,b.fst)&&(a.snd!=-1&&b.snd!=-1))||(ig(a.snd,b.snd)&&(a.fst!=-1&&b.fst!=-1))||(ig(a.fst,b.snd)&&(a.snd!=-1&&b.fst!=-1))||(ig(a.snd,b.fst)&&(a.fst!=-1&&b.snd!=-1))) 			
					return true;
	return false;
}
ll upd(ii &a, ii &b){
	vv c={a.fst,a.snd};
	vv d={b.fst,b.snd};
	//assert(b.snd==-1);
	ll r;
	fore(i,0,2)fore(j,0,2){
		if(ig(c[i],d[j])){r=c[i];c[i]=-1; d[j]=-1;break;}
	}
	a.fst=c[0];a.snd=c[1];
	b.fst=d[0];b.snd=d[1];
	return r;
}

int main(){
	JET
	ll n; cin>>n;
	fore(i,0,n)fore(j,0,n){
		char x; cin>>x;
		g[i][j]=x=='1';
	}
	vector<ii> cliq(n,ii({-1,-1}));
	vv tamanio;
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
		if(!ve) {cliq[i].fst=pos++; tamanio.pb(1); continue;}
		if(u<i) continue;
		tamanio.pb(2);
		ania(cliq[i],pos);
		ania(cliq[u],pos);
		//cout<<"i "<<i<<"\n";
		fore(j,u+1,n){
			if(g[i][j]&&g[u][j]){
				assert(comp(cliq[i],cliq[j])&&comp(cliq[u],cliq[j]));
				tamanio.back()++;
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
		tamanio.pb(2);
		ania(cliq[i],pos);
		ania(cliq[u],pos);
		fore(j,u+1,n){
			if(g[i][j]&&g[u][j]){
				tamanio.back()++;
				ania(cliq[j],pos);
			}
		}
		pos++;
	}
	ll EL_UUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU=0;
	fore(i,0,n){
		fore(j,i+1,n){
			if(comp2(cliq[i],cliq[j])){
				
			//	cout<<i<<" "<<j<<"\n";
			//	cout<<cliq[i].fst<<" "<<cliq[i].snd<<"   "<<cliq[j].fst<<" "<<cliq[j].snd<<"\n";
				if((tamanio[upd(cliq[i],cliq[j])]-=2)+2<3)pos--;EL_UUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU=j;break;
				
			}
		}
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