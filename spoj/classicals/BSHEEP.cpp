#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <map>

using namespace std;



class Point{
public:
	int x, y;
	Point(){}
	Point(int a, int b){
		x = a;
		y = b;
	}
	// bool operator<(Point a){
	// 	if(y == a.y){
	// 		return x < a.x;
	// 	}
	// 	return y < a.y;
	// }
	friend bool operator<(const Point& a, const Point& b);
	friend ostream& operator<<(ostream& os, const Point& pt);
}p0;

// bool operator<(const Point& a, const Point& b){
// 	if(a.y == b.y)
// 		return a.x < b.x;
// 	return a.y < b.y;
// }

ostream& operator<<(ostream& os, const Point& pt){
	os << pt.x << "," << pt.y;
	return os;
}

int orientation(Point a, Point b, Point c){
	int val = (b.y-a.y)*(c.x-b.x) - (b.x-a.x)*(c.y-b.y);
	if (val == 0) return 0; // linear points
	if (val > 0) return 1; // clockwise orientation
	return 2; // counter clockwise orientation
}


int dist(Point a, Point b){
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

bool operator<(const Point& a, const Point& b){
	int o = orientation(p0, a, b);
	if (o == 0){
		if (dist(p0, a) < dist(p0, b)) {
			cout << a << " is not dist less than " << b << endl;
			return false;
		}
		cout << a << " is dist less than " << b << endl;
		return true;
	}
	if (o == 2){
		cout << a << " is ori less than " << b << endl;
		return true;
	}
	cout << a << " is not ori less than " << b << endl;
	return false;
}


void swap(Point &a, Point &b){
	Point temp = a;
	a = b;
	b = temp;
}






float dist2(Point a, Point b){
	return sqrt(dist(a, b));
}


// int main(void){
// 	int t, n, x, y, tx, ty, ymin, mini;
// 	// cin >> t;
// 	scanf("%d", &t);
// 	while(t--){
// 		// cin >> n;
// 		scanf("%d", &n);
// 		// consider the edge case where n == 1 or n == 2 or n == 3
		
// 		Point points[n];
// 		ymin = 100001;
// 		for (int i = 0; i < n; i+=1){
// 			// cin >> x >> y;
// 			scanf("%d %d", &x, &y);
// 			if (y < ymin){
// 				ymin = y;
// 				mini = i;
// 			}else if(y == ymin && x < points[mini].x){
// 				mini = i;
// 			}
// 			points[i] = Point(x, y);
// 		}
// 		if (n == 1){
// 			cout << "0.00" << endl;
// 			cout << 1 << endl;
// 		}else if(n == 2 || n == 3){
// 			if (n == 3 && orientation(points[0], points[1], points[2])==0){
// 				sort(points, points+3);
				
// 			}
// 			float distance = 0.0;
// 			for (int i = 0; i < n-1; i += 1){
// 				distance+= dist2(points[i], points[i+1]);
// 			}
// 			distance += dist2(points[0], points[n-1]);
// 			cout << distance << endl;
// 			for (int i = 1; i <= n; i += 1){
// 				cout << i << " ";
// 			}
// 			cout << endl;
// 		}else{
// 			swap(points[0], points[mini]);
// 			p0 = points[0];
// 			sort(points+1,points+n,compare);
// 			// cout << "Points in sorted order are: ";
// 			// for (int i = 0; i < n; i += 1){
// 			// 	cout << points[i] << " ";
// 			// }
// 			// cout << endl;

// 			stack<int> hull;
// 			hull.push(0);
// 			hull.push(1);
// 			// cout << "Convex hull contains " << points[0] << " " << points[1] << endl;
// 			// hull.push(points[2]);
// 			Point prev, cur, next;
// 			// consider the case where there are only 2 or 3 points;
// 			prev = points[1];
// 			cur = points[2];
// 			next = points[3];
// 			int i = 4;
// 			while (i < n+2){
// 				// cout << "orientation of "<<prev << " " << cur << " " << next << " is " << orientation(prev, cur, next) << endl;
// 				if (orientation(prev, cur, next)==2){
// 					// cout << "Pushing " << cur << " into hull." << endl;
// 					hull.push(i-2);
// 				}
// 				prev = cur;
// 				cur = next;
// 				if (i < n)
// 					next = points[i++];
// 				else{
// 					next = points[0];
// 					i += 1;
// 				}
// 			}
// 			// cout << "The stack is ";
// 			vector<int> ans;
// 			while(!hull.empty()){
// 				int p = hull.top();
// 				hull.pop();
// 				ans.push_back(p);
// 				// cout << p << endl;
// 			}
// 			float distance = 0.0;
// 			for (int i = 0; i < ans.size()-1; i += 1){
// 				distance += dist2(points[ans[i]], points[ans[i+1]]);
// 			}
// 			distance += dist2(points[ans[0]],points[ans[ans.size()-1]]);
// 			// cout << distance << endl;
// 			printf("%.2f",distance);

// 			for (int i = 0; i < ans.size(); i += 1){
// 				cout << ans[i]+1 << " ";
// 			}
// 			cout << endl;
// 		}
// 	}
// }

int main(void){
	int t, n, x, y, tx, ty;

	scanf("%d", &t);

	while(t--){
		scanf("%d", &n);
		if (n == 1){
			scanf("%d %d", &tx, &ty);
			printf("0.00\n1\n\n");
		}else{
			Point points[n];
			for(int i = 0; i < n; i += 1){
				scanf("%d %d", &tx, &ty);
				points[i] = Point(tx, ty);
			}
			if (n == 2){
				printf("%.2f\n", 2*dist2(points[0], points[1]));
				if (points[0] < points[1]){
					printf("1 2\n\n");
				}else{
					printf("2 1\n\n");
				}
			}else{
				map<Point, int> initial_index; // for initial indexes
				for (int i = 0; i < n; i += 1){
					if(!initial_index[points[i]]){
						initial_index[points[i]] = i+1;
					}
				}
				// swap(*min_element(points, points+n), points[0]);
				int mini = 0, miny = points[0].y;
				for (int i = 0; i < n; i += 1){
					if (points[i].y < miny){
						miny = points[i].y;
						mini = i;
					}else if(points[i].y == miny && points[i].x < points[mini].x){
						mini = i;
					}
				}
				swap(points[0], points[mini]);
				sort(points+1, points+n);
				cout << "Points in sorted order are: " ;
				for(int i = 0; i < n; i += 1){
					cout << points[i] << " ";
				}
				cout << endl;
				vector<Point> unique_points;
				for (int i = 1; i < n;i += 1){
					Point cur = points[i];
					Point prev = points[i-1];
					if (cur.x == prev.x && cur.y == prev.y){
						// do nothing
					}else{
						unique_points.push_back(cur);
					}
				}
				int nn = unique_points.size();
				if (nn == 1){
					printf("0.00\n1\n\n");
				}else if(nn == 2){
					printf("%.2f\n", 2*dist2(unique_points[0], unique_points[1]));
					if (unique_points[0] < unique_points[1]){
						printf("%d %d\n\n", initial_index[unique_points[0]], initial_index[unique_points[1]]);
					}else{
						printf("%d %d\n\n", initial_index[unique_points[1]], initial_index[unique_points[0]]);	
					}
				}else{
					vector<Point> finals;
					unique_points.push_back(points[0]);
					finals.push_back(unique_points[0]);
					finals.push_back(unique_points[1]);
					for (int i = 2; i < unique_points.size()-1; i += 1){
						if (orientation(unique_points[i-1], unique_points[i], unique_points[i+1]) == 2){
							finals.push_back(unique_points[i]);
						}
					}
					float distance = 0.0;
					for (int i = 0; i < finals.size()-1; i += 1){
						distance += dist2(finals[i], finals[i+1]);
					}
					distance += dist2(finals[0], finals[finals.size()-1]);
					printf("%0.2f\n", distance);
					printf("%d", initial_index[finals[0]]);
					for (int i = 1; i < finals.size(); i += 1){
						printf(" %d", initial_index[finals[i]]);
					}
					printf("\n\n");
				}
			}

		}

	}

}