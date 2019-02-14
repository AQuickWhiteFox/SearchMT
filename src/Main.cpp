/**
 * Copyright 2019 Aditya Atluri
 * See LICENSE for copyright
 */

#include <fstream>
#include <iostream>
// to store file names
#include <list>
// used to store list of line numbers from corresponding files
#include <unordered_map>

inline void Usage() {
    std::cout << "Usage: ./a.out <key> <file-name-1> <file-name-2> ... "
              << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        Usage();
        return 0;
    }

    unsigned long key = std::stol(argv[1]);

    std::list<std::string> lFileNames;

    //! Get file names
    for (int i = 2; i < argc; i++) {
        lFileNames.push_back(argv[i]);
    }

    //! used to store line numbers of keys found in files
    //! key: file name, value: list of line numbers containing users key
    std::unordered_map<std::string, std::list<unsigned long>> indices;

    typedef std::list<std::string>::iterator fileNameIterator;

    //! open each file
    for (fileNameIterator fileName = lFileNames.begin();
         fileName != lFileNames.end(); fileName++) {
        std::list<unsigned long> index;
        std::ifstream file(*fileName);

        std::string line;

        unsigned long lineNumber = 1;

        //! get each line from current file
        while (getline(file, line)) {
            //! check if the number in the line is equal to users key. If yes,
            //! add line number to list of indices
            if (std::stol(line) == key) index.push_back(lineNumber);
            lineNumber++;
        }

        indices[*fileName] = index;
    }

    typedef std::unordered_map<std::string, std::list<unsigned long>>::iterator
        indexIterator;

    for (indexIterator index = indices.begin(); index != indices.end();
         index++) {
        std::cout << index->first << " " << index->second.size() << std::endl;
    }
}
