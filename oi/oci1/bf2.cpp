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
const ll MAXN=1e6+5;

string f(ll x, string a){
	if(x&1)swap(a[0],a[1]),swap(a[2],a[3]);
	if(x&2)swap(a[0],a[2]),swap(a[1],a[3]);
	return a;
}

int main(){FIN;
	ll n,m; cin>>n>>m; ll tipo; cin>>tipo;
	vector<string> a(n,string(m,'.')),b(n,string(m,'.'));
	fore(i,0,n)fore(j,0,m)cin>>a[i][j];
	fore(i,0,n)fore(j,0,m)cin>>b[i][j];
	//cout<<"rows\n";;fore(i,0,(n+1)/2)cout<<c[i]<<" ";;cout<<"\n";
	//cout<<"cols\n";;fore(i,0,(m+1)/2)cout<<c[n+i]<<" ";;cout<<"\n";
	ll can=0,res=MAXN;
	fore(mk,0,1ll<<(n+m)){
		ll flag=1,resi=__builtin_popcountll(mk);
		//if((n&1)&&((mk>>(n/2))&1)])continue;
		//if((m&1)&&((mk>>(n+m/2))&1))continue;
		auto ai=a;
		fore(i,0,n){
			if((mk>>i)&1)reverse(ALL(ai[i])),reverse(ALL(ai[n-1-i]));
		}
		fore(j,0,m){
			if((mk>>(n+j))&1){
				fore(i,0,n/2)swap(ai[i][j],ai[n-1-i][j]);
				fore(i,0,n/2)swap(ai[i][m-1-j],ai[n-1-i][m-1-j]);
			}
		}
		fore(i,0,n)fore(j,0,m)flag&=ai[i][j]==b[i][j];
		/*cout<<"rows ";;fore(i,0,n)cout<<((mk>>i)&1);;cout<<"\n";
		cout<<"cols ";;fore(i,0,m)cout<<((mk>>(n+i))&1);;cout<<"\n";
		fore(i,0,n){
			imp(ai[i]);
		}
		cout<<res<<" "<<flag<<"\n\n";*/
		if(flag)can=1,res=min(res,resi);
	}
	if(can){
		cout<<"YES\n";
		if(tipo)cout<<res<<"\n";
	}
	else {
		cout<<"NO\n";
	}
	return 0;
}
