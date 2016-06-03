#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

class Point{
public:
	int x, y;
	Point(){}
	Point(int a, int b){
		x = a;
		y = b;
	}
	friend ostream& operator<<(ostream& os, const Point& pt);
};

ostream& operator<<(ostream& os, const Point& pt){
	os << pt.x << "," << pt.y;
	return os;
}

void swap(Point &a, Point &b){
	Point temp = a;
	a = b;
	b = temp;
}

int dist(Point a, Point b){
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

int orientation(Point a, Point b, Point c){
	int val = (b.y-a.y)*(c.x-b.x) - (b.x-a.x)*(c.y-b.y);
	if (val == 0) return 0; // linear points
	if (val > 0) return 1; // clockwise orientation
	return 2; // counter clockwise orientation
}

Point p0;

int compare(Point a, Point b){
	int o = orientation(p0, a, b);
	if (o == 0){
		if (dist(p0, a) < dist(p0, b)) return 1;
		return 0;
	}
	if (o == 2){
		return 1;
	}
	return 0;
}

float dist2(Point a, Point b){
	return sqrt(dist(a, b));
}


int main(void){
	int t, n, x, y, tx, ty, ymin, mini;
	// cin >> t;
	scanf("%d", &t);
	while(t--){
		// cin >> n;
		scanf("%d", &n);
		// consider the edge case where n == 1 or n == 2 or n == 3
		
		Point points[n];
		ymin = 100001;
		for (int i = 0; i < n; i+=1){
			// cin >> x >> y;
			scanf("%d %d", &x, &y);
			if (y < ymin){
				ymin = y;
				mini = i;
			}else if(y == ymin && x < points[mini].x){
				mini = i;
			}
			points[i] = Point(x, y);
		}
		if (n == 1){
			cout << "0.00" << endl;
			cout << 1 << endl;
		}else if(n == 2 || n == 3){
			if (n == 3 && orientation(points[0], points[1], points[2])==0){
				int i = max_element(points, points+3) - points;
				int j = min_element(points, points+3) - points;
			}
			float distance = 0.0;
			for (int i = 0; i < n-1; i += 1){
				distance+= dist2(points[i], points[i+1]);
			}
			distance += dist2(points[0], points[n-1]);
			cout << distance << endl;
			for (int i = 1; i <= n; i += 1){
				cout << i << " ";
			}
			cout << endl;
		}else{
			swap(points[0], points[mini]);
			p0 = points[0];
			sort(points+1,points+n,compare);
			// cout << "Points in sorted order are: ";
			// for (int i = 0; i < n; i += 1){
			// 	cout << points[i] << " ";
			// }
			// cout << endl;

			stack<int> hull;
			hull.push(0);
			hull.push(1);
			// cout << "Convex hull contains " << points[0] << " " << points[1] << endl;
			// hull.push(points[2]);
			Point prev, cur, next;
			// consider the case where there are only 2 or 3 points;
			prev = points[1];
			cur = points[2];
			next = points[3];
			int i = 4;
			while (i < n+2){
				// cout << "orientation of "<<prev << " " << cur << " " << next << " is " << orientation(prev, cur, next) << endl;
				if (orientation(prev, cur, next)==2){
					// cout << "Pushing " << cur << " into hull." << endl;
					hull.push(i-2);
				}
				prev = cur;
				cur = next;
				if (i < n)
					next = points[i++];
				else{
					next = points[0];
					i += 1;
				}
			}
			// cout << "The stack is ";
			vector<int> ans;
			while(!hull.empty()){
				int p = hull.top();
				hull.pop();
				ans.push_back(p);
				// cout << p << endl;
			}
			float distance = 0.0;
			for (int i = 0; i < ans.size()-1; i += 1){
				distance += dist2(points[ans[i]], points[ans[i+1]]);
			}
			distance += dist2(points[ans[0]],points[ans[ans.size()-1]]);
			// cout << distance << endl;
			printf("%.2f",distance);

			for (int i = 0; i < ans.size(); i += 1){
				cout << ans[i]+1 << " ";
			}
			cout << endl;
		}
	}
}