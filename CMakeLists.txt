cmake_minimum_required(VERSION 3.17)
project(YoloObjectDetector)

set(CMAKE_CXX_STANDARD 14) #setting C++ 14 standard
find_package(PkgConfig) #finding pkg-config is a helper tool

#using pkg-config to getting Gstreamer
pkg_check_modules(GSTREAMER REQUIRED gstreamer-1.0)

# link opencv
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# link cuda
include(FindCUDA)
find_package(CUDA REQUIRED)
set(CUDA_NVCC_PLAGS ${CUDA_NVCC_PLAGS};-std=c++14;-g;-G;-gencode;arch=compute_30;code=sm_30)


include_directories(
        /usr/lib/x86_64-linux-gnu/glib-2.0/include
        /usr/include/glib-2.0
        /usr/include/libsoup-2.4
        /usr/include/json-glib-1.0
)

include_directories(
        /opt/nvidia/deepstream/deepstream-6.1/sources/includes/
        /home/ek/install/TensorRT-8.4.1.5/include
)

#including GStreamer header files directory
include_directories(
        ${GLIB_INCLUDE_DIRS}
        ${GSTREAMER_INCLUDE_DIRS}
        ${CUDA_INCLUDE_DIRS}
)

#linking GStreamer library directory
link_directories(
        ${GLIB_LIBRARY_DIRS}
        ${GSTREAMER_LIBRARY_DIRS}
        ${CUDA_LIBRARIES}
        ${OpenCV_LIBS}
        /home/ek/install/TensorRT-8.4.1.5/lib
)



#building target executable
add_executable(${PROJECT_NAME} main.cpp
        include/ds_yolo.cpp
        include/ds_yolo.h
        )

#linking Gstreamer library with target executable
target_link_libraries(${PROJECT_NAME}
        ${GSTREAMER_LIBRARIES}
        nvonnxparser
        nvinfer
        nvinfer_plugin
        cudart
        ${OpenCV_LIBS}
        )


set(DSLIBDIR /opt/nvidia/deepstream/deepstream-6.1/lib/)
set(PROJECT_LINK_LIBS
        ${DSLIBDIR}/libnvds_inferutils.so
        ${DSLIBDIR}/libnvv4l2.so
        ${DSLIBDIR}/libpostprocess_impl.so
        ${DSLIBDIR}/libnvds_yml_parser.so
        ${DSLIBDIR}/libnvds_video_metadata_serialization.so
        ${DSLIBDIR}/libnvds_nvtxhelper.so
        ${DSLIBDIR}/libnvds_nvmultiobjecttracker.so
        ${DSLIBDIR}/libnvds_nmos.so
        ${DSLIBDIR}/libnvds_msgconv.so
        ${DSLIBDIR}/libnvds_msgbroker.so
        ${DSLIBDIR}/libnvds_meta.so
        ${DSLIBDIR}/libnvds_mem_allocator.so
        ${DSLIBDIR}/libnvds_logger.so
        ${DSLIBDIR}/libnvds_lljpegdec.so
        ${DSLIBDIR}/libnvds_kafka_proto.so
        ${DSLIBDIR}/libnvds_inferutils.so
        ${DSLIBDIR}/libnvds_infer.so
        ${DSLIBDIR}/libnvds_infer_server.so
        ${DSLIBDIR}/libnvds_inferlogger.so
        ${DSLIBDIR}/libnvds_infercustomparser.so
        ${DSLIBDIR}/libnvdsinfer_custom_impl_Yolo.so
        ${DSLIBDIR}/libnvdsgst_tensor.so
        ${DSLIBDIR}/libnvdsgst_smartrecord.so
        ${DSLIBDIR}/libnvdsgst_meta.so
        ${DSLIBDIR}/libnvdsgst_inferbase.so
        ${DSLIBDIR}/libnvdsgst_helper.so
        ${DSLIBDIR}/libnvdsgst_bufferpool.so
        ${DSLIBDIR}/libnvdsgst_3d_gst.so
        ${DSLIBDIR}/libnvds_dsanalytics.so
        ${DSLIBDIR}/libnvds_dewarper.so
        ${DSLIBDIR}/libnvds_custom_sequence_preprocess.so
        ${DSLIBDIR}/libnvds_csvparser.so
        ${DSLIBDIR}/libnvdsbufferpool.so
        ${DSLIBDIR}/libnvds_batch_jpegenc.so
        ${DSLIBDIR}/libnvds_amqp_proto.so
        ${DSLIBDIR}/libnvbufsurftransform.so
        ${DSLIBDIR}/libnvbufsurface.so
        ${DSLIBDIR}/libnvbuf_fdmap.so
        ${DSLIBDIR}/libcustom_videoimpl.so
        ${DSLIBDIR}/libcuvidv4l2.so
        ${DSLIBDIR}/libgstnvdsseimeta.so
        ${DSLIBDIR}/libiothub_client.so
        ${DSLIBDIR}/libnvds_3d_common.so
        )


target_link_libraries( ${PROJECT_NAME}
        ${PROJECT_LINK_LIBS}
        )
