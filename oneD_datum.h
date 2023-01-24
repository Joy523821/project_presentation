#include<bits/stdc++.h>
using namespace std;

////////////////------------------------宣告-----------------//////////////

class oneD_datum{//一維數據處裡
    protected:
        vector<int> x;
        double average; //算術平均
        double standard_deviation; //標準差

    public:
        double stdev(){ //standard_deviation.getter
            return standard_deviation;
        }//stdev()

        double ave(){ //average.getter
            return average;
        }//ave()

        double percentile(int pt); //百分位數(中位數) //實作在.cpp

        double percentile_range(int pt1,int pt2){ //百分、四分位距
            if(pt1 > pt2) swap(pt1,pt2);
            return percentile(pt2) - percentile(pt1);
        }//percentile_range()

        void print();//print() //實作在.cpp
        
        void setup(int n);//setup() //實作在.cpp
        
        oneD_datum(int n){//constructor
            setup(n);
            print();
        }//constructor

        

}; //oneD_datum