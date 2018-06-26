
.PHONY: all build clean

build:
	mkdir -p build
	cd build; cmake ..
	make -C ./build -j8

test: build
	make test -C ./build

clean:
	-rm -rf build
