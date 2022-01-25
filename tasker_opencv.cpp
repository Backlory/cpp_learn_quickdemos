#include "tasker.h"



void tasker_OpenCV::colorSpace_Demo(Mat &image) {
    Mat gray, hsv;
    cvtColor(image, hsv, cv::COLOR_BGR2HSV);
    // H 0 ~ 180, S, V
    cvtColor(image, gray, cv::COLOR_BGR2GRAY);
    imshow("HSV", hsv);
    imshow("灰度", gray);
    // imwrite("D:/hsv.png", hsv);
    // imwrite("D:/gray.png", gray);
    cv::waitKey();
}

void tasker_OpenCV::mat_creation_demo() {
    // Mat m1, m2;
    // m1 = image.clone();
    // image.copyTo(m2);

    // 创建空白图像
    Mat m3 = Mat::zeros(cv::Size(8, 8), CV_8UC3);
    m3 = cv::Scalar(0, 0, 255);
    std::cout << "width: " << m3.cols << " height: " << m3.rows << " channels: "<<m3.channels()<< std::endl;
    // std::cout << m3 << std::endl;

    Mat m4;
    m3.copyTo(m4);
    m4 = cv::Scalar(0, 255, 255);
    imshow("图像", m3);
    imshow("图像4", m4);
}

void tasker_OpenCV::pixel_visit_demo(Mat &image) {
    int w = image.cols;
    int h = image.rows;
    int dims = image.channels();
    /*
    for (int row = 0; row < h; row++) {
        for (int col = 0; col < w; col++) {
            if (dims == 1) { // 灰度图像
                int pv = image.at<uchar>(row, col);
                image.at<uchar>(row, col) = 255 - pv;
            }
            if (dims == 3) { // 彩色图像
                Vec3b bgr = image.at<Vec3b>(row, col);
                image.at<Vec3b>(row, col)[0] = 255 - bgr[0];
                image.at<Vec3b>(row, col)[1] = 255 - bgr[1];
                image.at<Vec3b>(row, col)[2] = 255 - bgr[2];
            }
        }
    }
    */

    for (int row = 0; row < h; row++) {
        uchar* current_row = image.ptr<uchar>(row);
        for (int col = 0; col < w; col++) {
            if (dims == 1) { // 灰度图像
                int pv = *current_row;
                *current_row++ = 255 - pv;
            }
            if (dims == 3) { // 彩色图像
                *current_row++ = 255 - *current_row;
                *current_row++ = 255 - *current_row;
                *current_row++ = 255 - *current_row;
            }
        }
    }
    imshow("像素读写演示", image);
}

void tasker_OpenCV::operators_demo(Mat &image) {
    Mat dst = Mat::zeros(image.size(), image.type());
    Mat m = Mat::zeros(image.size(), image.type());
    m = cv::Scalar(5, 5, 5);

    // 加法
    /*
    int w = image.cols;
    int h = image.rows;
    int dims = image.channels();
    for (int row = 0; row < h; row++) {
        for (int col = 0; col < w; col++) {
            Vec3b p1 = image.at<Vec3b>(row, col);
            Vec3b p2 = m.at<Vec3b>(row, col);
            dst.at<Vec3b>(row, col)[0] = saturate_cast<uchar>(p1[0] + p2[0]);
            dst.at<Vec3b>(row, col)[1] = saturate_cast<uchar>(p1[1] + p2[1]);
            dst.at<Vec3b>(row, col)[2] = saturate_cast<uchar>(p1[2] + p2[2]);
        }
    }
    */
    divide(image, m, dst);

    imshow("加法操作", dst);
}

static void on_lightness(int b, void* userdata) {
    Mat image = *((Mat*)userdata);
    Mat dst = Mat::zeros(image.size(), image.type());
    Mat m = Mat::zeros(image.size(), image.type());
    addWeighted(image, 1.0, m, 0, b, dst);
    imshow("亮度与对比度调整", dst);
}

