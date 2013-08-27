LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
	lat_pipe.cpp \

LOCAL_SHARED_LIBRARIES := \
	libmybench \

LOCAL_MODULE_TAGS := optional
LOCAL_MODULE:= lat_pipe 

include $(BUILD_EXECUTABLE)
