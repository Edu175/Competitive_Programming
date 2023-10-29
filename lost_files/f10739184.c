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

ll oper(ll a, ll b, ll c){
	if(c)return max(a,b);
	else return min(a,b);
}
ll NEUT(ll b){
	if(b)return 0;
	else return 1e7;
}
struct STree{
	ll n; vector<ll>t[2];
	STree(ll n):n(n){t[0].resize(2*n+5,NEUT(0)),t[1].resize(2*n+5,NEUT(1));}
	void upd(ll p, ll v){
		ll P=p+n;
		for(p+=n,t[0][p]=v,t[1][p]=v;p>1;p>>=1){
			t[0][p>>1]=oper(t[0][p],t[0][p^1],0);
			t[1][p>>1]=oper(t[1][p],t[1][p^1],1);
		}
		//cout<<"upd: "<<P<<" "<<v<<": "<<t[0][P]<<" "<<t[1][P]<<"\n";
	}
	ll query(ll l, ll r, ll b){
		ll res=NEUT(b);
		//cout<<"\nq "<<b<<": "<<res<<" ";
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper(res,t[b][l++],b);//,cout<<l-1<<","<<t[b][l-1]<<" ";
			if(r&1)res=oper(res,t[b][--r],b);//,cout<<r<<","<<t[b][r]<<" ";
		}
		//cout<<"= "<<res<<"\n";
		return res;
	}
};
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		string s; cin>>s;
		vector<ll>oc(30);
		string w;
		for(auto i:s){
			if(!oc[i-'a'])w.pb(i);
			oc[i-'a']++;
		}
		sort(ALL(w));
		vector<ll>id(30,-1);
		fore(i,0,SZ(w))id[w[i]-'a']=i;
		string res(n,'$');
		ll flag=1;
		STree st(SZ(w));
		fore(i,0,SZ(w))st.upd(i,0);
		fore(i,0,n){
			/*imp(oc);
			fore(i,0,2*SZ(w))cout<<st.t[0][i]<<" ";
			cout<<"\n";
			fore(i,0,2*SZ(w))cout<<st.t[1][i]<<" ";
			cout<<"\n";*/
			for(ll c=30;c>=0;c--){
				if(!oc[c])continue;
				st.upd(id[c],st.t[0][SZ(w)+id[c]]+1);
				//cout<<c<<" "<<id[c]<<": "<<st.query(0,SZ(w),1)<<" "<<st.query(0,SZ(w),0)<<"\n";
				if(st.query(0,SZ(w),1)-st.query(0,SZ(w),0)<=k){
					res[i]='a'+c;
					oc[c]--;
					break;
				}
				else st.upd(id[c],st.t[0][SZ(w)+id[c]]-1);
			}
			if(res[i]=='$')flag=0;
		}
		reverse(ALL(res));
		if(flag)cout<<res<<"\n";
		else cout<<"-1\n";
		//cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
