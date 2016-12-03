
#define ll long long
#define LO(s) (s&(-s)) 
class BIT{
	ll *ft, size;
public:
	BIT(ll n){
		size = n;
		ft = new ll[n+1];
	}
	~BIT(){
		delete[] ft;
	}
	ll sum(ll a){
		ll ret = 0;
		for(;a;a -= LO(a)) ret += ft[a];
		return ret;
	}
	ll sum(ll a, ll b){
		return sum(b) - (a==1?0:sum(a-1));
	}
	void point_update(ll k, ll v){
		cerr << "Updating " << k << endl;
		for(; k <= size; k += LO(k)) ft[k] += v;
		cerr << "Updated " << endl;
	}
	void build(ll a[]){
		for(ll i = 1; i <= size; i += 1)
			point_update(i, a[i-1]);
	}
};	
