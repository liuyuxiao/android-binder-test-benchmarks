LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
	bw_pipe.cpp \

LOCAL_SHARED_LIBRARIES := \
	libmybench \

LOCAL_MODULE_TAGS := optional
LOCAL_MODULE:= bw_pipe 

include $(BUILD_EXECUTABLE)
