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
#LIBS += -L $$OPENCV_LIB_DIR -lopencv_aruco
#LIBS += -L $$OPENCV_LIB_DIR -lopencv_barcode
#LIBS += -L $$OPENCV_LIB_DIR -lopencv_bgsegm
#LIBS += -L $$OPENCV_LIB_DIR -lopencv_bioinspired
#LIBS += -L $$OPENCV_LIB_DIR -lopencv_calib3d
#LIBS += -L $$OPENCV_LIB_DIR -lopencv_ccalib
LIBS += -L $$OPENCV_LIB_DIR -lopencv_core
#LIBS += -L $$OPENCV_LIB_DIR -lopencv_cvv
#LIBS += -L $$OPENCV_LIB_DIR -lopencv_datasets
#LIBS += -L $$OPENCV_LIB_DIR -lopencv_dnn_objdetect
#LIBS += -L $$OPENCV_LIB_DIR -lopencv_dnn
#LIBS += -L $$OPENCV_LIB_DIR -lopencv_dnn_superres
#LIBS += -L $$OPENCV_LIB_DIR -lopencv_dpm
#LIBS += -L $$OPENCV_LIB_DIR -lopencv_face
#LIBS += -L $$OPENCV_LIB_DIR -lopencv_features2d
#LIBS += -L $$OPENCV_LIB_DIR -lopencv_flann
#LIBS += -L $$OPENCV_LIB_DIR -lopencv_fuzzy
#LIBS += -L $$OPENCV_LIB_DIR -lopencv_gapi
#LIBS += -L $$OPENCV_LIB_DIR -lopencv_hfs
LIBS += -L $$OPENCV_LIB_DIR -lopencv_highgui
LIBS += -L $$OPENCV_LIB_DIR -lopencv_imgcodecs
#LIBS += -L $$OPENCV_LIB_DIR -lopencv_img_hash
LIBS += -L $$OPENCV_LIB_DIR -lopencv_imgproc
#LIBS += -L $$OPENCV_LIB_DIR -lopencv_intensity_transform
#LIBS += -L $$OPENCV_LIB_DIR -lopencv_line_descriptor
#LIBS += -L $$OPENCV_LIB_DIR -lopencv_mcc
#LIBS += -L $$OPENCV_LIB_DIR -lopencv_ml
#LIBS += -L $$OPENCV_LIB_DIR -lopencv_objdetect
#LIBS += -L $$OPENCV_LIB_DIR -lopencv_optflow
#LIBS += -L $$OPENCV_LIB_DIR -lopencv_phase_unwrapping
#LIBS += -L $$OPENCV_LIB_DIR -lopencv_photo
#LIBS += -L $$OPENCV_LIB_DIR -lopencv_plot
#LIBS += -L $$OPENCV_LIB_DIR -lopencv_quality
#LIBS += -L $$OPENCV_LIB_DIR -lopencv_rapid
#LIBS += -L $$OPENCV_LIB_DIR -lopencv_reg
#LIBS += -L $$OPENCV_LIB_DIR -lopencv_rgbd
#LIBS += -L $$OPENCV_LIB_DIR -lopencv_saliency
#LIBS += -L $$OPENCV_LIB_DIR -lopencv_shape
#LIBS += -L $$OPENCV_LIB_DIR -lopencv_stereo
#LIBS += -L $$OPENCV_LIB_DIR -lopencv_stitching
#LIBS += -L $$OPENCV_LIB_DIR -lopencv_structured_light
#LIBS += -L $$OPENCV_LIB_DIR -lopencv_superres
#LIBS += -L $$OPENCV_LIB_DIR -lopencv_surface_matching
#LIBS += -L $$OPENCV_LIB_DIR -lopencv_text
#LIBS += -L $$OPENCV_LIB_DIR -lopencv_tracking
LIBS += -L $$OPENCV_LIB_DIR -lopencv_videoio
LIBS += -L $$OPENCV_LIB_DIR -lopencv_video
#LIBS += -L $$OPENCV_LIB_DIR -lopencv_videostab
#LIBS += -L $$OPENCV_LIB_DIR -lopencv_wechat_qrcode
#LIBS += -L $$OPENCV_LIB_DIR -lopencv_xfeatures2d
#LIBS += -L $$OPENCV_LIB_DIR -lopencv_ximgproc
#LIBS += -L $$OPENCV_LIB_DIR -lopencv_xobjdetect
#LIBS += -L $$OPENCV_LIB_DIR -lopencv_xphoto



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
