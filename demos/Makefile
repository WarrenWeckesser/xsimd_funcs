DEMOS = demo_argmin demo_fsum demo_minmax demo_ordered demo_peaktopeak
CXXFLAGS += -std=c++17 -pedantic -Wall -Wextra -march=native -O3 -I $(XSIMD_INCLUDE) -I ../include

all: $(DEMOS)

%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -rf *.o $(DEMOS)
