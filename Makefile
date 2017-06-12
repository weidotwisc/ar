AR_SRC := ./src/ar.cpp 
AR_OBJS := $(AR_SRC:%.cpp=%.o)

TEST_SRC := ./test/test.cpp
TEST_OBJS := $(TEST_SRC:%.cpp=%.o)

LIBDIR := lib

ARLIB := $(LIBDIR)/libar.so

./src/%.o: ./src/%.cpp
	$(MPICXX)  -fpic -shared -c $< -o $@

./test/%.o: ./test/%.cpp	
	$(CXX) -O3 -c -I${AR_HOME}/include $< -o $@
all:libar

$(ARLIB):	$(AR_OBJS)  $(LIBDIR)
	$(MPICXX) -fpic -shared $(AR_OBJS) -L{MPI_HOME}/lib -o $@ 


$(LIBDIR): $(AR_OBJS) 
	mkdir -p $(LIBDIR)	
	mkdir -p include
	cp ./src/*.h ./include
	
	
.PHONY: libar
libar: $(ARLIB)

artest: $(ARLIB) $(TEST_OBJS)
	$(CXX)  $(TEST_OBJS) -o "$@" -L${AR_HOME}/lib -lar

clean:
	$(RM) -fr artest ./lib ./include *.o ./src/*.o ./test/*.o
