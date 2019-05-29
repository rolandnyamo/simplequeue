# # .author: Roland Nyamoga
# # .descr: Makefile for recursive functions

CC = g++

CFLAGS = -c
CFLAGS = -Wall
CFLAGS += -std=c++11
CFLAGS += -g #To debug with gdb

SRCS = queue.cpp main.cpp menu.cpp
OBJS = queue.o main.o menu.o
HEADERS = queue.hpp menu.hpp
OUT = qlist #Name of the executable

#My output depends on the objects.
$(OUT): $(OBJS)
	$(CC) $(SRCS) $(CFLAGS) -o $(OUT)
	rm $(OBJS) *.gch

#Objects depend on source and header files
$(OBJS): $(SRCS) $(HEADERS)
	$(CC) -c $(SRCS) $(HEADERS) 

#This cleans all files created from compiling
clean:
	rm $(OUT)