static void on_contrast(int b, void* userdata) {
    Mat image = *((Mat*)userdata);
    Mat dst = Mat::zeros(image.size(), image.type());
    Mat m = Mat::zeros(image.size(), image.type());
    double contrast = b / 100.0;
    addWeighted(image, contrast, m, 0.0, 0, dst);
    imshow("亮度与对比度调整", dst);
}

void tasker_OpenCV::tracking_bar_demo(Mat &image) {
    namedWindow("亮度与对比度调整", cv::WINDOW_AUTOSIZE);
    int lightness = 50;
    int max_value = 100;
    int contrast_value = 100;
    cv::createTrackbar("Value Bar:", "亮度与对比度调整", &lightness, max_value, on_lightness, (void*) (&image));
    cv::createTrackbar("Contrast Bar:", "亮度与对比度调整", &contrast_value, 200, on_contrast, (void*)(&image));
    on_lightness(50, &image);
}

void tasker_OpenCV::key_demo(Mat &image) {
    Mat dst = Mat::zeros(image.size(), image.type());
    while (true) {
        int c = cv::waitKey(100);
        if (c == 27) { // 退出
            break;
        }
        if (c == 49) { // Key #1
            std::cout << "you enter key # 1 "<< std::endl;
            cvtColor(image, dst, cv::COLOR_BGR2GRAY);
        }
        if (c == 50) { // Key #2
            std::cout << "you enter key # 2 " << std::endl;
            cvtColor(image, dst, cv::COLOR_BGR2HSV);
        }
        if (c == 51) { // Key #3
            std::cout << "you enter key # 3 " << std::endl;
            dst = cv::Scalar(50, 50, 50);
            add(image, dst, dst);
        }
        imshow("键盘响应", dst);
    }
}

void tasker_OpenCV::color_style_demo(Mat &image) {
    int colormap[] = {
        cv::COLORMAP_AUTUMN,
        cv::COLORMAP_BONE,
        cv::COLORMAP_JET,
        cv::COLORMAP_WINTER,
        cv::COLORMAP_RAINBOW,
        cv::COLORMAP_OCEAN,
        cv::COLORMAP_SUMMER,
        cv::COLORMAP_SPRING,
        cv::COLORMAP_COOL,
        cv::COLORMAP_PINK,
        cv::COLORMAP_HOT,
        cv::COLORMAP_PARULA,
        cv::COLORMAP_MAGMA,
        cv::COLORMAP_INFERNO,
        cv::COLORMAP_PLASMA,
        cv::COLORMAP_VIRIDIS,
        cv::COLORMAP_CIVIDIS,
        cv::COLORMAP_TWILIGHT,
        cv::COLORMAP_TWILIGHT_SHIFTED
    };

    Mat dst;
    int index = 0;
    while (true) {
        int c = cv::waitKey(500);
        if (c == 27) { // 退出
            break;
        }
        applyColorMap(image, dst, colormap[index%19]);
        index++;
        imshow("颜色风格", dst);
    }
}

void tasker_OpenCV::bitwise_demo(Mat &image) {
    Mat m1 = Mat::zeros(cv::Size(256, 256), CV_8UC3);
    Mat m2 = Mat::zeros(cv::Size(256, 256), CV_8UC3);
    rectangle(m1, cv::Rect(100, 100, 80, 80), cv::Scalar(255, 255, 0), -1, cv::LINE_8, 0);
    rectangle(m2, cv::Rect(150, 150, 80, 80), cv::Scalar(0, 255, 255), -1, cv::LINE_8, 0);
    imshow("m1", m1);
    imshow("m2", m2);
    Mat dst;
    bitwise_xor(m1, m2, dst);
    imshow("像素位操作", dst);
}

void tasker_OpenCV::channels_demo(Mat &image) {
    std::vector<Mat> mv;
    split(image, mv);
    imshow("蓝色", mv[0]);
    imshow("绿色", mv[1]);
    imshow("红色", mv[2]);

    Mat dst;
    mv[0] = 0;
    // mv[1] = 0;
    merge(mv, dst);
    imshow("红色", dst);

    int from_to[] = { 0, 2, 1,1, 2, 0 };
    mixChannels(&image, 1, &dst, 1, from_to, 3);
    imshow("通道混合", dst);
}

