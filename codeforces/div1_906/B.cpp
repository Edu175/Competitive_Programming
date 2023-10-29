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
const ll MAXN=2e5+5;

ll a[MAXN],vis[MAXN];
ll n,c,mn[2];

void mv(ll w){
	while(w<n&&(vis[mn[w]]||(w&&mn[0]==mn[1])))mn[w]++;
}

set<ii>st;

ll cnt(ll i){
	return (a[i]+(i+1)-1)/(i+1);
}

void add(ll i, ll j){
	cout<<"add "<<i<<"--"<<j<<"\n";
	if(i>j)swap(i,j);
	cout<<i<<" "<<j<<": "<<a[i]<<" "<<a[j]<<"\n";
	st.erase({-cnt(j),j});
	vis[j]=1;
	st.erase({-cnt(i),i});
	a[i]+=a[j];//max(a[i],a[j]);
	cout<<i<<" "<<j<<": "<<a[i]<<" "<<a[j]<<"\n";
	st.insert({-cnt(i),i});
	mv(0),mv(1);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>c;
		fore(i,0,n)cin>>a[i];
		fore(i,0,n){
			vis[i]=0;
		}
		mn[0]=0,mn[1]=0;
		mv(0),mv(1);
		if(SZ(st))st.clear();
		fore(i,0,n)st.insert({-cnt(i),i});
		ll flag=1;
		fore(i,0,n-1){
			ll x=st.begin()->snd;
			if(x==mn[0])x=next(st.begin())->snd;
			cout<<mn[0]<<" "<<mn[1]<<"\n";
			cout<<x<<"--"<<mn[0]<<": "<<cnt(x)<<">="<<(mn[0]+1)*c<<"\n";
			cout<<mn[0]<<"--"<<mn[1]<<": "<<cnt(mn[0])<<">="<<(mn[1]+1)*c<<"\n";
			if(cnt(x)>=(mn[0]+1)*c)add(x,mn[0]);
			else if(cnt(mn[0])>=(mn[1]+1)*c)add(mn[0],mn[1]);
			else {
				flag=0;
				break;
			}
		}
		if(flag)cout<<"Yes\n";
		else cout<<"No\n";
		//cout<<endl;
	}
	return 0;
}
