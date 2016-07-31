#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

#define ll long long
#define pb push_back

class Point{
public:
	ll x, y;

	Point(){}
	Point(ll xi, ll yi){
		x = xi;
		y = yi;
	}
	bool operator<(Point b){
		if(y != b.y){
			return y < b.y;
		}
		return x < b.x;
	}
	friend bool operator<(const Point& a, const Point& b);
};

bool operator<(const Point& a, const Point& b){
	if (a.y != b.y){
		return a.y < b.y;
	}
	return a.x < b.x;
}

Point pivot;

ll orientation(Point a, Point b, Point c){
	ll val = (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x);
	if(val > 0){
		return -1;
	}else if(val < 0){
		return 1;
	}else{
		return 0;
	}
}

ll sqrdist(Point a, Point b){
	ll dx = a.x-b.x;
	ll dy = a.y-b.y;
	return dx*dx + dy*dy;
}

bool Polar_order(Point a, Point b){
	ll order = orientation(pivot, a, b);
	if(order == 0)
		return sqrdist(pivot, a) < sqrdist(pivot, b);
	return order==-1;
}

vector<Point> grahamscan(set<Point> pointset, ll N){
	vector<Point> hull, points(pointset.begin(), pointset.end());
	if(N < 3) return hull;
	ll leastY =0;
	for(ll i =1;i<N;++i){	
		if(points[i] < points[leastY])
			leastY =i;
	}
	swap(points[0], points[leastY]);
	pivot = points[0];
	sort(points.begin()+1, points.end(), Polar_order);
	hull.pb(points[0]);
	hull.pb(points[1]);
	hull.pb(points[2]);
	for (ll i = 3; i < N; i += 1){
		Point top = hull.back();
		hull.pop_back();
		while(orientation(hull.back(), top, points[i]) != -1){
			top = hull.back();
			hull.pop_back();
		}
		hull.pb(top);
		hull.pb(points[i]);
	}
	return hull;
}
float last_area;
void area(vector<Point> hull, ll N){
	if(hull.size() < 3){
		printf("0.0\n");
	}else{
		hull.pb(hull[0]);
		hull.pb(hull[1]);
		float area = 0;
		for (int i = 1; i <= N; i += 1){
			area += hull[i].x*(hull[i+1].y - hull[i-1].y);
		}
		last_area = abs(area/2);
		printf("%0.1f\n", abs(area/2));
	}
}

multiset<Point> pointsmultiset;

void add(ll x, ll y){
	Point newP = Point(x, y);
	pointsmultiset.insert(newP);
	set<Point> pointset(pointsmultiset.begin(), pointsmultiset.end());
	vector<Point> hull  = grahamscan(pointset, pointset.size());
	area(hull, hull.size());
}

void erase(ll x, ll y){
	multiset<Point>::iterator it, it2;
	it = pointsmultiset.find(Point(x, y));
	it2 = it;
	it2++;
	pointsmultiset.erase(it, it2);
	if(pointsmultiset.find(Point(x,y)) != pointsmultiset.end()){
		printf("%0.1f\n", last_area);
	}else{
		set<Point> pointset(pointsmultiset.begin(), pointsmultiset.end());
		vector<Point> hull  = grahamscan(pointset, pointset.size());
		area(hull, hull.size());
	}
}

int main(void){
	ll t, n, x, y;
	char ch;
	char temp[20];
	scanf("%lld", &t);
	while(t--){
		ll n;
		scanf("%lld", &n);
		while(n--){
			cin >> ch >> x >> y;

			if(ch == '+'){
				add(x, y);
			}else{
				erase(x,y);
			}
		}
	}
}