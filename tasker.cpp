#include"tasker.h"
//=================================

using std::string;

/* ========================
 * test for memory leak
 * ========================*/
void tasker::task5(){
    int *array = new int[10];
    array[9] = 99;
    delete[](array);
}

void tasker::task4(){
    string s1;
    string s2 = "c plus plus";
    string s3 = s2;
    string s4 (5, 's');
    std::cout<<s1<<std::endl;
    std::cout<<s2<<std::endl;
    std::cout<<s3.insert(5,"!adqw@")<<std::endl;
    std::cout<<s3.length()<<std::endl;

    std::cout<<s4<<std::endl;
    std::cout<<s4.c_str()<<std::endl;

    std::cout<<typeid(s1).name()<<std::endl;
    for(int i=0, len=s2.length();i<len;i++){
        s1 += s2[i];
        std::cout<<s1<<std::endl;
    }

}

void tasker::task3(){
    class VLA{
    public:
        VLA(const int lgth):m_len(lgth){
            if (lgth>0){
                m_arr = new int[lgth];
            }
            else {
                m_arr = nullptr;
            }
        }
        //==
        ~VLA(){
            delete[] m_arr;
        }
        //==
        void input(){
            for(int i=0; nullptr!=at(i); i++){
                std::cin>>*at(i);
            }
        }
        //==
        void show(){
            for(int i=0; nullptr!=at(i); i++){
                std::cout<<*at(i)<<", ";
            }
        }
    private:
        const int m_len;
        int *m_arr;
        int *m_p;
        int *at(int i){
            if (!m_arr || i<0 || i>=m_len){
                return nullptr;
            }
            else{
                return m_arr +i;
            }
        }
    };

    int n;
    std::cin>>n;
    VLA *parr = new VLA(n);
    std::cout<<"input number is"<<n<<":"<<std::endl;
    parr->input();
    std::cout<<"OK! your array is"<<std::endl;
    parr->show();
    delete parr;
}

void tasker::task2(int a=5, float b=6.9, char c='q'){
    std::cout<<a<<b<<c<<std::endl;
}

void tasker::task1(){
    class Student{
    public:
        char name[100];
        int age;
        float score;
        Student(char *pname, const int age_=19, float score_=100.0):
            age(age_), score(score_){
            std::strcpy(name, pname);
        }
        void display(){
            std::cout << this->name  <<"'s age is "<< this->age<<
                         ", and he get a score of "<< this->score<<"." << std::endl;
        }
    private:
        void ss(){
            std::cout<<this->name<<" is singing with you."<<std::endl;
        }
    };

    Student xiaoming("xiaoming", 25, 98.1);
    xiaoming.display();
    Student stu2("liuhua", 11, 65.2);
    stu2.display();
}
