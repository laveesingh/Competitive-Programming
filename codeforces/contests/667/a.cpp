#include <iostream>
#include <cmath>

using namespace std;

int main(void){
	int d, h, v, e;
	double pi = M_PI;
	cin >> d >> h >> v >> e;
	// cout << pi << endl;
	double r = d/2.0;
	double init_vol = pi * r * r * h;
	// cout << "initial volume is : " << init_vol << endl;
	double inc_vol = pi*r*r*e;
	double dec_vol = v;
	//cout << "inc_vol: " << inc_vol << "dec_vol: " << dec_vol << endl;
	if (inc_vol > dec_vol){
		cout << "NO" << endl;
	}else{
		// int flat = 0;
		int dtime = 0;
		for (int i = 1; i < 10001; i += 1){
			init_vol -= dec_vol;
			init_vol += inc_vol;
			if (init_vol <= 0){
				dtime = i;
				// cout << "dtime set to : " << dtime << endl;
				break;
			}
		}
		if (dtime == 0){
			cout << "NO" << endl;
		}else{
			init_vol += dec_vol;
			init_vol -= inc_vol;
			// cout << "volume remaining after integer seconds: " << init_vol << endl;
			dec_vol /= 1000000;
			inc_vol /= 1000000;
			double i = dtime-1;
			double etime;
			while (i <= dtime){
				init_vol -= dec_vol;
				init_vol += inc_vol;
				if (init_vol <= 0){
					etime = i;
					// cout << "etime set to : " << etime << endl;
					break;
				}
				i += 0.000001;
			}
			cout << "YES" << endl;
			cout << etime << endl;
		}
	}

}