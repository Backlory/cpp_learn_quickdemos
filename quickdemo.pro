TEMPLATE = app
CONFIG += c++14
CONFIG += console c++11
CONFIG += app_bundle
CONFIG += qt

SOURCES += main.cpp \
    tasker_eigen.cpp \
    tasker_libtorch.cpp
SOURCES += tasker_cpp.cpp
SOURCES += tasker_opencv.cpp
SOURCES += tasker_stl.cpp

HEADERS += tasker.h

#==============================
#compiler and linker flags
unix {
QMAKE_LFLAGS += -Wl,--no-as-needed
}


#=============eigen 3.4: this tool do not need any lib.
INCLUDEPATH += /media/newdisk/home2/liyaning2/CPP/tools/eigin/eigen-3.4.0-GNU/include/


#=============opencv 4: pay attention to ld.so.config.d/opencv.conf
#OPENCV_DIR = "/media/newdisk/home2/liyaning2/CPP/tools/opencv/opencv455/usr/local"
INCLUDEPATH += -I   /usr/local/include/opencv4/
DEPENDPATH +=       /usr/local/include/opencv4/
OPENCV_LIB_DIR = "/usr/local/lib/opencv4/"
#LIBS += -L$$OPENCV_LIB_DIR -lopencv_aruco
#LIBS += -L$$OPENCV_LIB_DIR -lopencv_barcode
#LIBS += -L$$OPENCV_LIB_DIR -lopencv_bgsegm
#LIBS += -L$$OPENCV_LIB_DIR -lopencv_bioinspired
#LIBS += -L$$OPENCV_LIB_DIR -lopencv_calib3d
#LIBS += -L$$OPENCV_LIB_DIR -lopencv_ccalib
LIBS += -L$$OPENCV_LIB_DIR -lopencv_core
#LIBS += -L$$OPENCV_LIB_DIR -lopencv_cvv
#LIBS += -L$$OPENCV_LIB_DIR -lopencv_datasets
#LIBS += -L$$OPENCV_LIB_DIR -lopencv_dnn_objdetect
#LIBS += -L$$OPENCV_LIB_DIR -lopencv_dnn
#LIBS += -L$$OPENCV_LIB_DIR -lopencv_dnn_superres
#LIBS += -L$$OPENCV_LIB_DIR -lopencv_dpm
#LIBS += -L$$OPENCV_LIB_DIR -lopencv_face
#LIBS += -L$$OPENCV_LIB_DIR -lopencv_features2d
#LIBS += -L$$OPENCV_LIB_DIR -lopencv_flann
#LIBS += -L$$OPENCV_LIB_DIR -lopencv_fuzzy
#LIBS += -L$$OPENCV_LIB_DIR -lopencv_gapi
#LIBS += -L$$OPENCV_LIB_DIR -lopencv_hfs
LIBS += -L$$OPENCV_LIB_DIR -lopencv_highgui
LIBS += -L$$OPENCV_LIB_DIR -lopencv_imgcodecs
#LIBS += -L$$OPENCV_LIB_DIR -lopencv_img_hash
LIBS += -L$$OPENCV_LIB_DIR -lopencv_imgproc
#LIBS += -L$$OPENCV_LIB_DIR -lopencv_intensity_transform
#LIBS += -L$$OPENCV_LIB_DIR -lopencv_line_descriptor
#LIBS += -L$$OPENCV_LIB_DIR -lopencv_mcc
#LIBS += -L$$OPENCV_LIB_DIR -lopencv_ml
#LIBS += -L$$OPENCV_LIB_DIR -lopencv_objdetect
#LIBS += -L$$OPENCV_LIB_DIR -lopencv_optflow
#LIBS += -L$$OPENCV_LIB_DIR -lopencv_phase_unwrapping
#LIBS += -L$$OPENCV_LIB_DIR -lopencv_photo
#LIBS += -L$$OPENCV_LIB_DIR -lopencv_plot
#LIBS += -L$$OPENCV_LIB_DIR -lopencv_quality
#LIBS += -L$$OPENCV_LIB_DIR -lopencv_rapid
#LIBS += -L$$OPENCV_LIB_DIR -lopencv_reg
#LIBS += -L$$OPENCV_LIB_DIR -lopencv_rgbd
#LIBS += -L$$OPENCV_LIB_DIR -lopencv_saliency
#LIBS += -L$$OPENCV_LIB_DIR -lopencv_shape
#LIBS += -L$$OPENCV_LIB_DIR -lopencv_stereo
#LIBS += -L$$OPENCV_LIB_DIR -lopencv_stitching
#LIBS += -L$$OPENCV_LIB_DIR -lopencv_structured_light
#LIBS += -L$$OPENCV_LIB_DIR -lopencv_superres
#LIBS += -L$$OPENCV_LIB_DIR -lopencv_surface_matching
#LIBS += -L$$OPENCV_LIB_DIR -lopencv_text
#LIBS += -L$$OPENCV_LIB_DIR -lopencv_tracking
LIBS += -L$$OPENCV_LIB_DIR -lopencv_videoio
LIBS += -L$$OPENCV_LIB_DIR -lopencv_video
#LIBS += -L$$OPENCV_LIB_DIR -lopencv_videostab
#LIBS += -L$$OPENCV_LIB_DIR -lopencv_wechat_qrcode
#LIBS += -L$$OPENCV_LIB_DIR -lopencv_xfeatures2d
#LIBS += -L$$OPENCV_LIB_DIR -lopencv_ximgproc
#LIBS += -L$$OPENCV_LIB_DIR -lopencv_xobjdetect
#LIBS += -L$$OPENCV_LIB_DIR -lopencv_xphoto



