CC = gcc
CFLAGS = -std=c++17 -lstdc++ -pedantic -Wall -Werror -Wextra
TEST_FLAGS = -lgtest
MODEL_FILES = $(wildcard Model/*.cc)
CONTROLLER_FILES = $(wildcard Controller/*.cc)
TEST_FILES = $(wildcard Tests/*.cc)

all:
	$(MAKE) clean
	$(MAKE) install

install:
	mkdir 3DViewer
	cd 3DViewer && cmake ..
	cd 3DViewer && make

uninstall:
	rm -rf 3DViewer

launch:
	open 3DViewer/3DViewer.app

dvi:
	open documentation.md

dist:
	 tar -cf 3DViewer.tar 3DViewer

build_test:
	cd Tests && mkdir -p build
	cd Tests/build && cmake -DCMAKE_BUILD_TYPE=Debug ..
	cd Tests/build && make

test: build_test
	cd Tests/build && ctest -VV

gcov_report:
	$(CC) $(CFLAGS) $(TEST_FILES) $(MODEL_FILES) -coverage $(TEST_FLAGS) -o gcovreport
	./gcovreport
	lcov -t "gcovreport" -o gcovreport.info -c -d .
	genhtml -o report gcovreport.info
	rm -rf *.a *.info *.gcda *.gcno gcovreport

style:
	 clang-format -style=Google -i Model/*.cc Model/*.h Model/QtGifImage/gifimage/*.cpp \
 Model/QtGifImage/gifimage/*.h Model/QtGifImage/giflib/*.c Model/QtGifImage/giflib/*.h View/*.cc View/MainWindow/*.cc \
 View/MainWindow/*.h Controller/*.cc Controller/*.h Tests/*.cc

clean:
	 rm -rf 3DViewer
	 rm -rf Tests/build