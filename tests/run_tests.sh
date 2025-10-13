set -e

make
./test_all_same
./test_argmin
./test_minmax
./test_peaktopeak
