CXX=g++
CXX_FLAGS=
LD=g++
LD_FLAGS=
CXX_SRC=$(shell find . -type f -name "*.cpp")
OBJ=$(patsubst %.cpp, %.cxx.o, $(CXX_SRC))
OUTPUT=vm

test: $(OUTPUT)
	./$<

testCmpl: $(OUTPUT)
	./$< compile test.asm test.bin

$(OUTPUT): $(OBJ)
	@echo "Linking $@..."
	@$(LD) $(LD_FLAGS) $(OBJ) -o $@

%.cxx.o: %.cpp
	@echo "CXX $<..."
	@$(CXX) -c $< -o $@