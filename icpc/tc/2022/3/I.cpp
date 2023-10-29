#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;

bool comp(pair<ll,ll>p1, pair<ll,ll>p2){
	return p1.snd-p1.fst < p2.snd-p2.fst;
}

int main(){FIN;
	ll n,k; cin>>n>>k;
	ll a[n];
	map<ll,vector<ll>>mp;
	fore(i,0,n){
		cin>>a[i];
		mp[a[i]].pb(i);
	}
	vector<pair<ll,ll>> ex;
	for(auto i:mp){
		if(SZ(i.snd)>=k){
			//ll dif=1e6;
			fore(j,0,SZ(i.snd)){
				if(j+k-1>=SZ(i.snd))break;
				/*if(i.snd[j+k-1]-i.snd[j]<=dif)*/
				ex.pb({(i.snd[j]),(i.snd[j+k-1])});
			}
		}
	}
	fore(i,0,SZ(ex)){
		cout<<ex[i].fst<<" "<<ex[i].snd<<" | ";
	}
	cout<<"\n";
	sort(ALL(ex),comp);
	fore(i,0,SZ(ex)){
		cout<<ex[i].fst<<" "<<ex[i].snd<<" | ";
	}
	cout<<"\n";
	set<ll> l,r;
	ll res=0;
	l.insert(-1),l.insert(1e6),r.insert(n);
	fore(i,0,SZ(ex)){
		ll prel=*(prev(l.lower_bound(ex[i].fst)));
		ll prer=*(r.lower_bound(ex[i].snd));
		if(i&&prel==-1&&prer==1e6) 5;
		else {
			res+=(ex[i].fst+1-(prel+1))*(n-ex[i].snd-(n-prer));
			cout<<(ex[i].fst+1-(prel+1))*(n-ex[i].snd-(n-prer))<<"\n";
			l.insert(ex[i].fst);
			r.insert(ex[i].snd);
		}
	}
	pres;
	return 0;
}
