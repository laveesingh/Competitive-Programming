#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
#define ll long long int
#define _ ios_base::sync_with_stdio(0);	cin.tie(0);	cout.tie(0);

class Point
{	public:
		ll x, y;
		bool operator < (Point b)
		{	if(y != b.y)
				return y < b.y;
			return x < b.x;
		}
		
};

Point pivot;		//Least y-coordinate

ll cross_product(Point a, Point b, Point c)
{	ll area =(b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x);
	if(area > 0)
		return -1;
	else if(area < 0)
		return 1;
	else
		return 0;
}

ll sqrdist(Point a, Point b)
{	ll dx =a.x - b.x;
	ll dy =a.y - b.y;
	return dx*dx + dy*dy;
}

bool Polar_order(Point a, Point b)
{	ll order =cross_product(pivot, a, b);
	if(order == 0)
		return sqrdist(pivot, a) < sqrdist(pivot, b);
	return (order == -1);
} 



vector<Point> grahamscan(vector<Point> points, ll N){	
	vector<Point> hull;

	if(N < 3)
		return hull;
	
	ll leastY =0;
	for(ll i =1;i<N;++i){	if(points[i] < points[leastY])
			leastY =i;
	}

	swap(points[0], points[leastY]);
	pivot =points[0];
	
	sort(points.begin() + 1, points.begin()+N, Polar_order);

	hull.push_back(points[0]);
	hull.push_back(points[1]);
	hull.push_back(points[2]);

	for(ll i =3;i<N;++i){	
		Point top =hull[hull.size()-1];
		hull.pop_back();
		while(cross_product(hull[hull.size()-1], top, points[i]) != -1){	
			top =hull[hull.size()-1];
			hull.pop_back();
		}
		hull.push_back(top);
		hull.push_back(points[i]);
	}
	return hull;
}

void area(vector<Point> hull, ll N){	
	// Point P[N+2];
	ll i =0;

	// P[N] = P[0];
	// P[N+1] = P[1];
	if (hull.size() < 3){
		// cout << 0.0 << endl;
		printf("0.0\n");
	}else{

		hull.push_back(hull[0]);
		hull.push_back(hull[1]);
		// cout << "size of hull is: " << hull.size() << endl;
		float area_polygon =0;
		for(i =1;i<=N;++i){	
			area_polygon+= (hull[i].x*(hull[i+1].y - hull[i-1].y));
		}	
		// cout << fixed << setprecision(1) << abs(area_polygon/2) << endl;
		printf("%.1f\n", abs(area_polygon/2));
	}
}

vector<Point> points;
void added(ll x, ll y){	
	Point newP;
	newP.x =x;
	newP.y =y;
	points.push_back(newP);
	// cout << "Finding convex hull;" << endl;
	vector<Point> hull =grahamscan(points, points.size());
	// cout << "Finding area " << endl;
	area(hull, hull.size());
}
void erased(ll x, ll y){	
	Point newP;
	ll i;
	for(i =0;i<points.size();++i)
	{	newP =points[i];
		if(newP.x == x && newP.y == y)
			break;	
	}
	points.erase(points.begin()+i);
	// cout << "Finding convex hull;" << endl;
	vector<Point> hull = grahamscan(points, points.size());
	// cout << "Finding area" << endl;
	area(hull, hull.size());
}

int main(void){	

	ll t;
	// cin>>t;
	scanf("%lld", &t);
	while(t--)
	{	ll n;
		// cin>>n;
		scanf("%lld", &n);
		while(n--)
		{	
			char ch;
			ll x, y;
			// cin>>ch>>x>>y;
			// ch = getche();
			// scanf("%c", &ch);
			// fflush(stdin);
			cin >> ch;
			scanf("%lld %lld", &x, &y);
			if(ch == '+'){
				// cout << "Entering added" << endl;
				added(x, y);
			}
			else{
				// cout << "Entering erased " << endl;
				erased(x, y);
			}
		}
	}
}