#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "DatalogProgram.h"

using namespace std;

int main(int argc, char** argv) {
  //check commandline arguments

    if (argc != 2) {
        std::cout << "usage: " << argv[0] << " input_file" << endl;
        return 1;
    }

    // open file
    string fileName = argv[1];
    ifstream input(fileName);
    if (!input.is_open()) {
        cout << "File " << fileName << " could not be found or opened." << endl;
        return 1;
    }


    DatalogProgram* dataLog = new DatalogProgram();
    string output( (std::istreambuf_iterator<char>(input)),(std::istreambuf_iterator<char>()));
    try{
        dataLog->process(output);
        cout << dataLog->toString() << endl;
    } catch (std::string e) {
        cout << e << endl;
        return 0;
    }

    delete dataLog;

    return 0;
}