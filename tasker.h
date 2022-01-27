#ifndef TASKER_H
#define TASKER_H

#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <typeinfo>
#include <fstream>
#include <memory>



class tasker_eigen{
public:
    void task1();
    void task2();
    void task3();
    void task4();
    void task5();
    void task6();
    void task7();
    void task8();
    void task9();
    void task10();
    void task11();
};

class tasker_libtorch{
public:
    void task1();
    void task2();
    void task3();
    void task4();
    void task5();
    void task6();
    void task7();
    void task8();
    void task9();
    void task10();
    void task11();
};


#include<opencv2/opencv.hpp>
using cv::Mat;
class tasker_OpenCV{
    public:
        tasker_OpenCV(){
            std::cout<<"tasker on opencv"<<std::endl;
        }
        void colorSpace_Demo(Mat &image);
        void mat_creation_demo();
        void pixel_visit_demo(Mat &image);
        void operators_demo(Mat &image);
        void tracking_bar_demo(Mat &image);
        void key_demo(Mat &image);
        void color_style_demo(Mat &image);
        void bitwise_demo();
        void channels_demo(Mat &image);
        void inrange_demo(Mat &image);
        void pixel_statistic_demo(Mat &image);
        void drawing_demo(Mat &image);
        void random_drawing();
        void polyline_drawing_demo();
        void mouse_drawing_demo(Mat &image);
        void norm_demo(Mat &image);
        void resize_demo(Mat &image);
        void flip_demo(Mat &image);
        void rotate_demo(Mat &image);
        void video_demo();
        void histogram_demo(Mat &image);
        void histogram_2d_demo(Mat &image);
        void histogram_eq_demo(Mat &image);
        void blur_demo(Mat &image);
        void gaussian_blur_demo(Mat &image);
        void bifilter_demo(Mat &image);
        void face_detection_demo();
};

class tasker_STL{
public:
    void task1();
    void task2();
    void task3();
    void task4();
    void task5();
    void task6();
    void task7();
    void task8();
    void task9();
    void task10();
    void task11();
};



class tasker_cpp{
public:
    void task1();
    void task2(int a, float b, char c);
    void task3();
    void task4();
    void task5();
    void task6();
    void task7();
    void task8();
    void task9();
    void task10();
    void task11();
};




#endif // TASKER_H
