#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main(void){
    string time;
    cin >> time;
    string flag = time.substr(8, 2);
    string time_str = time.substr(0, 8);
    string nhour;
    if (flag == "PM"){
        string hour = time_str.substr(0,2);
        int ihour = stoi(hour);
        if (ihour != 12){
            ihour += 12;
        }
        nhour = to_string(ihour);
        if (nhour.length() == 1) nhour = "0"+nhour;
    }
    else{
        string hour = time_str.substr(0, 2);
        int ihour = stoi(hour);
        if (ihour == 12){
            nhour = "00";
        }else{
            nhour = to_string(ihour);
            if (nhour.length() == 1) nhour = "0"+nhour;
        }
    }
    string new_string = nhour + time_str.substr(2, 6);
    cout << new_string << endl;
}
