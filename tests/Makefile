TESTS = test_all_same test_argmin test_minmax test_peaktopeak

all: $(TESTS)

%: %.cpp checkit.h
	g++ -std=c++17 -pedantic -Wall -Wextra -march=native -O3 -I $(XSIMD_INCLUDE) -I ../include $< -o $@

clean:
	rm -rf $(TESTS)
