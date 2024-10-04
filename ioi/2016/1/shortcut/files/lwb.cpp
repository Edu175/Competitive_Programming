    #include <bits/stdc++.h>
    #define pb push_back
    #define fst first
    #define snd second
    #define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
    #define SZ(x) ((int)x.size())
    #define ALL(x) x.begin(),x.end()
    #define mset(a,v) memset((a),(v),sizeof(a))
    #define imp(v) {for(auto dkfjhg:v)cout<<dkfjhg<<" ";cout<<"\n";}
    using namespace std;
    typedef long long ll;
    typedef pair<ll,ll> ii;
    const ll INF=1e16;
    ll n,c;
    vector<ll>p,d;
    ll fake=109;
    ii operator^(ii a, ii b){
    	return {max(a.fst,b.fst),min(a.snd,b.snd)};
    }
     
    ll cuenta(ll i, ll b){
    	return d[i]+(b?-1:1)*p[i];
    }
    bool les(ll i, ll j, ll b){
    	if(i==-1)return 1;
    	if(j==-1)return 0;
    	return cuenta(i,b)<cuenta(j,b);
    }
    ii oper(ii a, ll i, ll w){
    	if(les(a.fst,i,w))a.snd=a.fst,a.fst=i;
    	else if(les(a.snd,i,w))a.snd=i;
    	return a;
    }
    vector<ii> mn,mx;
    vector<ll>sums,ids;
    bool can(ll m){
    	vector<ii>ed;
    	auto add=[&](ll i, ll j){
    		if(i>j)swap(i,j);
    		if(i!=-1)ed.pb({i,j});
    	};
    	ll pos=0;
    	for(auto i:ids){
    		while(pos<n&&sums[pos]<=m+p[i]-d[i])pos++;
    		if(pos<n){
    			ll j=mn[pos].fst;
    			if(j==i)j=mn[pos].snd;
    			add(i,j);
    			
    			j=mx[pos].fst;
    			if(j==i)j=mx[pos].snd;
    			add(i,j);
    		}
    	}
    	
    	// if(m==fake){
    	// 	for(auto [i,j]:ed)cout<<i<<","<<j<<" ";;cout<<"\n";
    	// }
    	
    	ii xc={-INF,INF},yc=xc;
    	for(auto [i,j]:ed){
    		ll s=m-c-d[i]-d[j];
    		ii x={p[i]+p[j]-s,p[i]+p[j]+s};
    		ii y={p[i]-p[j]-s,p[i]-p[j]+s};
    		// if(m==fake)cout<<s<<" "<<x.fst<<","<<x.snd<<" "<<y.fst<<","<<y.snd<<" s x y\n";
    		xc=xc^x;
    		yc=yc^y;
    	}
    	// if(m==fake)cout<<xc.fst<<","<<xc.snd<<" "<<yc.fst<<","<<yc.snd<<" xc yc\n";
    	fore(i,0,n){
    		ii pa=ii({xc.fst-p[i],xc.snd-p[i]})^
    			   ii({p[i]-yc.snd,p[i]-yc.fst});
    		// if(m==fake){
    		// 	cout<<pa.fst<<","<<pa.snd<<"\n";
    		// }
    		auto it=lower_bound(ALL(p),pa.fst);
    		if(it!=p.end()&&*it<=pa.snd)return 1;
    	}
    	return 0;
    }
    long long find_shortcut(int N, std::vector <int> L, std::vector <int> D, int C){
    	n=N,c=C;
    	vector<ll>a;
    	for(auto i:L)a.pb(i);
    	for(auto i:D)d.pb(i);
    	
    	p=vector<ll>(n);
    	fore(i,1,n)p[i]=p[i-1]+a[i-1];
    	
    	mn=mx=vector<ii>(n);
    	vector<ll>idx(n);
    	iota(ALL(idx),0);
    	fore(i,0,n)sums.pb(p[i]+d[i]);
    	sort(ALL(idx),[&](ll i, ll j){return sums[i]<sums[j];});
    	sort(ALL(sums));
    	
    	ids=vector<ll>(n);
    	iota(ALL(ids),0);
    	sort(ALL(ids),[&](ll i, ll j){return p[i]-d[i]<p[j]-d[j];});
    	
    	for(ll i=n-1;i>=0;i--){
    		mn[i]=mx[i]={idx[i],-1};
    		if(i<n-1){
    			mn[i]=oper(mn[i+1],idx[i],0);
    			mx[i]=oper(mx[i+1],idx[i],1);
    		}
    	}
    	// for(auto i:mx)cout<<i.fst<<","<<i.snd<<" ";;cout<<"\n";
    	// for(auto i:mn)cout<<i.fst<<","<<i.snd<<" ";;cout<<"\n";
    	ll l=0,r=INF;
    	while(l<=r){
    		ll m=(l+r)/2;
    		if(can(m))r=m-1;
    		else l=m+1;
    	}
    	return l;
    }