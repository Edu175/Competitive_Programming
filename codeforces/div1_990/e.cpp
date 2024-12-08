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
const ll INF=1e10;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,sdhf; cin>>n>>sdhf;
		vector<pair<ii,ii>>a;
		set<ll>st;
		fore(i,0,n){
			ll ai,b,s; cin>>ai>>b>>s;
			a.pb({{ai,0},{b,s}});
			st.insert(s);
		}
		ll cnt=-1;
		auto get=[&](){
			cnt++;
			while(st.count(cnt))cnt++;
			return cnt;
		};
		fore(h,0,2){
			ll k; cin>>k;
			fore(i,0,k){
				ll p; cin>>p; p--;
				a[p].fst.snd=h;
			}
		}
		sort(ALL(a)); reverse(ALL(a));
		auto _a=a;
		auto check=[&](vector<ii>ps)->bool{
			if(SZ(ps)>5*n)return 0; //
			ll mn0=INF,mx1=0;
			map<ll,ll>mp;
			for(auto [d,t]:ps){
				if(mp.count(t))return 0;
				mp[t]=d;
			}
			sort(ALL(ps));
			for(auto i:_a){
				auto [fs,sn]=i;
				auto [a,gr]=fs;
				auto [b,s]=sn;
				ll q=lower_bound(ALL(ps),ii({a,INF}))-ps.begin();
				if(mp.count(s)&&b>=mp[s]&&a<mp[s])q++;
				if(gr)mx1=max(mx1,q);
				else mn0=min(mn0,q);
				// cout<<gr<<","<<q<<" ";
			}
			// cout<<endl;
			return mn0>mx1;
		};
		
		// for(auto i:a){
		// 	cout<<i.fst.fst<<","<<i.fst.snd<<","<<i.snd.fst<<","<<i.snd.snd<<" ";
		// }cout<<"\n-->\n";
		
		ll did0=0,did1=0;
		while(SZ(a)&&a.back().fst.snd==1)a.pop_back(),did1=1;
		ll divi=a.back().fst.fst;
		reverse(ALL(a));
		while(SZ(a)&&a.back().fst.snd==0)a.pop_back(),did0=1;
		reverse(ALL(a));
		
		// for(auto i:a){
		// 	cout<<i.fst.fst<<","<<i.fst.snd<<","<<i.snd.fst<<","<<i.snd.snd<<" ";
		// }cout<<"\n";
		
		if(!SZ(a)){
			cout<<"1\n"<<divi<<" "<<get()<<"\n";
			continue;
		}
		ll s=a.back().fst.fst;
		ll e=a[0].fst.fst+1;
		map<ll,ll>ss,es;
		for(auto [i,dat]:a){
			auto [b,s]=dat;
			if(i.snd){
				if(!ss.count(s))ss[s]=b+1;
				ss[s]=max(ss[s],b+1);
			}
			else {
				if(!es.count(s))es[s]=b;
				es[s]=min(es[s],b);
			}
		}
		ll flag=1;
		vector<ii>ps;
		for(auto [spe,b]:es){
			// ll si=ss.count(spe)?ss[spe]:-1;
			ll si=ss[spe];
			if(si>b)flag=0;
			else {
				ll k=-1;
				// if(si<=s)k=si; // como que no puedo ganar un problema dos veces?
				if(b>=e)k=b;
				flag&=k>=0;
				ps.pb({k,spe});
			}
		}
		if(!flag)cout<<"-1\n";
		else {
			if(did1){
				fore(_,0,3)ps.pb({s,get()});
			}
			if(did0){
				fore(_,0,3)ps.pb({e,get()});
			}
			if(!check(ps))cout<<"WA\n";
			cout<<SZ(ps)<<"\n";
			for(auto i:ps)cout<<i.fst<<" "<<i.snd<<"\n";
			// cout<<endl;
			assert(check(ps));
		}
	}
	return 0;
}
