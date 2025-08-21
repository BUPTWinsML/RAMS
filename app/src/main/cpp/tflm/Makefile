CC = gcc
CXX = g++

SRC_DIRS = .
BUILD_DIR = $(SRC_DIRS)/build

MKDIR = mkdir -p

SRCS = $(shell find $(SRC_DIRS) -name "*.cc") $(shell find $(SRC_DIRS) -name "*.c")

OBJS = $(patsubst %.cc,$(BUILD_DIR)/%.o,$(patsubst %.c,$(BUILD_DIR)/%.o,$(SRCS)))

DEPS = $(OBJS:.o=.d)

INC=\
-I. \
-I./third_party/kissfft \
-I./third_party/gemmlowp \
-I./third_party/flatbuffers/include \
-I./third_party/cmsis_nn/Include \
-I./third_party/cmsis_nn \
-I./third_party/ruy

KERNEL_OPTIMIZATION_LEVEL = -O3


COMMON_FLAGS := \
  -DCMSIS_NN_USE_SINGLE_ROUNDING \
  -DTF_LITE_DISABLE_X86_NEON \
  $(CC_WARNINGS)

CXXFLAGS := \
  -std=c++11 \
  -fno-rtti \
  -fno-exceptions \
  -Wnon-virtual-dtor \
  $(COMMON_FLAGS)

CCFLAGS := \
  -std=c11 \
  $(COMMON_FLAGS)

CXXFLAGS += -DNDEBUG -DCMSIS_NN 
CCFLAGS  += -DNDEBUG -DCMSIS_NN 

LDFLAGS = -lm
LDFLAGS += -Wl,--fatal-warnings -Wl,--gc-sections

TARGET_EXEC = test-cmsisnn

.PHONY: all clean

all: $(BUILD_DIR)/$(TARGET_EXEC)

-include $(DEPS)

$(BUILD_DIR):
	$(MKDIR) $@

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(MKDIR) $(dir $@)
	$(CC) $(CCFLAGS) $(KERNEL_OPTIMIZATION_LEVEL) $(INC) -MMD -MP -c $< -o $@

$(BUILD_DIR)/%.o: %.cc | $(BUILD_DIR)
	$(MKDIR) $(dir $@)
	$(CXX) $(CXXFLAGS) $(KERNEL_OPTIMIZATION_LEVEL) $(INC) -MMD -MP -c $< -o $@

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS) | $(BUILD_DIR)
	$(CXX) $(LDFLAGS) $(OBJS) -o $@
	strip -s $@

clean:
	rm -rf $(BUILD_DIR)
