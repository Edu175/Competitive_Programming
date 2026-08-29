#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) int(x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" ";;cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

vv lis(vv a){
    vv v;
    for(auto x:a){
        ll p=lower_bound(ALL(v),x)-v.begin();
        if(p>=SZ(v))v.pb(x);
        else v[p]=x;
    }
    return v;
}

bool good(vv a, vv b){
    vv c=a; for(auto i:b)c.pb(i);
    ll len1=SZ(lis(c));
    c=b; for(auto i:a)c.pb(i);
    ll len2=SZ(lis(c));
    return len1==len2;
}

int main(){
    JET
    ll t; cin>>t;
    while(t--){
        ll n,m; cin>>n>>m;
        vv a(n),is(m);
        fore(i,0,n){
            cin>>a[i],a[i]--;
            is[a[i]]=1;
        }
        vv h;
        fore(i,0,m)if(!is[i])h.pb(i);
        if(good(a,h)){
            cout<<"Yes\n";
            for(auto i:h)cout<<i+1<<" ";;cout<<"\n";
            continue;
        }
        reverse(ALL(h));
        if(good(a,h)){
            cout<<"Yes\n";
            for(auto i:h)cout<<i+1<<" ";;cout<<"\n";
            continue;
        }
        reverse(ALL(h));

        vv pre(m),suf(m);
        auto got=lis(a);
        for(auto i:got)pre[i]++;
        fore(i,0,m)pre[i]+=(i?pre[i-1]:0);
        reverse(ALL(a)); for(auto &i:a)i=-i;
        got=lis(a);
        reverse(ALL(a)); for(auto &i:a)i=-i;
        for(auto i:got)suf[-i]=1;
        for(ll i=m-1;i>=0;i--)suf[i]+=(i+1<m?suf[i+1]:0);
        ll len=suf[0];
        // cerr<<"len "<<len<<"\n";
        // imp(pre)
        // imp(suf)
        // imp(h)
		
		vv ret;
		ll rev=0;
		auto doRev=[&](vv &a){reverse(ALL(a));for(auto &i:a)i=m-1-i;};
		if(!(suf[h[0]]==len)){
			rev=1;
			doRev(h);
			reverse(ALL(suf));
			reverse(ALL(pre));
			swap(suf,pre);
		}
		
		// cerr<<"caso "<<1+rev<<"\n";
		ll mxs=-m;
		ll ans=-1;
		fore(k,1,SZ(h)){
			ll p=h[SZ(h)-k];
			mxs=max(mxs,1-k+suf[p]);
			ll curp=pre[p]+k;
			ll curs=k+mxs;

			// cerr<<k<<": "<<curp<<" "<<curs<<"\n";

			if(curs<=len+1 && curp==len+1){
				ans=k;
				break;
			}
		}
		if(ans!=-1){
			ll k=ans;
			vv b,c;
			fore(i,SZ(h)-k,SZ(h))b.pb(h[i]);
			fore(i,0,SZ(h)-k)c.pb(h[i]);
			reverse(ALL(c));
			for(auto i:c)b.pb(i);
			ret=b;
		}
		
		if(!SZ(ret))cout<<"No\n";
		else {
			if(rev)doRev(ret);
			assert(good(a,ret));
			cout<<"Yes\n";
			for(auto i:ret)cout<<i+1<<" ";;cout<<"\n";
		}
    }
    return 0;
}