void tasker_OpenCV::inrange_demo(Mat &image) {
    Mat hsv;
    cvtColor(image, hsv, cv::COLOR_BGR2HSV);
    Mat mask;
    inRange(hsv, cv::Scalar(35, 43, 46), cv::Scalar(77, 255, 255), mask);

    Mat redback = Mat::zeros(image.size(), image.type());
    redback = cv::Scalar(40, 40, 200);
    bitwise_not(mask, mask);
    imshow("mask", mask);
    image.copyTo(redback, mask);
    imshow("roi区域提取", redback);
}

void tasker_OpenCV::pixel_statistic_demo(Mat &image) {
    double minv, maxv;
    cv::Point minLoc, maxLoc;
    std::vector<Mat> mv;
    split(image, mv);
    for (int i = 0; i < mv.size(); i++) {
        minMaxLoc(mv[i], &minv, &maxv, &minLoc, &maxLoc, Mat());
        std::cout <<"No. channels:"<< i << " min value:" << minv << " max value:" << maxv << std::endl;
    }
    Mat mean, stddev;
    Mat redback = Mat::zeros(image.size(), image.type());
    redback = cv::Scalar(40, 40, 200);
    meanStdDev(redback, mean, stddev);
    imshow("redback", redback);
    std::cout << "means:" << mean << std::endl;
    std::cout<< " stddev:" << stddev << std::endl;
}

void tasker_OpenCV::drawing_demo(Mat &image) {
    cv::Rect rect;
    rect.x = 100;
    rect.y = 100;
    rect.width = 250;
    rect.height = 300;
    Mat bg = Mat::zeros(image.size(), image.type());
    rectangle(bg, rect, cv::Scalar(0, 0, 255), -1, 8, 0);
    circle(bg, cv::Point(350, 400), 15, cv::Scalar(255, 0, 0), -1, 8, 0);
    line(bg, cv::Point(100, 100), cv::Point(350, 400), cv::Scalar(0, 255, 0), 4, cv::LINE_AA, 0);
    cv::RotatedRect rrt;
    rrt.center = cv::Point(200, 200);
    rrt.size = cv::Size(100, 200);
    rrt.angle = 90.0;
    ellipse(bg, rrt, cv::Scalar(0, 255, 255), 2, 8);
    Mat dst;
    addWeighted(image, 0.7, bg, 0.3, 0, dst);
    imshow("绘制演示", bg);
}

void tasker_OpenCV::random_drawing() {
    Mat canvas = Mat::zeros(cv::Size(512, 512), CV_8UC3);
    int w = canvas.cols;
    int h = canvas.rows;
    cv::RNG rng(12345);
    while (true) {
        int c = cv::waitKey(10);
        if (c == 27) { // 退出
            break;
        }
        int x1 = rng.uniform(0, w);
        int y1 = rng.uniform(0, h);
        int x2 = rng.uniform(0, w);
        int y2 = rng.uniform(0, h);
        int b = rng.uniform(0, 255);
        int g = rng.uniform(0, 255);
        int r = rng.uniform(0, 255);
        // canvas = cv::Scalar(0, 0, 0);
        line(canvas, cv::Point(x1, y1), cv::Point(x2, y2), cv::Scalar(b, g, r), 1, cv::LINE_AA, 0);
        imshow("随机绘制演示", canvas);
    }
}

void tasker_OpenCV::polyline_drawing_demo() {
    Mat canvas = Mat::zeros(cv::Size(512, 512), CV_8UC3);
    int w = canvas.cols;
    int h = canvas.rows;
    cv::Point p1(100, 100);
    cv::Point p2(300, 150);
    cv::Point p3(300, 350);
    cv::Point p4(250, 450);
    cv::Point p5(50, 450);
    std::vector<cv::Point> pts;
    pts.push_back(p1);
    pts.push_back(p2);
    pts.push_back(p3);
    pts.push_back(p3);
    pts.push_back(p4);
    pts.push_back(p5);
    // polylines(canvas, pts, true, cv::Scalar(0, 255, 0), -1, 8, 0);
    std::vector<std::vector<cv::Point>> contours;
    contours.push_back(pts);
    drawContours(canvas, contours, 0, cv::Scalar(0, 0, 255), -1, 8);
    imshow("绘制多边形", canvas);
}

