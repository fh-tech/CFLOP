all: CFLOP

CFLOP:
	cmake -H. -Bbuild && cd build && cmake --build . && ctest