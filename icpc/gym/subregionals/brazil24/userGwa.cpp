#include <bits/stdc++.h>
using namespace std;

#define int long long

#define MAXN 100100
#define MAXID (2*MAXN)
int l[MAXN];
int lft[MAXID];
int rgt[MAXID];
int sz[MAXID];
int tmp[MAXID];
int pert[MAXID];
int pai[MAXID];
int cpai[MAXID];
int bit[MAXID];
int n, rt;
set<int> st;
ostringstream out;

struct SegmentTree {
    vector<int> vals;
    void build() {
        vals=vector<int>(4*rt, 0);
    }
    void lazyPropagation(int nd) {
        if(!vals[nd]) return;
        vals[2*nd]=vals[2*nd+1]=vals[nd];
        vals[nd]=0;
    }
    void update(int nd, int l, int r, int p, int q, int v) {
        if(l<r) lazyPropagation(nd);
        if(l>q||p>r) return;
        if(l>=p&&r<=q) {
            vals[nd]=v;
            if(l<r) lazyPropagation(nd);
            return;
        }
        int mid=(l+r)/2;
        update(2*nd, l, mid, p, q, v);
        update(2*nd+1, mid+1, r, p, q, v);
    }
    void update(int l, int r, int v) {
        update(1, 1, rt, l, r, v);
    }
    int query(int nd, int l, int r, int i) {
        if(l==r) return vals[nd];
        lazyPropagation(nd);
        int mid=(l+r)/2;
        if(i<=mid) return query(2*nd, l, mid, i);
        return query(2*nd+1, mid+1, r, i);
    }
    int query(int i) {
        return query(1, 1, rt, i);
    }
};

SegmentTree seg;

void update(int i, int v) {
    for(;i<=rt;i+=(i&(-i))) bit[i]+=v;
}

int query(int i) {
    int ans=0;
    for(;i>0;i-=(i&(-i))) ans+=bit[i];
    return ans;
}

int query(int l, int r) {
    return query(r)-query(l-1);
}

int queryV(int v) {
    return query(tmp[v], tmp[v]+sz[v]-1);
}

int nxtPai(int v) {
    auto p=st.lower_bound(tmp[v]);
    if(p==st.begin()) return cpai[v];
    --p;
    if(*p<tmp[cpai[v]]) return cpai[v];
    return pert[*p+1];
}

void doUpdate(int v, bool recurs) {
    if(!v) return;
    int np=nxtPai(v);
    pair<int, int> prl={queryV(lft[v]), -seg.query(tmp[lft[v]])};
    pair<int, int> prr={queryV(rgt[v]), -seg.query(tmp[rgt[v]])};
    if(prl>prr) {
        st.erase(tmp[v]);
    } else {
        st.insert(tmp[v]);
    }
    seg.update(tmp[recurs?np:v], tmp[v], -max(prl, prr).second);
    if(recurs) doUpdate(pai[np], true);
}

void solve() {
    n=rt=0;
    st.clear();

    cin >> n;
    rt=2*n-1;
    for(int i=0;i<=n+1;i++) l[i]=0;
    for(int i=0;i<=rt+1;i++) {
        lft[i]=rgt[i]=sz[i]=tmp[i]=pert[i]=pai[i]=cpai[i]=bit[i]=0;
    }
    seg.build();
    for(int i=1;i<=n;i++) cin >> l[i];
    for(int i=n+1;i<=rt;i++) {
        cin >> lft[i] >> rgt[i];
    }

    for(int i=1;i<=n;i++) sz[i]=1;
    for(int i=n+1;i<=rt;i++) {
        sz[i]=sz[lft[i]]+sz[rgt[i]]+1;
        if(sz[lft[i]]<sz[rgt[i]]) swap(lft[i], rgt[i]);
    }
    tmp[rt]=1;
    for(int i=rt;i>n;i--) {
        tmp[lft[i]]=tmp[i]+1;
        tmp[rgt[i]]=tmp[i]+1+sz[lft[i]];
    }
    for(int i=1;i<=rt;i++) pert[tmp[i]]=i;
    for(int i=n+1;i<=rt;i++) {
        pai[lft[i]]=pai[rgt[i]]=i;
    }
    for(int i=rt;i>=1;i--) {
        if(!cpai[i]) cpai[i]=i;
        cpai[lft[i]]=cpai[i];
    }

    for(int i=1;i<=n;i++) {
        update(tmp[i], l[i]);
        seg.update(tmp[i], tmp[i], i);
    }
    for(int v=n+1;v<=rt;v++) {
        doUpdate(v, false);
    }

    int q;
    cin >> q;
    out << seg.query(1) << endl;
    while(q--) {
        int v, vl;
        cin >> v >> vl;
        update(tmp[v], vl);
        doUpdate(pai[v], true);
        out << seg.query(1) << endl;
    }
}

int32_t main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t=1;
    while(t--) solve();
    cout << out.str();
    return 0;
}