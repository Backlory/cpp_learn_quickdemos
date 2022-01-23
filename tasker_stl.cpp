#include"tasker.h"
//=================================
#include<vector>
#include<array>

using std::cin;
using std::cout;
using std::endl;

void tasker_STL::task3(){
    ;
}

void tasker_STL::task2(){
    std::array<double, 10> values {0.5, 1.0, 5.3, 342.3,};
    for(int i=0; i<values.size();i++){
        values.at(i) += 5;
    }
    cout<<std::get<3>(values)<<endl;
    cout<<"==============="<<endl;
    if (!values.empty()){
        for(auto val=values.begin(); val<values.end(); val++){
            cout<<*val<<endl;
            cout<<val<<endl;
        }
    }
}

void tasker_STL::task1(){
    std::vector<int> v{1,2,3,4,56,7,8,9};
    std::vector<int>::iterator i;
    //==
    cout<<"=======Method 1: using index to access vector elements========"<<endl;
    for(int i=0; i<static_cast<int>(v.size());i++){
        cout<<"v["<<i<<"]="<<v[i]<<endl;
    }
    cout<<"=======Method 2: checking if two iterators are equal to access ========"<<endl;
    for(i=v.begin();i!=v.end(); i++){
        cout<< *i <<"-"<<endl;
    }
    cout<<"=======Method 3: comparing two iterators to access ========"<<endl;
    for(i=v.begin();i<v.end(); i++){
        cout<< *i <<"-"<<endl;
    }
    cout<<"=======Method 4: using operator '+' to access  ========"<<endl;
    for(i=v.begin();i<v.end();){
        cout<< *i <<"-"<<endl;
        i+=2;
    }
}
