#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define forr(i,a,b) for(ll i=b-1,jet=a;i>=jet;--i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

vv lis(vv a){
	vv v;
	vv ans(SZ(a));
	fore(idx,0,SZ(a)){
		auto x=a[idx];
		if(!x)continue;
		ll p=lower_bound(ALL(v),x)-v.begin();
		if(p==SZ(v))v.pb(x);
		else v[p]=x;
		ans[idx]=p+1;
	}
	return ans;
}

int main(){FIN;
	while(1){
		ll n; cin>>n;
		if(!n)break;
		vv a(n+2);
		vv zs;
		fore(i,1,n+1){
			cin>>a[i];
			if(a[i])a[i]++;
			else zs.pb(i);
		}
		a[n+1]=n+2; a[0]=1;
		n=SZ(a);
		vv le=lis(a);
		auto na=a; reverse(ALL(na));
		for(auto &i:na)i=-i;
		vv ri=lis(na); reverse(ALL(ri));
		ll k=*max_element(ALL(le));
		vector<vv> posl(n+1),posr(n+1);
		fore(i,0,n)if(a[i]){
			posl[le[i]].pb(i);
			posr[ri[i]].pb(i);
		}
		// for(auto i:le)cout<<i<<" ";;cout<<"\n";
		// for(auto i:ri)cout<<i<<" ";;cout<<"\n";

		// vector<ii> rans;
		// cerr<<"k "<<k<<"\n";
		vv swep(n+7);
		fore(c,0,k+1){
			// cerr<<"c "<<c<<"\n";
			auto &u=posl[c];
			auto &v=posr[k-c];
			vector<ii> ev;
			for(auto i:u)ev.pb({i,1});
			for(auto i:v)ev.pb({i,-1});
			sort(ALL(ev));
			multiset<ll> st;
			for(auto i:v)st.insert(a[i]);
			// for(auto i:u)cout<<i<<" ";;cout<<"\n";
			// for(auto i:v)cout<<i<<" ";;cout<<"\n";
			ll mn=n+5;
			fore(i,0,SZ(ev)){
				auto [idx,del]=ev[i];
				if(del==1)mn=min(mn,a[idx]);
				else st.erase(a[idx]);
				if(!SZ(st))continue;
				ll mx=*st.rbegin();
				// rans.pb({mn+1,mx});
				if(mx-(mn+1)<=0)continue;
				ll cant=lower_bound(ALL(zs),ev[i+1].fst)-lower_bound(ALL(zs),idx);
				if(i+1==SZ(ev)||!cant)continue;
				// cerr<<"cant "<<cant<<"\n";
				// cerr<<idx<<" "<<ev[i+1].fst<<"\n";
				// cout<<"found "<<mn<<","<<mx<<": "<<idx<<"\n";
				swep[mn+1]++;
				swep[mx]--;
			}
		}
		ll res=0,cnt=0;
		// cout<<"swep: ";;for(auto i:swep)cout<<i<<" ";;cout<<endl;
		assert(!swep[0]&&!swep[1]);
		fore(i,2,n){
			cnt+=swep[i];
			ll good=cnt>0;
			ll cur=(i-1)*(k-2+good);
			res+=cur;
			// cout<<i-1<<": "<<k-2+good<<"\n";
		}
		cout<<res<<"\n";
	}
}