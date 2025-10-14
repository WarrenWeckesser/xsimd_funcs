EXECUTABLES = all_same_timing min_argmin_timing ordered_timing
CXXFLAGS += -std=c++17 -pedantic -Wall -Wextra -march=native -O3 -I $(XSIMD_INCLUDE) -I ../include

all: $(EXECUTABLES)

%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -rf *.o $(EXECUTABLES)
