TEMPLATE = app
CONFIG += c++11
CONFIG += console c++11
CONFIG += app_bundle
CONFIG += qt

SOURCES += main.cpp
SOURCES += tasker_cpp.cpp
SOURCES += tasker_opencv.cpp
SOURCES += tasker_stl.cpp

HEADERS += tasker.h

#==============================
#compiler and linker flags
unix {
QMAKE_LFLAGS += -Wl,--no-as-needed
}


#eigen 3.4: this tool do not need any lib.
INCLUDEPATH += /media/newdisk/home2/liyaning2/CPP/tools/eigin/eigen-3.4.0-GNU/include/

#opencv 4: pay attention to ld.so.config.d/opencv.conf
#OPENCV_DIR = "/media/newdisk/home2/liyaning2/CPP/tools/opencv/opencv455/usr/local"
INCLUDEPATH += -I   /usr/local/include/opencv4/
DEPENDPATH +=       /usr/local/include/opencv4/
OPENCV_LIB_DIR = "/usr/local/lib/opencv4/"
LIBS += -L $$OPENCV_LIB_DIR -lopencv_core
LIBS += -L $$OPENCV_LIB_DIR -lopencv_highgui
LIBS += -L $$OPENCV_LIB_DIR -lopencv_imgcodecs
LIBS += -L $$OPENCV_LIB_DIR -lopencv_imgproc


#libtorch 1.8: pay attention to ld.so.config.d/opencv.conf
LIBTORCH_DIR = "/media/newdisk/home2/liyaning2/CPP/tools/libtorch/libtorch"
INCLUDEPATH += -I $$LIBTORCH_DIR/include/torch/csrc/api/include
INCLUDEPATH += -I $$LIBTORCH_DIR/include
DEPENDPATH += $$LIBTORCH_DIR/include/torch/csrc/api/include
DEPENDPATH += $$LIBTORCH_DIR/include
LIBS += -L$$LIBTORCH_DIR/lib -lc10 -lc10_cuda \
        -lcaffe2_detectron_ops_gpu \
        -lcaffe2_module_test_dynamic \
        -lcaffe2_nvrtc -lcaffe2_observers \
        -lonnx -lonnx_proto \
       -ltorch_cuda -ltorch_cpu -ltorch