#==============libtorch 1.8: pay attention to ld.so.config.d/opencv.conf
LIBTORCH_DIR = "/media/newdisk/home2/liyaning2/CPP/tools/libtorch/libtorch"
INCLUDEPATH += -I $$LIBTORCH_DIR/include/torch/csrc/api/include
INCLUDEPATH += -I $$LIBTORCH_DIR/include
DEPENDPATH += $$LIBTORCH_DIR/include/torch/csrc/api/include
DEPENDPATH += $$LIBTORCH_DIR/include

LIBS += -L$$LIBTORCH_DIR/lib -lasmjit
LIBS += -L$$LIBTORCH_DIR/lib -lbenchmark
LIBS += -L$$LIBTORCH_DIR/lib -lbenchmark_main
LIBS += -L$$LIBTORCH_DIR/lib -lc10
LIBS += -L$$LIBTORCH_DIR/lib -lc10_cuda
LIBS += -L$$LIBTORCH_DIR/lib -lc10d
LIBS += -L$$LIBTORCH_DIR/lib -lcaffe2_detectron_ops_gpu
LIBS += -L$$LIBTORCH_DIR/lib -lcaffe2_module_test_dynamic
LIBS += -L$$LIBTORCH_DIR/lib -lcaffe2_nvrtc
LIBS += -L$$LIBTORCH_DIR/lib -lcaffe2_observers
LIBS += -L$$LIBTORCH_DIR/lib -lCaffe2_perfkernels_avx
LIBS += -L$$LIBTORCH_DIR/lib -lcaffe2_protos
LIBS += -L$$LIBTORCH_DIR/lib -lclog
LIBS += -L$$LIBTORCH_DIR/lib -lcpuinfo
LIBS += -L$$LIBTORCH_DIR/lib -lcpuinfo_internals
LIBS += -L$$LIBTORCH_DIR/lib -ldnnl
LIBS += -L$$LIBTORCH_DIR/lib -lfbgemm
LIBS += -L$$LIBTORCH_DIR/lib -lfmt
LIBS += -L$$LIBTORCH_DIR/lib -lfoxi_loader
LIBS += -L$$LIBTORCH_DIR/lib -lgloo
LIBS += -L$$LIBTORCH_DIR/lib -lgloo_cuda
LIBS += -L$$LIBTORCH_DIR/lib -lgmock
LIBS += -L$$LIBTORCH_DIR/lib -lgmock_main
LIBS += -L$$LIBTORCH_DIR/lib -lgtest
LIBS += -L$$LIBTORCH_DIR/lib -lgtest_main
LIBS += -L$$LIBTORCH_DIR/lib -ljitbackend_test
LIBS += -L$$LIBTORCH_DIR/lib -lkineto
LIBS += -L$$LIBTORCH_DIR/lib -lmkldnn
LIBS += -L$$LIBTORCH_DIR/lib -lnnpack
LIBS += -L$$LIBTORCH_DIR/lib -lnnpack_reference_layers
LIBS += -L$$LIBTORCH_DIR/lib -lnvrtc-builtins
LIBS += -L$$LIBTORCH_DIR/lib -lonnx
LIBS += -L$$LIBTORCH_DIR/lib -lonnx_proto
LIBS += -L$$LIBTORCH_DIR/lib -lprocess_group_agent
LIBS += -L$$LIBTORCH_DIR/lib -lprotobuf
LIBS += -L$$LIBTORCH_DIR/lib -lprotobuf-lite
LIBS += -L$$LIBTORCH_DIR/lib -lprotoc
LIBS += -L$$LIBTORCH_DIR/lib -lpthreadpool
LIBS += -L$$LIBTORCH_DIR/lib -lpytorch_qnnpack
LIBS += -L$$LIBTORCH_DIR/lib -lqnnpack
LIBS += -L$$LIBTORCH_DIR/lib -lshm
LIBS += -L$$LIBTORCH_DIR/lib -ltensorpipe
LIBS += -L$$LIBTORCH_DIR/lib -ltensorpipe_agent
LIBS += -L$$LIBTORCH_DIR/lib -ltensorpipe_uv
LIBS += -L$$LIBTORCH_DIR/lib -ltorch
LIBS += -L$$LIBTORCH_DIR/lib -ltorch_cpu
LIBS += -L$$LIBTORCH_DIR/lib -ltorch_cuda
LIBS += -L$$LIBTORCH_DIR/lib -ltorch_global_deps
LIBS += -L$$LIBTORCH_DIR/lib -ltorchbind_test
LIBS += -L$$LIBTORCH_DIR/lib -lXNNPACK

