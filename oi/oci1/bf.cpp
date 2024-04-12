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
	vector<vector<string>>a(n,vector<string>(m,string(1,'0')));
	fore(i,0,n)fore(j,0,m)cin>>a[i][j][0];
	vector<vector<string>>b(n,vector<string>(m,string(1,'0')));
	fore(i,0,n)fore(j,0,m)cin>>b[i][j][0];
	fore(i,0,(n+1)/2)fore(j,0,(m+1)/2){
		a[i][j]+=a[i][m-1-j]+a[n-1-i][j]+a[n-1-i][m-1-j];
		b[i][j]+=b[i][m-1-j]+b[n-1-i][j]+b[n-1-i][m-1-j];
	}
	
	//cout<<"rows\n";;fore(i,0,(n+1)/2)cout<<c[i]<<" ";;cout<<"\n";
	//cout<<"cols\n";;fore(i,0,(m+1)/2)cout<<c[n+i]<<" ";;cout<<"\n";
	ll can=0,res=MAXN;
	fore(mk,0,1ll<<(n+m)){
		vector<ll>c(n+m);
		fore(i,0,n+m)c[i]=(mk>>i)&1;
		if((n&1)&&c[n/2])continue;
		if((m&1)&&c[n+m/2])continue;
		ll flag=1,resi=__builtin_popcountll(mk);
		//cout<<"rows ";;fore(i,0,n)cout<<((mk>>i)&1);;cout<<"\n";
		//cout<<"cols ";;fore(i,0,m)cout<<((mk>>(n+i))&1);;cout<<"\n";
		fore(i,0,(n+1)/2)fore(j,0,(m+1)/2){
			ll x=2*c[n+j]+c[i];
			//cout<<x<<": "<<a[i][j]<<"--> "<<f(x,a[i][j])<<" == "<<b[i][j]<<"\n";
			flag&=f(x,a[i][j])==b[i][j];
		}
		
		//cout<<resi<<" "<<flag<<"\n\n";
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
