TARGET=table_reader_tiny

CC=g++

CPPFLAGS=-D__LINUX__       \
		-g         \
		-rdynamic  \
		-O3        \
		-I.        \
		-std=c++11 \

LINKFALGS=-lboost_atomic -lgtest -lpthread

#CPPOBJS=$(shell find ./ -name "*.cpp" | awk -F".cpp" '{printf "%s.o\n", $$1}')
CPPOBJS=$(shell find ./ -name "*.cpp")

all:
	$(CC) $(CPPFLAGS) $(CPPOBJS) $(LINKFALGS) -o $(TARGET)
