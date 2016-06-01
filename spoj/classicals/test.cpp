#include<iostream>
using namespace std;

class Restaurant{ 

private:
double tip, tax,totalCost,mealCost;
int roundCost;
public:

Restaurant (double m)
{
    mealCost = m   ;
}

void tipCalc(double t)
{
    tip=mealCost*(t/100.0);
}

void taxCalc(double t)
{
    tax=mealCost*(t/100.0);
}

void totalCost1()
{
    totalCost=mealCost+tip+tax;
}

int roundCost1()
{
    roundCost=(int)totalCost;
    return roundCost;
} 

};// class ends
int main()
{
    double mealCost, tipPercent, taxPercent, totalCost;
    int roundCost;


    //cout<<"\n Enter mealCost \n";
    cin>>mealCost;
    Restaurant       ob1(mealCost);
    //cout<<"\n Enter mealtipPercent \n";
    cin>>tipPercent;
    //cout<<"\n Enter mealtaxPercent \n";
    cin>>taxPercent;
    ob1.tipCalc(tipPercent);
    ob1.taxCalc(taxPercent);
    ob1.totalCost1();
    cout<<"The total meal cost is "<<ob1.roundCost1()<<" dollars."<<endl;
    return 0;
}     