EXECUTABLES = all_same_timing min_argmin_timing ordered_timing

all: $(EXECUTABLES)

all_same_timing: all_same_timing.cpp
	g++ -std=c++17 -pedantic -Wall -Wextra -march=native -O3 -I $(XSIMD_INCLUDE) -I ../include all_same_timing.cpp -o all_same_timing

min_argmin_timing: min_argmin_timing.cpp
	g++ -std=c++17 -pedantic -Wall -Wextra -march=native -O3 -I $(XSIMD_INCLUDE) -I ../include min_argmin_timing.cpp -o min_argmin_timing

ordered_timing: ordered_timing.cpp
	g++ -std=c++17 -pedantic -Wall -Wextra -march=native -O3 -I $(XSIMD_INCLUDE) -I ../include ordered_timing.cpp -o ordered_timing

clean:
	rm -rf *.o $(EXECUTABLES)
