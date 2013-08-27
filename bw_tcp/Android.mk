LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
	bw_tcp.cpp \

LOCAL_SHARED_LIBRARIES := \
	libmybench \

LOCAL_MODULE_TAGS := optional
LOCAL_MODULE:= bw_tcp

include $(BUILD_EXECUTABLE)
