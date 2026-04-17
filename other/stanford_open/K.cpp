#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

#define oper max
#define NEUT 0
struct STree { // segment tree for min over integers
	vector<int> st;int n;
	STree(int n): st(4*n+5,NEUT), n(n) {}
	void upd(int k, int s, int e, int p, int v){
		if(s+1==e){st[k]+=v;return;}
		int m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v);
		else upd(2*k+1,m,e,p,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	int query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return NEUT;
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
    int left(int k, int s, int e, int p){
        if(s>p) return -1;
        if(e-1<=p){
            if(st[k]==0) return -1;
            if(s+1==e) return s;
        }
        int m=(s+e)/2;
        int ans=left(2*k+1,m,e,p);
        if(ans<0)ans=left(2*k,s,m,p);
        return ans;
    }
    int right(int k, int s, int e, int p){
        if(e-1<p) return n;
        if(s>=p){
            if(st[k]==0) return n;
            if(s+1==e) return s;
        }
        int m=(s+e)/2;
        int ans=right(2*k,s,m,p);
        if(ans==n) ans=right(2*k+1,m,e,p);
        return ans;
    }
	void upd(int p, int v){upd(1,0,n,p,v);}
	int query(int a, int b){return query(1,0,n,a,b);}
    int left(int p){return left(1,0,n,p);}
    int right(int p){return right(1,0,n,p);}
};

int main(){FIN;
    int n,m; cin>>n>>m;
    n++;

    vector<ii> v(m);
    fore(i,0,m) cin>>v[i].fst>>v[i].snd,v[i].snd*=-1;
	sort(ALL(v));
	auto _v=v; v.clear();
	ll R=-5;
	for(auto [l,r]:_v){
		r=-r;
		if(r>R)R=r,v.pb({l,r});
	}

    vector<int> mxr(n),mnl(n);

    // maximo R
    {
		vector<int> ur(n,-1);
		for(auto [l,r]:v)ur[l]=max(ur[l],r);
		fore(i,0,n){
			
		}
    }

    // minimo L
    {
        vector<vector<ii>> ev(n);
        STree st(n);
        for(auto [l,r]:v){
            ev[l].pb({l,1});
            if(r+1<n) ev[r+1].pb({l,-1});
        }

        fore(i,0,n){
            for(auto [l,flag]:ev[i]) st.upd(l,flag);
            mnl[i]=st.right(0);
            if(mnl[i]==n)mnl[i]=i;
        }

    }

    int db=0;
    
    vector<vector<int>> op(n);
    fore(i,0,n) if(mnl[i]<=i) op[mnl[i]].pb(i);
    fore(i,0,n) reverse(ALL(op[i]));
    
    ll sumdead=0, amdead=0;
    
    ll ans=0, inq=0;

    vector<pair<ll,ll>> q;

    for(int pos=n-1;pos>=0;pos--){

        // agrego intervalo muerto
        if(mnl[pos]<=pos){
            sumdead+=pos;
            amdead++;
        }

        ll len=max(0, mxr[pos]-pos), cnt=0;
        while(SZ(q) && q.back().fst<=len){
            auto cur=q.back();
            q.pop_back();
            if(db) cout<<"resto "<<cur.fst*cur.snd<<"!!\n";
            inq-=cur.fst*cur.snd;
            cnt+=cur.snd;
        }
        inq+=len*cnt;
        q.pb({len,cnt});
        if(db) cout<<"meto "<<len<<" cantidad "<<cnt<<"\n";

        if(db) cout<<"pendejo "<<pos<<endl;

        // el iesimo pasa a ser vivo
        for(auto i:op[pos]){
            sumdead-=i;
            amdead--;

            ll len=i-pos, cnt=1;
            while(SZ(q) && q.back().fst<=len){
                auto cur=q.back();
                q.pop_back();
                if(db) cout<<"resto "<<cur.fst*cur.snd<<"!!\n";
                inq-=cur.fst*cur.snd;
                cnt+=cur.snd;
            }

            if(db) cout<<"meto "<<len<<" cantidad "<<cnt<<"\n";

            inq+=len*cnt;
            q.pb({len,cnt});
        }

        if(db)cout<<"ne la cola "<<inq<<"!!\n";
        
        ans+=inq;

        // los muertos fijan el pos como comienzo
        ans+=sumdead-amdead*pos;

        if(db) cout<<"hasta "<<pos<<" respuesta "<<ans<<endl<<endl;
    }

    long double r=(long double)(ans)/(1ll*n*(n-1)/2);

    // cout<<ans<<"\n";
    cout<<fixed<<setprecision(10)<<r<<"\n";
}