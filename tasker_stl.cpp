#include"tasker.h"
//=================================
#include<vector>
#include<array>
#include<map>

using std::cin;
using std::cout;
using std::endl;

void tasker_STL::task5(){
    std::map<std::string, std::string> mymap;
    mymap["model_name"] = "ResNet101";
    mymap["lr"] = "\\test\\ss";

    for(auto item:mymap){
        cout<<item.first<<" = "<<item.second<<endl;
    }
    cout<<mymap["lr"]<<endl;
}

void tasker_STL::task4(){
    class testdemo{
    private:
        int num;
    public:
        testdemo(int num):num(num){
            cout<<"constructor function is called!"<<endl;
        }
        testdemo(const testdemo &other):num(other.num){
            cout<<"copy constructor function is called!"<<endl;
        }
        /*testdemo(testdemo &&other):num(other.num){        //if commit
            cout<<"move constructor function is called!"<<endl;
        }*/
    };
    std::vector<testdemo> demo1, demo2;
    demo1.emplace_back(2);
    demo2.push_back(2);


}

void tasker_STL::task3(){
    std::vector<double> vec1 {2,3,4,5,6,99};
    std::vector<double> vec2(8, 0.6);
    std::vector<double> vec3(vec2);
    std::vector<double> vec4(std::begin(vec1)+2, std::begin(vec1)+6);
    std::vector<std::vector<double>> vec5(4, vec1);
    for(auto value:vec1){cout<<value<<" ";}cout<<endl;
    for(auto value:vec2){cout<<value<<" ";}cout<<endl;
    for(auto value:vec3){cout<<value<<" ";}cout<<endl;
    for(auto value:vec4){cout<<value<<" ";}cout<<endl;
    for(auto row=vec5.begin();row<vec5.end();row++){
        for(auto column=row->begin();column<row->end();column++){
            cout<<*column<<" ";
        }
        cout<<endl;
    }
    for(auto &row:vec5){
        for(auto &column:row)
            cout<<column<<" ";
        cout<<endl;
    }
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
