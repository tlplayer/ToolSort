CC      := g++
CCFLAGS :=  -g -Wall -I

TARGETS:=  ToolSort maketest test
MAINS  := $(addsuffix .o, $(TARGETS) )
OBJ    :=  $(MAINS)
DEPS   := ToolSort.cpp 

.PHONY: all clean

all: $(TARGETS)

clean:
	rm -f $(TARGETS) 

test: 
	g++ -o test -g test.cpp

ToolSort: 
	g++ -o  ToolSort -g  ToolSort.cpp

maketest:
	g++ -o  maketest -g maketest.cpp