cv::Point sp(-1, -1);
cv::Point ep(-1, -1);
Mat temp;
static void on_draw(int event, int x, int y, int flags, void *userdata) {
    Mat image = *((Mat*)userdata);
    if (event == cv::EVENT_LBUTTONDOWN) {
        sp.x = x;
        sp.y = y;
        std::cout <<"start cv::Point:" << sp << std::endl;
    }
    else if (event == cv::EVENT_LBUTTONUP) {
        ep.x = x;
        ep.y = y;
        int dx = ep.x - sp.x;
        int dy = ep.y - sp.y;
        if (dx > 0 && dy > 0) {
                cv::Rect box(sp.x, sp.y, dx, dy);
                temp.copyTo(image);
                imshow("ROI区域", image(box));
                rectangle(image, box, cv::Scalar(0, 0, 255), 2, 8, 0);
                imshow("鼠标绘制", image);
                // ready for next drawing
                sp.x = -1;
                sp.y = -1;
        }
    }
    else if (event == cv::EVENT_MOUSEMOVE) {
        if (sp.x > 0 && sp.y > 0) {
            ep.x = x;
            ep.y = y;
            int dx = ep.x - sp.x;
            int dy = ep.y - sp.y;
            if (dx > 0 && dy > 0) {
                cv::Rect box(sp.x, sp.y, dx, dy);
                temp.copyTo(image);
                rectangle(image, box, cv::Scalar(0, 0, 255), 2, 8, 0);
                imshow("鼠标绘制", image);
            }
        }
    }
}

void tasker_OpenCV::mouse_drawing_demo(Mat &image) {
    namedWindow("鼠标绘制", cv::WINDOW_AUTOSIZE);
    cv::setMouseCallback("鼠标绘制", on_draw, (void*)(&image));
    imshow("鼠标绘制", image);
    temp = image.clone();
}

void tasker_OpenCV::norm_demo(Mat &image) {
    Mat dst;
    std::cout << image.type() << std::endl;
    image.convertTo(image, CV_32F);
    std::cout << image.type() << std::endl;
    normalize(image, dst, 1.0, 0, cv::NORM_MINMAX);
    std::cout << dst.type() << std::endl;
    imshow("图像数据归一化", dst);
    // CV_8UC3, CV_32FC3
}

void tasker_OpenCV::resize_demo(Mat &image) {
    Mat zoomin, zoomout;
    int h = image.rows;
    int w = image.cols;
    resize(image, zoomin, cv::Size(w / 2, h / 2), 0, 0, cv::INTER_LINEAR);
    imshow("zoomin", zoomin);
    resize(image, zoomout, cv::Size(w*1.5, h*1.5), 0, 0, cv::INTER_LINEAR);
    imshow("zoomout", zoomout);
}

void tasker_OpenCV::flip_demo(Mat &image) {
    Mat dst;
    // flip(image, dst, 0); // 上下翻转
    // flip(image, dst, 1); // 左右翻转
    flip(image, dst, -1); // 180°旋转
    imshow("图像翻转", dst);
}

void tasker_OpenCV::rotate_demo(Mat &image) {
    Mat dst, M;
    int w = image.cols;
    int h = image.rows;
    M = getRotationMatrix2D(cv::Point2f(w / 2, h / 2), 45, 1.0);
    double cos = abs(M.at<double>(0, 0));
    double sin = abs(M.at<double>(0, 1));
    int nw = cos*w + sin*h;
    int nh = sin*w + cos*h;
    M.at<double>(0, 2) += (nw / 2 - w / 2);
    M.at<double>(1,2) += (nh / 2 - h / 2);
    warpAffine(image, dst, M, cv::Size(nw, nh), cv::INTER_LINEAR, 0, cv::Scalar(255, 255, 0));
    imshow("旋转演示", dst);
}

