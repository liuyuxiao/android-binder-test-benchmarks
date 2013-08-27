LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
  IServerlfeng.cpp \
  Serverlfeng.cpp \
  lat2_binder.cpp

LOCAL_SHARED_LIBRARIES := \
  libmybench \
  libutils \
  libbinder

LOCAL_MODULE_TAGS := optional
LOCAL_MODULE:= lat2_binder

include $(BUILD_EXECUTABLE)
