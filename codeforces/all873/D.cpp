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

/*const ll K=13;//K such that 2^k>n    								SUBTAREA 1
#define oper min
ll st[K][1ll<<K];ll n;
void st_init(ll *a){
	fore(i,0,n)st[0][i]=a[i];
	fore(k,1,K)fore(i,0,n-(1ll<<k)+1)
		st[k][i]=oper(st[k-1][i],st[k-1][i+(1ll<<(k-1))]);
}
ll st_query(ll s,ll e){
	ll k=63-__builtin_clzll(e-s);
	return oper(st[k][s],st[k][e-(1ll<<k)]);
}*/
/*#define oper1 min
ll st1[K][1ll<<K];
void st1_init(ll *a){
	fore(i,0,n)st1[0][i]=a[i];
	fore(k,1,K)fore(i,0,n-(1ll<<k)+1)
		st1[k][i]=oper1(st1[k-1][i],st1[k-1][i+(1ll<<(k-1))]);
}
ll st1_query(ll s,ll e){
	ll k=63-__builtin_clzll(e-s);
	return oper1(st1[k][s],st1[k][e-(1ll<<k)]);
}*/
ll INF=1e9+5;
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll a[n];
		//map<ll,ll>id;
		fore(i,0,n)cin>>a[i];//,id[a[i]]=-1;
		/*ll c=0;
		for(auto &i:id)i.snd=c++;
		fore(i,0,n)a[i]=id[a[i]];*/
		ll res=0;
		fore(i,0,n)res+=(i+1)*(n-i);//,cout<<"("<<i+1<<")*("<<n-i<<")\n";
		res-=n*(n+1)/2;
		//cout<<"res "<<res<<"\n";
		//a[n]=-1;
		//st_init(a);
		//st1_init(a);
		/*vector<ll>r(n,n);
		fore(i,0,n){
			fore(j,i,n)if(a[j]<a[i]){
				r[i]=j;
				break;
			}
			ll s=i+1,e=n-1;
			while(s<=e){
				ll m=(s+e)/2;
				if(st_query(i,m+1)<a[i])e=m-1;
				else s=m+1;
			}
			r[i]=s;
		}*/
		//imp(a); //imp(r);
		set<pair<ll,ll>>st;
		fore(i,1,n)st.insert({-a[i],i});
		fore(i,1,n){
			vector<pair<ll,ll>>s;
			for(auto j:st)s.pb({-j.fst,j.snd});
			ll mx=-1,r=n;
			/*for(auto i:s)cout<<i.fst<<","<<i.snd<<" ";
			cout<<"\n";
			cout<<i<<": ";*/
			for(ll j=i-1;j>=0;j--){
				mx=max(mx,a[j]);
				while(SZ(s)&&s.back().fst<mx)r=min(r,s.back().snd),s.pop_back();
				res-=(r-i);
				//cout<<mx<<","<<j<<","<<r<<"("<<i-j<<"*"<<r-i<<") ";
			}
			//cout<<"\n";
			st.erase({-a[i],i});
		}
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