/*
void tasker_OpenCV::video_demo() {
    cv::VideoCapture capture("example.mp4");
    int frame_width = capture.get(cv::CAP_PROP_FRAME_WIDTH);
    int frame_height = capture.get(cv::CAP_PROP_FRAME_HEIGHT);
    int count = capture.get(cv::CAP_PROP_FRAME_COUNT);
    double fps = capture.get(cv::CAP_PROP_FPS);
    std::cout << "frame width:" << frame_width << std::endl;
    std::cout << "frame height:" << frame_height << std::endl;
    std::cout << "FPS:" << fps << std::endl;
    std::cout << "Number of Frames:" << count << std::endl;
    cv::VideoWriter writer("D:/test.mp4", capture.get(cv::CAP_PROP_FOURCC), fps, cv::Size(frame_width, frame_height), true);
    Mat frame;
    while (true) {
        capture.read(frame);
        flip(frame, frame, 1);
        if (frame.empty()) {
            break;
        }
        imshow("frame", frame);
        colorSpace_Demo(frame);
        writer.write(frame);
        // TODO: do something....
        int c = cv::waitKey(1);
        if (c == 27) { // 退出
            break;
        }
    }

    // release
    capture.release();
    writer.release();
}
*/
void tasker_OpenCV::histogram_demo(Mat &image) {
    // 三通道分离
    std::vector<Mat> bgr_plane;
    split(image, bgr_plane);
    // 定义参数变量
    const int channels[1] = { 0 };
    const int bins[1] = { 256 };
    float hranges[2] = { 0,255 };
    const float* ranges[1] = { hranges };
    Mat b_hist;
    Mat g_hist;
    Mat r_hist;
    // 计算Blue, Green, Red通道的直方图
    calcHist(&bgr_plane[0], 1, 0, Mat(), b_hist, 1, bins, ranges);
    calcHist(&bgr_plane[1], 1, 0, Mat(), g_hist, 1, bins, ranges);
    calcHist(&bgr_plane[2], 1, 0, Mat(), r_hist, 1, bins, ranges);

    // 显示直方图
    int hist_w = 512;
    int hist_h = 400;
    int bin_w = cvRound((double)hist_w / bins[0]);
    Mat histImage = Mat::zeros(hist_h, hist_w, CV_8UC3);
    // 归一化直方图数据
    normalize(b_hist, b_hist, 0, histImage.rows, cv::NORM_MINMAX, -1, Mat());
    normalize(g_hist, g_hist, 0, histImage.rows, cv::NORM_MINMAX, -1, Mat());
    normalize(r_hist, r_hist, 0, histImage.rows, cv::NORM_MINMAX, -1, Mat());
    // 绘制直方图曲线
    for (int i = 1; i < bins[0]; i++) {
        line(histImage, cv::Point(bin_w*(i - 1), hist_h - cvRound(b_hist.at<float>(i - 1))),
            cv::Point(bin_w*(i), hist_h - cvRound(b_hist.at<float>(i))), cv::Scalar(255, 0, 0), 2, 8, 0);
        line(histImage, cv::Point(bin_w*(i - 1), hist_h - cvRound(g_hist.at<float>(i - 1))),
            cv::Point(bin_w*(i), hist_h - cvRound(g_hist.at<float>(i))), cv::Scalar(0, 255, 0), 2, 8, 0);
        line(histImage, cv::Point(bin_w*(i - 1), hist_h - cvRound(r_hist.at<float>(i - 1))),
            cv::Point(bin_w*(i), hist_h - cvRound(r_hist.at<float>(i))), cv::Scalar(0, 0, 255), 2, 8, 0);
    }
    // 显示直方图
    namedWindow("Histogram Demo", cv::WINDOW_AUTOSIZE);
    imshow("Histogram Demo", histImage);
}

