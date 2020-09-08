CC=clang

CFLAGS=-g -DDEBUG -std=c++11 -fPIC -I src -DPLATFORM_LINUX $(shell sdl2-config --cflags)
LIBS=-lstdc++ -lm -ldl -lGL $(shell sdl2-config --libs) -Wl,-R, -Wl,.

all: libRenderer.so host

.PHONY: clean
clean:
	rm -f host
	rm -f lib*.so

# Platform
host: src/host.cpp libRenderer.so
	${CC} src/host.cpp ${CFLAGS} -o $@ ${LIBS}

libRenderer.so: src/renderer.cpp src/gl.cpp src/gl.h
	${CC} src/renderer.cpp ${CFLAGS} -shared -o $@ ${LIBS}

