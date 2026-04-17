#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) do{cerr<<#v<<": ";;for(auto i:v)cout<<i<<" ";;cout<<"\n";}while(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
typedef ll node;

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		vector<set<ll>> inds(2,{-1}); // inds in [1] are rev'd
		ll res=0;
		ll ty;
		auto rev=[&](ll p){
			if(ty)p=n-1-p;
			return p;
		};
		auto val=[&](ll i)->ll {
			if(i==-1)return 0;
			return a[rev(i)];
		};
		auto good=[&](ll i, ll j){return val(i)-ty<val(j);};
		auto goodvl=[&](ll v, ll j){return v-ty<val(j);};
		auto goodvr=[&](ll i, ll v){return val(i)-ty<v;};
		
		auto rang=[&](ll i, ll j)-> ll {
			assert(j<n);
			// if(j==n)return 0;
			return (j-i)*val(i);
		};
		
		fore(_ty,0,2){
			ty=_ty;
			auto &ind=inds[ty];
			fore(i,0,n){
				ll u=*ind.rbegin();
				if(good(u,i))res+=rang(u,i),ind.insert(i);
			}
		}
		
		auto rem=[&](ll i, ll d)-> void {
			// cerr<<"\nrem "<<i<<" "<<ty<<"\n";
			auto &ind=inds[ty];
			ll v=val(i)+d;
			auto it=ind.lower_bound(i);
			
			ll pr=*prev(it);
			
			// cerr<<"pr "<<pr<<"\n";
			
			// cerr<<val(pr)<<" "<<val(i)<<"\n";
			
			if(!goodvr(pr,v))return;
			
			// cerr<<"good\n";
			
			if(it!=ind.end()){
				ll del=rang(pr,*it);
				res-=del;
				// cerr<<"sacop "<<pr<<" "<<*it<<": "<<del<<"\n";
			}
			while(it!=ind.end()&&!goodvl(v,*it)){
				auto prox=next(it);
				if(prox!=ind.end()){
					ll del=rang(*it,*prox);
					res-=del;
					// cerr<<"saco "<<*it<<" "<<*prox<<": "<<del<<"\n";
				}
				it=ind.erase(it);
			}
			it=ind.insert(i).fst;
			
			res+=rang(pr,i);
			if(next(it)!=ind.end())res+=(*next(it)-i)*v;
		};
		
		ll sum=0;
		fore(i,0,n)sum+=a[i];
		// fore(ty,0,2)imp(inds[ty])
		ll q; cin>>q;
		while(q--){
			ll i,d; cin>>i>>d; i--;
			fore(_ty,0,2){
				ty=_ty;
				rem(rev(i),d);
			}
			sum+=d;
			a[i]+=d;
			ll mx=a[*inds[0].rbegin()];
			// cerr<<"mx: "<<mx<<"\n";
			ll cur=res+mx-sum;
			
			// fore(ty,0,2)imp(inds[ty])
			
			cout<<cur<<"\n";
		}
	}
	return 0;
}