#include "main.h"

int main(int argc, char *argv[]) {
    // std::cout << "Hello, World!" << std::endl;
    // std::cout << exec("ls") << std::endl;
    if(argc <= 1) {
        std::cerr << "Missing Input Location" << std::endl;
        return -1;
    } else if(argc == 2) {
        std::string file_path = std::string(argv[1]);
        std::cout << "Start Processing: " << file_path << std::endl;
    } else {
        std::cerr << "Too Many Arguments" << std::endl;
        return -1;
    }
    return 0;
}