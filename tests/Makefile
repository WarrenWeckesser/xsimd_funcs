TESTS = test_all_same test_argmin test_minmax test_ordered test_peaktopeak
CXXFLAGS += -std=c++17 -pedantic -Wall -Wextra -march=native -O3 -I $(XSIMD_INCLUDE) -I ../include

all: $(TESTS)

%: %.cpp checkit.h
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -rf $(TESTS)
