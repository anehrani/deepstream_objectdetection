//
// Created by ek on 28.07.2022.
//

#ifndef TINYYOLOV2_DS_YOLO_H
#define TINYYOLOV2_DS_YOLO_H


#include <gst/gst.h>
#include <glib.h>
#include <stdio.h>
#include <cuda_runtime_api.h>
#include "gstnvdsmeta.h"

#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>


static GstPadProbeReturn osd_sink_pad_buffer_probe (GstPad * pad, GstPadProbeInfo * info, gpointer u_data);
static gboolean bus_call (GstBus * bus, GstMessage * msg, gpointer data);
int yolo_deepstream (int argc, char *argv[]);

#endif //DS_YOLO_H
