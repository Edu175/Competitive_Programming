#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b;i<oia;i++)
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto messi:v)cout<<messi<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

struct pt{
	ll x,y;
	pt(ll x, ll y):x(x),y(y){}
	pt(){}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	bool operator==(pt p){return (x==p.x&&y==p.y);}
	ll operator%(pt p){return x*p.y-y*p.x;}
	bool left(pt p, pt q){// está izquierda o sobre p-->q?
		return (q-p)%(*this-p)>=0;
	}
};
bool operator<(pt a, pt b){
		pair<ll,ll>c,d;
		c={a.x,a.y},d={b.x,b.y};
		return c<d;
	}
ii pen(pair<pt,pt>a){
	ii ret={a.fst.y-a.snd.y,a.fst.x-a.snd.x};
	ll g=__gcd(ret.fst,ret.snd);
	ret.fst/=g; ret.snd/=g;
	if(ret.snd<0)ret.snd*=-1,ret.fst*=-1;
	if(ret.snd==0)ret.fst=abs(ret.fst);
	return ret;
}
ii per(ii m){
	ii ret={-m.snd,m.fst};
	if(!m.fst)ret={m.snd,m.fst};
	if(ret.snd<0)ret.snd*=-1,ret.fst*=-1;
	return ret;
}
ll dis(pt p, pt q){
	return (p.x-q.x)*(p.x-q.x)+(p.y-q.y)*(p.y-q.y);
}
ll isa=1;
ii qan(vector<pt>&a,pair<pt,pt>b){
	ll l=0,r=SZ(a)-1,c=1;
	ll s=a[l].left(b.fst,b.snd),e=a[r].left(b.fst,b.snd);
	if(s&&e){
		if(dis(b.fst,a[l])<dis(b.fst,a[r]))return {SZ(a),l};
		else return {SZ(a),r};
	}
	else if(!s&&!e)return {0,0};
	else if(s)c=0;
	while(l<=r){
		ll m=(l+r)/2;
		if(a[m].left(b.fst,b.snd)){
			if(!c)l=m+1;
			else r=m-1;
		}
		else {
			if(!c)r=m-1;
			else l=m+1;
		}
	}
	/*if(!isa){
		cout<<c<<": ";
		for(auto i:a)cout<<i.left(b.fst,b.snd)<<" ";
		cout<<"\n";
	}*/
	if(!c)return {l,r};
	else return {SZ(a)-l,l};
}
ll cnt(vector<pt>&a, vector<pt>&b, vector<pt>&c, ll f){ // SZ(vi)>=2
	pair<pt,pt> dc={c[0],c[1]};
	if(c[0].left(a[0],a[1])){
		if(c[SZ(c)-1].left(a[0],a[1])){
			if(dis(a[0],c[0])>dis(a[0],c[SZ(c)-1]))swap(dc.fst,dc.snd);
		}
		else swap(dc.fst,dc.snd);
	}
	else{
		if(!c[SZ(c)-1].left(a[0],a[1])){
			if(dis(a[0],c[0])<dis(a[0],c[SZ(c)-1]))swap(dc.fst,dc.snd);
		}
	}
	ii qa=qan(a,dc),qb=qan(b,dc),qc=qan(c,{a[0],a[1]});
	if(c[qc.snd]==a[qa.snd])qc.fst--;
	if(!isa)qa.fst=0,qc.fst=SZ(c),qb=max(qb,qan(b,{dc.snd,dc.fst}));
	if(f&&*lower_bound(ALL(c),b[qb.snd])==b[qb.snd])qc.fst--;
	/*if(!isa){
		for(auto edu:b)cout<<edu.x<<","<<edu.y<<" ";
		cout<<"\n";
		for(auto edu:c)cout<<edu.x<<","<<edu.y<<" ";
		cout<<"\n";
		pt it=*lower_bound(ALL(c),b[qb.snd]);
		cout<<it.x<<","<<it.y<<" "<<qb.snd<<": "<<b[qb.snd].x<<","<<b[qb.snd].y<<"\n";
		cout<<"a:"<<qa.fst<<" b:"<<qb.fst<<","<<qb.snd<<" c:"<<qc.fst<<","<<qb.snd<<"\n"<<qa.fst+f*qb.fst+qc.fst<<"\n\n";
	}*/
	//cout<<d<<" a:"<<qa.fst<<" b:"<<qb.fst<<" c:"<<qc.fst<<" ";
	return qa.fst+f*qb.fst+qc.fst;
}
int buscandof(int N, vector<int> x, vector<int> y)
{
    ll n=N; vector<pt>v(n);
    fore(i,0,n)v[i].x=x[i],v[i].y=y[i];
    map<ii,vector<pair<pt,pt>>>mp;
    fore(i,0,n){
    	fore(j,i+1,n){
    		mp[pen({v[i],v[j]})].pb({v[i],v[j]});
    	}
    }
    map<ii,vector<set<pt>>>rec;
    for(auto &i:mp){
    	for(auto &s:i.snd){ // s=pair<pt,pt>
			ll flag=1;
			for(auto &j:rec[i.fst]){
				pt p=*j.begin();
				if(s.fst==p||pen({s.fst,p})==i.fst){
					j.insert(s.fst);
					j.insert(s.snd);
					flag=0;
					break;
				}
			}
			if(flag)rec[i.fst].pb({s.fst,s.snd});
    	}
    }
    map<ii,vector<vector<pt>>>seg;
    for(auto &i:rec){
    	seg[i.fst].resize(SZ(i.snd));
    	fore(j,0,SZ(i.snd)){
    		for(auto &h:i.snd[j])seg[i.fst][j].pb(h);
    	}
    }
   /* for(auto &i:seg){
    	cout<<i.fst.fst<<"/"<<i.fst.snd<<":\n";
    	fore(j,0,SZ(i.snd)){ //i.snd[j] = segmento
    		for(auto &h:i.snd[j]){
    			cout<<h.x<<","<<h.y<<" ";
    		}
    		cout<<"\n";
    	}
    }
    cout<<"\ncuentas\n";*/
    ll res=0;
    for(auto &m:seg){
    	//cout<<m.fst.fst<<"/"<<m.fst.snd<<":\n";
    	fore(i,0,SZ(m.snd)){// <= 125 // A
    		vector<pt>a=m.snd[i];
    		fore(j,0,SZ(m.snd)){ // B
    			vector<pt>b=m.snd[j];
    			if(!b[0].left(a[0],a[1]))reverse(ALL(a));
    			if(a[0].left(b[0],b[1]))reverse(ALL(b));
    			if(i==j&&a[0]==b[0])reverse(ALL(b));
    			res=max(res,(ll)SZ(a)+SZ(b)*(i!=j));
    			/*cout<<"a: "; for(auto edu:a)cout<<edu.x<<","<<edu.y<<" ";
    			cout<<"\n";
    			cout<<"b: "; for(auto edu:b)cout<<edu.x<<","<<edu.y<<" "; 
    			cout<<"\n";
    			cout<<per(m.fst).fst<<"/"<<per(m.fst).snd<<": ("<<SZ(seg[per(m.fst)])<<")\n";*/
    			fore(h,0,SZ(seg[per(m.fst)])){
    				vector<pt>&c=seg[per(m.fst)][h];
    				isa=0;res=max(res,cnt(a,b,c,1));isa=1;
    				//cout<<"c: "; for(auto edu:c)cout<<edu.x<<","<<edu.y<<" "; 
    				//cout<<"\n";
    				ll resi=0;
    				if(i==j)resi=max(cnt(a,a,c,0),cnt(b,b,c,0));
    				else resi=cnt(a,b,c,1);
    				//cout<<"= "<<resi<<"\n\n";
    				res=max(res,resi);
    			}
    		}
    	}
    }
    return res;
}
