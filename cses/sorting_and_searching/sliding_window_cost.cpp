#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

ll k;
set<ii>st;
ll mid;
ll sl=0,sr=0;
ll calc(ll x){
	return mid*x-sl+sr-(k-mid)*x;
}

int main(){FIN;
	ll n; cin>>n>>k;
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i];
	mid=(k+1)/2-1;
	fore(i,0,k)st.insert({a[i],i});
	auto it=st.begin();
	auto p=it;
	fore(j,0,k){
		if(j==mid)p=it;
		if(j<mid)sl+=it->fst;
		else sr+=it->fst;
		it++;
	}
	cout<<calc(p->fst)<<" ";
	ll ac=mid;
	fore(i,k,n){
		cout<<"["<<i<<":"<<distance(st.begin(),p)<<"|"<<ac<<"|"<<mid<<"]"<<endl;
		ii h={a[i],i};
		if(h<*p)ac++,sl+=h.fst;
		else sr+=h.fst;
		st.insert(h);
		h={a[i-k],i-k};
		if(h<*p)ac--,sl-=h.fst;
		else sr-=h.fst;
		if(ac<mid){
			sl+=p->fst;
			sr-=p->fst;
			ac++; p++;
		}
		if(ac>mid){
			ac--; p--;
			sl-=p->fst;
			sr+=p->fst;
		}
		st.erase(h);
		cout<<"["<<i<<":"<<distance(st.begin(),p)<<"|"<<ac<<"|"<<mid<<"]"<<endl;
		cout<<calc(p->fst)<<" ";
	}
	cout<<"\n";
	return 0;
}

