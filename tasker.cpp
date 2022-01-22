#include"tasker.h"
//=================================

using std::string;

//template<typename T1, typename T2> void task10_swap(T1 &, T2 &);  //useless declaration
template<typename T> void task10_swap(T *a, T *b){
    T temp = *a;
    *a = *b;
    *b = temp;
    return;
}
template<typename T> void task10_swap(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
    return;
}
template<typename T1, typename T2> void task10_swap(T1 &a, T2 &b){
    T1 temp = a;// here is a loss of accuracy
    a = b;
    b = temp;
    return;
}
void tasker::task10(){
    float a=1.1, b=2.9;
    int i1=9, i2=7;
    task10_swap(&i1, &i2);
    std::cout<<i1<<","<<i2<<std::endl;
    task10_swap(i1, i2);
    std::cout<<i1<<","<<i2<<std::endl;
    task10_swap<int, int>(i1, i2);
    std::cout<<i1<<","<<i2<<std::endl;
    task10_swap(a, i2);
    std::cout<<i1<<","<<i2<<std::endl;
}

void tasker::task9(){
    class Complex{
    private:
        double m_real,m_imag;
    public:
        Complex():m_real(0.0),m_imag(0.0){}
        Complex(float real, float imag):m_real(real),m_imag(imag){}
        //==
        double real() const {
            return this->m_real;
        }
        //==
        double imag() const{
            return this->m_imag;
        }
        //==
        Complex operator+(const Complex &c2){
            return Complex(this->m_real+c2.m_real, this->m_imag+c2.m_imag);
        }
        //==
        void show(){
            std::cout<<this->m_real<<" + "<<this->m_imag <<" i"<<std::endl;
        }
    };
    Complex a(5.9, 16);
    Complex b(1.6, 66);
    Complex c=a+b;
    c.show();
    std::cout<<c.real()<<std::endl;

}

void tasker::task8(){
    std::cout<<typeid (0).name()<<"|"<<std::endl;
    std::cout<<typeid (1).name()<<"|"<<std::endl;
    std::cout<<typeid (1.6).name()<<"|"<<std::endl;
    std::cout<<typeid (true).name()<<"|"<<std::endl;
    std::cout<<typeid (false).name()<<"|"<<std::endl;
    std::cout<<typeid ("asd1q").name()<<"|"<<std::endl;
    std::cout<<typeid ("adq1d2a156d1da6").name()<<"|"<<std::endl;
    std::cout<<typeid ('k').name()<<"|"<<std::endl;
    std::cout<<typeid (tasker).name()<<"|"<<std::endl;
    std::cout<<typeid (void).name()<<"|"<<std::endl;
    bool temp = (typeid(3.3)==typeid("123"));
    std::cout<<temp<<std::endl;
}

void tasker::task7(){
    /**/
    class People{
    private:
        const string m_name;
        const int m_age;
    public:
        People(string name, int age):
            m_name(name),m_age(age){
            std::cout<<"People comes!"<<std::endl;
        }
        ~People(){
            std::cout<<"people died!"<<std::endl;
        }
        //==
        string getname(){
            return this->m_name;
        }
        //==
        int getage(){
            return this->m_age;
        }
    };
    class Student: public People{
    private:
        float m_score;
    public:
        Student(string name, int age, float score):People(name, age){
            this->m_score = score;
            std::cout<<"student comes!"<<std::endl;
        }
        ~Student(){
            std::cout<<"student dead!"<<std::endl;
        }
        float getscore(){
            return this->m_score;
        }
        void setscore(float score){
            this->m_score = score;
        }
    };
    //==
    Student stu1("xiaoming", 17, 95.8);
    std::cout<<stu1.getname()<<std::endl;
    std::cout<<stu1.getage()<<std::endl;
    std::cout<<stu1.getscore()<<std::endl;
    stu1.setscore(50.7);
    std::cout<<stu1.getscore()<<std::endl;
}

void tasker::task6(){
    /*
     * reference will not create a copy of return value in memory, but will
     * directly change the value of the veriable who called this funcation.
    */
    class task6_class{
    public:
        static int plus10(int &r){
            r+=10;return r;
        }
    };
    int num1 = 10;
    int num2 = task6_class::plus10(num1);
    std::cout<<num1<<", "<<num2<<std::endl;
}

void tasker::task5(){
    /* ========================
     * test for memory leak
     * ========================*/
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
