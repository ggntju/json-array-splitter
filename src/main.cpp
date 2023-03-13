#include "main.h"

int main(int argc, char *argv[]) {
    if(argc <= 2) {
        std::cerr << "Missing Input Location / Lines per File" << std::endl;
        std::cerr << "Usage: ./JSON-ARRAY-SPLITTER [file_path] [lines_per_file]" << std::endl;
        return -1;
    } else if(argc == 3) {
        std::string file_path = std::string(argv[1]);
        std::cout << "Start Processing: " << file_path << std::endl;
        if(!util::file_exists(file_path)) {
            std::cerr << "File Does not Exist" << std::endl;
            return -1;
        }
        int lines_per_file = std::stoi(std::string(argv[2]));
        printf("Each File Contains %d Lines of Data\n", lines_per_file);
        std::string command = "split -l " + std::to_string(lines_per_file) + " -a 3 -d " + file_path + " part_";
        if(OK == util::exec(command)) {
            std::cout << "Splitting is Finished" << std::endl;
        }
        int part_file_count = 0;
        for (auto const& dir_entry : std::filesystem::directory_iterator{std::filesystem::current_path()}) {
            if(util::is_part_file(dir_entry.path())) {
                part_file_count++;
            }
        }
        if(part_file_count == 0 || part_file_count > 1000) {
            std::cerr << "Invalid Part File, Please Check" << std::endl;
            return -1;
        }
        printf("Part Files Count: %d \n", part_file_count);
        for (auto const& dir_entry : std::filesystem::directory_iterator{std::filesystem::current_path()}) {
            if(util::is_part_file(dir_entry.path())) {
                if(util::is_first_part(dir_entry.path())) {
                    util::process_first_part(dir_entry.path());
                    continue;
                }
                if(util::is_last_part(dir_entry.path(), part_file_count)) {
                    util::process_last_part(dir_entry.path());
                    continue;
                }
                util::process_middle_part(dir_entry.path());
            }
        }
        printf("Processing for %s is Finished \n", file_path.c_str());
        return 0;
    } else {
        std::cerr << "Too Many Arguments" << std::endl;
        return -1;
    }
    return 0;
}