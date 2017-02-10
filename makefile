# set compiler type
CC=gcc
CXX=g++
# set compiler argument
#-g to generate debug info for gdb
CFLAGS=-Wall -O2
LDFLAGS=-L./
AR=ar
ARFLAGS=-rc
ATARGET=libcfun.a

SHAREFLAGS=-fpic -shared
STARGET=libclassfun.so

MTARGET=mainCallTest

all: 		$(ATARGET) $(STARGET) $(MTARGET)

staticlib:	$(ATARGET)
dynamiclib:	$(STARGET)
testmain:	$(MTARGET)

$(ATARGET):	fun.o
		$(AR) $(ARFLAGS) $(ATARGET) fun.o

$(STARGET): 	classfun.cpp \
		classfun.h 
		$(CXX) classfun.cpp $(SHAREFLAGS) -o $(STARGET) $(LDFLAGS) -lcfun
		
$(MTARGET): 	mainCallTest.cpp
		$(CXX) mainCallTest.cpp -o mainCallTest $(LDFLAGS) -lclassfun

fun.o:		fun.c \
		fun.h		
		$(CC) -c fun.c $(CFLAGS) 

clean:
	rm -f *.o
	rm -f $(STARGET)
	rm -f $(ATARGET)
	rm -f $(MTARGET)

.PHONY: clean 
