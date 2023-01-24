#include<bits/stdc++.h>
#include"oneD_datum.h"
using namespace std;

///////////////////////--------------------實作--------------------///////////////////////////////////
double oneD_datum::percentile(int pt) {
    double index = pt * x.size() * 0.01;
    if (index == x.size()) return x[x.size() -1]; //P100  = an 
    if (index != (int)index) return x[(int)index];  //index = 2.5  --> a3 --> x[2]
    else{ 
        double temp1 = x[(int)index-1] + x[(int)index]; //index = 2 --> (a2+a3)/2 --> (x[1]+x[2]) /2
        return temp1 / 2; 
    }
}//percentile()

void oneD_datum::print(){
    cout << "current data: ";
    for(int i = 0; i < x.size(); i++){
        cout << x[i] << " ";
    }
    cout << "\n";
    cout << "current average: " << average<< "\n";
    cout << "current median: " << percentile(50)<<"\n";
    cout << "current standard deviation: " << standard_deviation << "\n";
    return;
}//print()

void oneD_datum::setup(int n){
    int temp;
    for(int i = 0; i < n; i++){
        cin >> temp;
        x.push_back(temp);
    }
    double temp2 = 0;
    sort(x.begin(), x.end(), less<int>());
    for(auto i:x){
        temp2 += i;
    }
    average = temp2 / x.size();
    double tempsd = 0;
    for(auto i:x){
        tempsd += (i-average)*(i-average);
    }
    standard_deviation = sqrt(tempsd / x.size());
    return;
}//setup()


////////////////////////--------------------執行--------------------//////////////////////////////
int main(){
    //可以用：
    //oneD_datum name(n) 建立並輸入一個型別為oneD_datum,含n位的變數name
    //.setup(n) 加入n個值
    //.ave() 回傳平均值
    //.stdev() 回傳標準差
    //.print() 以修飾過的格式輸出結果
    //.percentile(a) 回傳百分位數Pa
    //.percentile_range(a,b) 回傳百分位距Pa-Pb
    
    int n; 
    cin >> n;                               //sample Input: 5
    oneD_datum A(n);                        //sample Input: 6 5 4 3 1 
                                            //Ouput: current data: 1 3 4 5 6
                                            //       current average: 3.8
                                            //       current median: 4
                                            //       current standard deviation: 1.72047
    A.setup(1);                             //sample Input: 2
    A.print();                              //Ouput: current data: 1 2 3 4 5 6
                                            //       current average: 3.5
                                            //       current median: 3.5
                                            //       current standard deviation: 1.70783
    cout << "Q3 - Q1 = "<< A.percentile_range(75,25)<<"\n";      //= Q3 - Q1 = a5 - a2 = 3 
    cout << "P30 = " << A.percentile(30)<<"\n"; // = P30 = a2 = 2
}