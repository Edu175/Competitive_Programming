#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
ll n,m;

ii operator+(ii a, ii b){return {a.fst+b.fst,a.snd+b.snd};}
ii cv(ll x){return {x/m,x%m};}
ll cv(ii x){return m*x.fst+x.snd;}
bool allowed(ii x){
	if(x.fst<0||x.fst>=n||x.snd<0||x.snd>=m)return 0;
	return 1;
}
int main(){FIN;
	cin>>n>>m; ll d[2]; cin>>d[0]>>d[1]; d[0]--,d[1]--;
	char a[n*m];
	fore(i,0,n*m)cin>>a[i];
	ii mx={-1,1};
	fore(x,0,n*m)if(a[x]=='.'){
		set<ll>st;
		fore(i,-1,2)if(i)fore(j,-1,2)if(j)fore(w,0,2){
			ii y={i*d[0],j*d[1]};
			if(w)swap(y.fst,y.snd);
			y.fst+=cv(x).fst;
			y.snd+=cv(x).snd;
//				cout<<"dir "<<i<<","<<j<<": "<<y.fst-(w?cv(x).snd:cv(x).fst)<<","<<y.snd-(w?cv(x).fst:cv(x).snd)<<"  ";
//			cout<<y.fst<<","<<y.snd<<"\n";
			if(allowed(y))st.insert(cv(y));
		}
		ll c=0;
		for(auto y:st)c+=a[y]=='*';
		ii r={c,-x};
		mx=max(mx,r);
//		cout<<cv(x).fst<<","<<cv(x).snd<<": "; imp(st); cout<<c<<"\n";
	}
	ll x=-mx.snd;
	cout<<cv(x).fst+1<<" "<<cv(x).snd+1<<"\n";
	return 0;
}
