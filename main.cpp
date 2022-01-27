#include"tasker.h"
#include<thread>

void tasker3_show_src(cv::Mat image){
    std::cout<<"second thread is running, thread id = "<< std::this_thread::get_id()<<std::endl;
    cv::imshow("input image", image);
    //cv::waitKey();
    return;
}

/*====================================================================*/
int main()
{
    std::cout << "Progress starts..." << std::endl;
    std::cout<<"main thread id = "<< std::this_thread::get_id()<<std::endl;
    std::cout<<"========================================"<<std::endl;

    //================================================================
    cv::Mat src = cv::imread("example.jpg"); //BGR
    if(src.empty()){
        std::cout<<"could not open image"<<std::endl; return -1;
    }
    std::thread thread_src(tasker3_show_src, src);
    thread_src.join();
    tasker_OpenCV Tasker3;
    //Tasker3.colorSpace_Demo(src);
    //Tasker3.mat_creation_demo();
    //Tasker3.pixel_visit_demo(src);
    //Tasker3.operators_demo(src);
    //Tasker3.tracking_bar_demo(src);
    //Tasker3.key_demo(src);
    //Tasker3.color_style_demo(src);
    //Tasker3.bitwise_demo();
    //Tasker3.channels_demo(src);
    //Tasker3.inrange_demo(src);
    //Tasker3.pixel_statistic_demo(src);
    //Tasker3.drawing_demo(src);
    //Tasker3.random_drawing();
    //Tasker3.polyline_drawing_demo();
    //Tasker3.mouse_drawing_demo(src);
    //Tasker3.norm_demo(src);
    //Tasker3.resize_demo(src);
    //Tasker3.flip_demo(src);
    //Tasker3.rotate_demo(src);
    Tasker3.video_demo();
    //Tasker3.histogram_demo(src);
    //Tasker3.histogram_2d_demo(src);
    //Tasker3.histogram_eq_demo(src);
    //Tasker3.blur_demo(src);
    //Tasker3.gaussian_blur_demo(src);
    //Tasker3.bifilter_demo(src);
    //Tasker3.face_detection_demo();




    //================================================================
    //tasker_STL Tasker2;
    //Tasker2.task1();
    //Tasker2.task2();
    //Tasker2.task3();
    //Tasker2.task4();
    //Tasker2.task5();
    //Tasker2.task6();


    //================================================================
    //tasker_cpp Tasker1;
    //Tasker1.task1();
    //Tasker1.task2(9,5.6,'a');
    //Tasker1.task3();
    //Tasker1.task4();
    //Tasker1.task5();
    //Tasker1.task6();
    //Tasker1.task7();
    //Tasker1.task8();
    //Tasker1.task9();
    //Tasker1.task10();
    //Tasker1.task11();

    return 0;
}
