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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		string a; cin>>a;
		set<ll>p8,p9;
		fore(i,0,n){
			if(a[i]=='(')p8.insert(i);
			else p9.insert(i);
		}
		if(SZ(p8)!=SZ(p9)){
			cout<<"-1\n";
			continue;
		}
		vector<ll>res(n);
		fore(i,0,n){
			if(a[i]==')')continue;
			cout<<i<<": "; imp(p9);
			auto x=p9.lower_bound(i);
			if(x!=p9.end()){
				res[i]=1,res[*x]=1;
				p8.erase(i),p9.erase(*x);
			}
		}
		/*fore(i,0,n){
			if(a[i]=='('||!p9.count(i))continue;
			auto x=p8.lower_bound(i);
			if(x!=p8.end()){
				res[i]=2,res[*x]=2;
				p9.erase(i),p8.erase(*x);
				//cout<<"2: "<<i<<" "<<*x<<"\n";
			}
		}*/
		imp(res);
		set<ll>st;
		fore(i,0,n)st.insert(res[i]);
		ll k=SZ(st);
		cout<<k<<"\n";
		if(k==1){
			fore(i,0,n)cout<<"1 ";
			cout<<"\n";
		}
		else{
			for(auto i:res)cout<<i+1<<" ";
			cout<<"\n";
		}
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home

