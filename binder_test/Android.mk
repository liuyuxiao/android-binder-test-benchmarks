LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
	binder_tester.c

LOCAL_SHARED_LIBRARIES := \
  libutils \
  libbinder

LOCAL_MODULE_TAGS := optional
LOCAL_MODULE:= binder_test

include $(BUILD_EXECUTABLE)
