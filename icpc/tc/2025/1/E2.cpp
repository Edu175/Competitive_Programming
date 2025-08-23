#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5;

vector<ii> get(vector<ii> a){
	ll n=SZ(a);
	set<ll>st={-1,n};
	vector<ii>ret(n);
	for(auto [v,i]:a){
		auto it=st.lower_bound(i);
		ret[i]={*prev(it),*it};
		st.insert(i);
	}
	return ret;
}

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		vv a(n);
		vector<ii>sa;
		vector<vv> pos(n+1);
		fore(i,0,n){
			cin>>a[i];
			sa.pb({a[i],i});
			pos[a[i]].pb(i);
		}
		sort(ALL(sa));
		auto mn=get(sa);
		sort(ALL(sa),[&](ii a, ii b){
			a.snd*=-1; b.snd*=-1;
			return a>b;
		});
		auto mx=get(sa);
		ll res=0;
		fore(c,1,n+1){
			auto &u=pos[c];
			fore(_,0,SZ(u)){
				ll i=u[_];
				ll v=k-a[i];
				if(v<0||v>n)continue;
				auto &vec=pos[v];
				auto p=upper_bound(ALL(vec),i);
				if(p==vec.end())continue;
				ll j=*p;
				// if(_+1<SZ(u)&&u[_+1]<j)continue;
				cout<<i<<" "<<j<<" prueba\n";
				if(mn[i].snd>mx[j].fst){
					ll term=(i-mn[i].fst)*(mx[j].snd-j);
					cout<<"good "<<term<<"\n";
					cout<<mn[i].fst<<","<<mn[i].snd<<" "<<mx[j].fst<<","<<mx[j].snd<<"\n";
					res+=term;
				}
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}