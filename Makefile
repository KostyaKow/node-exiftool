default:
	gcc -fPIC -g -c -Wall test.c; gcc -shared -Wl,-soname,libnodeexiftool.so.0 \
		-o libnodeexiftool.so.0.1 test.o -lc; ln -s libnodeexiftool.so.0.1 libnodeexiftool.so

test:
	node test.js; dmesg | tail -n1
