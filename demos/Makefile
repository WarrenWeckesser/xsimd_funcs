DEMOS = demo_argmin demo_fsum demo_minmax demo_ordered demo_peaktopeak

all: $(DEMOS)

demo_minmax: demo_minmax.cpp
	g++ -std=c++17 -pedantic -Wall -Wextra -march=native -O3 -I $(XSIMD_INCLUDE) -I ../include demo_minmax.cpp -o demo_minmax

demo_argmin: demo_argmin.cpp
	g++ -std=c++17 -pedantic -Wall -Wextra -march=native -O3 -I $(XSIMD_INCLUDE) -I ../include demo_argmin.cpp -o demo_argmin

demo_argmin_blocks: demo_argmin_blocks.cpp
	g++ -std=c++17 -pedantic -Wall -Wextra -march=native -O3 -I $(XSIMD_INCLUDE) -I ../include demo_argmin_blocks.cpp -o demo_argmin_blocks

demo_peaktopeak: demo_peaktopeak.cpp
	g++ -std=c++17 -pedantic -Wall -Wextra -march=native -O3 -I $(XSIMD_INCLUDE) -I ../include demo_peaktopeak.cpp -o demo_peaktopeak

demo_fsum: demo_fsum.cpp
	g++ -std=c++17 -pedantic -Wall -Wextra -march=native -O3 -I $(XSIMD_INCLUDE) -I ../include demo_fsum.cpp -o demo_fsum

demo_ordered: demo_ordered.cpp
	g++ -std=c++17 -pedantic -Wall -Wextra -march=native -O3 -I $(XSIMD_INCLUDE) -I ../include demo_ordered.cpp -o demo_ordered

clean:
	rm -rf *.o $(DEMOS)
