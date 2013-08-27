LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
  IServerlfeng.cpp \
  Serverlfeng.cpp \
  binder_bench.cpp

LOCAL_SHARED_LIBRARIES := \
    libmybench \
    libutils \
    libbinder

LOCAL_MODULE_TAGS := optional
LOCAL_MODULE:= bw_binder

include $(BUILD_EXECUTABLE)
