EXECUTABLES = all_same_timing min_argmin_timing ordered_timing

all: $(EXECUTABLES)

%: %.cpp
	$(CXX) -std=c++17 -pedantic -Wall -Wextra -march=native -O3 -I $(XSIMD_INCLUDE) -I ../include $< -o $@

clean:
	rm -rf *.o $(EXECUTABLES)
