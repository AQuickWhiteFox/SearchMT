CXX=clang++

all: search

search: ./src/Main.cpp
	mkdir -p ./bin
	$(CXX) -std=c++11 $^ -o ./bin/$@

clean:
	rm -rf ./bin