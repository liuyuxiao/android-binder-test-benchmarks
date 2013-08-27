LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
binderAddInts.cpp

LOCAL_SHARED_LIBRARIES := \
  libutils \
  libbinder

LOCAL_MODULE_TAGS := optional
LOCAL_MODULE:= lat_binder

include $(BUILD_EXECUTABLE)
