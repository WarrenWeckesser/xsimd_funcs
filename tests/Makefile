TESTS = test_all_same test_argmin

all: $(TESTS)

test_all_same: test_all_same.cpp
	g++ -std=c++17 -pedantic -Wall -Wextra -march=native -O3 -I $(XSIMD_INCLUDE) -I ../include test_all_same.cpp -o test_all_same

test_argmin: test_argmin.cpp
	g++ -std=c++17 -pedantic -Wall -Wextra -march=native -O3 -I $(XSIMD_INCLUDE) -I ../include test_argmin.cpp -o test_argmin

clean:
	rm -rf *.o $(TESTS)
