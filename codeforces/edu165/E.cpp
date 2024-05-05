#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<endl
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>a(n),c(n),p[n];
		fore(i,0,n)cin>>a[i],a[i]--,p[a[i]].pb(i);
		/*vector<ii>ran;
		fore(i,0,n)if(SZ(p[i])){
			if(SZ(p[i])==1)ran.pb({0,-p[i][0]});
			else ran.pb({p[i].end()[-2]+1,-p[i].back()});
		}
		sort(ALL(ran));
		vector<ii>ran_;
		for(auto [l,r]:ran){
			r=-r;
			if(!SZ(ran_)||ran_.back().snd<r)ran_.pb({l,r});
		}
		ran=ran_;*/
		ll r=-1,q=0;
		vector<ii>b;
		vector<ll>bad(n),au(n);
		ll qb=0;
		fore(i,0,n){
			if(SZ(p[i])>1)au[p[i].end()[-2]]=1;
			else if(SZ(p[i])==1)bad[p[i][0]]=1;
		}
		//imp(au);
		//imp(bad);
		fore(i,0,n){
			//if(u[a[i]]==i){c[a[i]]--;continue;}
			//auto lwb=lower_bound(ALL(ran),(ii){i,n+5})
			#define agrego(i) {c[a[i]]++;if(c[a[i]]==1)q++;if(c[a[i]]==2)q--;qb+=bad[i];}
			#define saco(i) {c[a[i]]--;if(c[a[i]]==1)q++;if(c[a[i]]==0)q--;qb-=bad[i];}
			while(qb){
				saco(r);
				r--;
			}
			while(r<n-1&&r<i){
				++r;
				agrego(r);
			}
			while(!qb&&q){
				assert(r<n-1);
				++r;
				agrego(r);
			}
			//cout<<"["<<i<<","<<r<<"] "<<q<<" "<<qb<<" | "; imp(c);
			//imp(bad);
			if(!qb)b.pb({i,r});
			else b.pb({i,n-1});
			if(au[i])bad[p[a[i]].back()]=1,qb+=p[a[i]].back()<=r;
			saco(i);
		}
		vector<ii>d;
		for(auto [l,r]:b){
			while(SZ(d)&&d.back().snd>=r)d.pop_back();
			d.pb({l,r});
		}
		if(!SZ(d))cout<<"0\n";
		else {
			ll e=d[0].snd;
			ll res=1;
			for(auto [l,r]:d){
				if(e>=l)continue;
				else res++,e=r;
			}
			cout<<res<<"\n";
		}
	}
	return 0;
}
