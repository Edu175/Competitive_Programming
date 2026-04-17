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
ll techo(ll n){
	ll pot=1;
	while(pot<n)pot*=2;
	return pot;
}
struct STree{
	int N,n; vector<ll>t;
	STree(int N):N(N),n(techo(N)),t(2*n+5,NEUT){}
	void upd(int p, ll v){
		for(p+=n,t[p]=v;p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
	}
	int left(int k, int s, int e, int p){
        if(s>p) return -1;
        if(e-1<=p){
            if(t[k]==0) return -1;
            if(s+1==e) return s;
        }
        int m=(s+e)/2;
        int ans=left(2*k+1,m,e,p);
        if(ans<0)ans=left(2*k,s,m,p);
        return ans;
    }
    int right(int k, int s, int e, int p){
        if(e-1<p) return N;
        if(s>=p){
            if(t[k]==0) return N;
            if(s+1==e) return min(s,N);
        }
        int m=(s+e)/2;
        int ans=right(2*k,s,m,p);
        if(ans==N) ans=right(2*k+1,m,e,p);
        return ans;
    }
    int left(int p){return left(1,0,n,p);}
    int right(int p){return right(1,0,n,p);}
};

int main(){FIN;
    int n,m; cin>>n>>m;
    n++;

    vector<ii> v(m);
    fore(i,0,m) cin>>v[i].fst>>v[i].snd;

    vector<int> mxr(n),mnl(n);

    // maximo R
    {
        vector<vector<ii>> ev(n);
        STree st(n);
        for(auto [l,r]:v){
            ev[r].pb({r,1});
            if(l) ev[l-1].pb({r,-1});
        }

        for(int i=n-1;i>=0;i--){
            for(auto [r,flag]:ev[i]) st.upd(r,flag);
            mxr[i]=st.left(n-1);
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