PRE_TARGETDEPS += $$LIBTORCH_DIR/lib/libasmjit.a
PRE_TARGETDEPS += $$LIBTORCH_DIR/lib/libbenchmark.a
PRE_TARGETDEPS += $$LIBTORCH_DIR/lib/libbenchmark_main.a
PRE_TARGETDEPS += $$LIBTORCH_DIR/lib/libc10d.a
PRE_TARGETDEPS += $$LIBTORCH_DIR/lib/libCaffe2_perfkernels_avx.a
PRE_TARGETDEPS += $$LIBTORCH_DIR/lib/libcaffe2_protos.a
PRE_TARGETDEPS += $$LIBTORCH_DIR/lib/libclog.a
PRE_TARGETDEPS += $$LIBTORCH_DIR/lib/libcpuinfo.a
PRE_TARGETDEPS += $$LIBTORCH_DIR/lib/libcpuinfo_internals.a
PRE_TARGETDEPS += $$LIBTORCH_DIR/lib/libdnnl.a
PRE_TARGETDEPS += $$LIBTORCH_DIR/lib/libfbgemm.a
PRE_TARGETDEPS += $$LIBTORCH_DIR/lib/libfmt.a
PRE_TARGETDEPS += $$LIBTORCH_DIR/lib/libfoxi_loader.a
PRE_TARGETDEPS += $$LIBTORCH_DIR/lib/libgloo.a
PRE_TARGETDEPS += $$LIBTORCH_DIR/lib/libgloo_cuda.a
PRE_TARGETDEPS += $$LIBTORCH_DIR/lib/libgmock.a
PRE_TARGETDEPS += $$LIBTORCH_DIR/lib/libgmock_main.a
PRE_TARGETDEPS += $$LIBTORCH_DIR/lib/libgtest.a
PRE_TARGETDEPS += $$LIBTORCH_DIR/lib/libgtest_main.a
PRE_TARGETDEPS += $$LIBTORCH_DIR/lib/libkineto.a
PRE_TARGETDEPS += $$LIBTORCH_DIR/lib/libmkldnn.a
PRE_TARGETDEPS += $$LIBTORCH_DIR/lib/libnnpack.a
PRE_TARGETDEPS += $$LIBTORCH_DIR/lib/libnnpack_reference_layers.a
PRE_TARGETDEPS += $$LIBTORCH_DIR/lib/libonnx.a
PRE_TARGETDEPS += $$LIBTORCH_DIR/lib/libonnx_proto.a
PRE_TARGETDEPS += $$LIBTORCH_DIR/lib/libprotobuf.a
PRE_TARGETDEPS += $$LIBTORCH_DIR/lib/libprotobuf-lite.a
PRE_TARGETDEPS += $$LIBTORCH_DIR/lib/libprotoc.a
PRE_TARGETDEPS += $$LIBTORCH_DIR/lib/libpthreadpool.a
PRE_TARGETDEPS += $$LIBTORCH_DIR/lib/libpytorch_qnnpack.a
PRE_TARGETDEPS += $$LIBTORCH_DIR/lib/libqnnpack.a
PRE_TARGETDEPS += $$LIBTORCH_DIR/lib/libtensorpipe.a
PRE_TARGETDEPS += $$LIBTORCH_DIR/lib/libtensorpipe_uv.a
PRE_TARGETDEPS += $$LIBTORCH_DIR/lib/libXNNPACK.a
