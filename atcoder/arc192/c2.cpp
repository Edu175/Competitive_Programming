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
const ll MAXN=5005;

ll info[2][MAXN];
ll ask(ll s, ll t){
	cout<<"? "<<s+1<<" "<<t+1<<endl;
	ll ret; cin>>ret;
	return ret;
}
ll n;

pair<vv,vv> solve(){
	
	ll mx=1;
	fore(i,1,n)if(info[0][i]>info[0][mx])mx=i;
	
	if(mx==1){
		
	}
	ll fg=0;
	if(info[1][mx]>info[0][mx])fg=1;
	if(fg)swap(info[0],info[1]);
	vv a(n),p(n);
	p[mx]=n-1;
	a[1]=info[0][1]+info[1][mx]-info[0][mx];
	
	
	
	
	if(fg)swap(a[0],a[1]),reverse(ALL(p));
	vv b(n);
	fore(i,0,n)b[p[i]]=a[i];
	return {p,b};
	// if(fg)swap(info[0],info[1]);
}


int main(){FIN;
	fore(i,1,n)info[0][i]=ask(0,i);
	info[1][0]=info[0][1];
	fore(i,2,n)info[1][i]=ask(1,i);
	
	auto [p,a]=solve(0);
	// if(!SZ(p)){
	// 	auto par=solve(1);
	// 	p=par.fst,a=par.snd;
	// }
	cout<<"! ";
	for(auto i:p)cout<<i+1<<" ";
	for(auto i:a)cout<<i<<" ";
	cout<<endl;
	return 0;
}
