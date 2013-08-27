LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
	lat_tcp.cpp \

LOCAL_SHARED_LIBRARIES := \
	libmybench \

LOCAL_MODULE_TAGS := optional
LOCAL_MODULE:= lat_tcp 

include $(BUILD_EXECUTABLE)