void tasker_OpenCV::histogram_2d_demo(Mat &image) {
    // 2D 直方图
    Mat hsv, hs_hist;
    cvtColor(image, hsv, cv::COLOR_BGR2HSV);
    int hbins = 30, sbins = 32;
    int hist_bins[] = { hbins, sbins };
    float h_range[] = { 0, 180 };
    float s_range[] = { 0, 256 };
    const float* hs_ranges[] = { h_range, s_range };
    int hs_channels[] = { 0, 1 };
    calcHist(&hsv, 1, hs_channels, Mat(), hs_hist, 2, hist_bins, hs_ranges, true, false);
    double maxVal = 0;
    minMaxLoc(hs_hist, 0, &maxVal, 0, 0);
    int scale = 10;
    Mat hist2d_image = Mat::zeros(sbins*scale, hbins * scale, CV_8UC3);
    for (int h = 0; h < hbins; h++) {
        for (int s = 0; s < sbins; s++)
        {
            float binVal = hs_hist.at<float>(h, s);
            int intensity = cvRound(binVal * 255 / maxVal);
            rectangle(hist2d_image, cv::Point(h*scale, s*scale),
                cv::Point((h + 1)*scale - 1, (s + 1)*scale - 1),
                cv::Scalar::all(intensity),
                -1);
        }
    }
    applyColorMap(hist2d_image, hist2d_image, cv::COLORMAP_JET);
    imshow("H-S Histogram", hist2d_image);
    imwrite("D:/hist_2d.png", hist2d_image);
}

void tasker_OpenCV::histogram_eq_demo(Mat &image) {
    Mat gray;
    cvtColor(image, gray, cv::COLOR_BGR2GRAY);
    imshow("灰度图像", gray);
    Mat dst;
    equalizeHist(gray, dst);
    imshow("直方图均衡化演示", dst);
}

void tasker_OpenCV::blur_demo(Mat &image) {
    Mat dst;
    blur(image, dst, cv::Size(15, 15), cv::Point(-1, -1));
    imshow("图像模糊", dst);
}

void tasker_OpenCV::gaussian_blur_demo(Mat &image) {
    Mat dst;
    GaussianBlur(image, dst, cv::Size(0, 0), 15);
    imshow("高斯模糊", dst);
}

void tasker_OpenCV::bifilter_demo(Mat &image) {
    Mat dst;
    bilateralFilter(image, dst, 0, 100, 10);
    imshow("双边模糊", dst);
}


/*
void tasker_OpenCV::face_detection_demo() {
    std::string root_dir = "D:/opencv-4.4.0/opencv/sources/samples/dnn/face_detector/";
    cv::dnn::Net net = cv::dnn::readNetFromTensorflow(root_dir+ "opencv_face_detector_uint8.pb", root_dir+"opencv_face_detector.pbtxt");
    cv::VideoCapture capture("D:/images/video/example_dsh.mp4");
    Mat frame;
    while (true) {
        capture.read(frame);
        if (frame.empty()) {
            break;
        }
        Mat blob = cv::dnn::blobFromImage(frame, 1.0, cv::Size(300, 300), cv::Scalar(104, 177, 123), false, false);
        net.setInput(blob);// NCHW
        Mat probs = net.forward(); //
        Mat detectionMat(probs.size[2], probs.size[3], CV_32F, probs.ptr<float>());
        // 解析结果
        for (int i = 0; i < detectionMat.rows; i++) {
            float confidence = detectionMat.at<float>(i, 2);
            if (confidence > 0.5) {
                int x1 = static_cast<int>(detectionMat.at<float>(i, 3)*frame.cols);
                int y1 = static_cast<int>(detectionMat.at<float>(i, 4)*frame.rows);
                int x2 = static_cast<int>(detectionMat.at<float>(i, 5)*frame.cols);
                int y2 = static_cast<int>(detectionMat.at<float>(i, 6)*frame.rows);
                cv::Rect box(x1, y1, x2 - x1, y2 - y1);
                rectangle(frame, box, cv::Scalar(0, 0, 255), 2, 8, 0);
            }
        }
        imshow("人脸检测演示", frame);
        int c = cv::waitKey(1);
        if (c == 27) { // 退出
            break;
        }
    }
}
*/
