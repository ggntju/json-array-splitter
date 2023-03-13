#ifndef UTIL_H
#define UTIL_H
#pragma once

#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <string>
#include <filesystem>
#include <memory>
#include <sstream>

#define OK 0
#define NG -1

namespace util{
    inline int exec(std::string command) {
        char buffer[4096];
        std::string result = "";

        // Open pipe to file
        FILE* pipe = popen(command.c_str(), "r");
        if (!pipe) {
            return NG;
        }

        // read till end of process:
        while (!feof(pipe)) {
            // use buffer to read and add to result
            if (fgets(buffer, 128, pipe) != NULL)
                result += buffer;
        }

        pclose(pipe);
        return OK;
    }

    inline bool file_exists(std::string path) {
        std::filesystem::path f{path.c_str()};
        if (std::filesystem::exists(f)) {
            return true;
        } else {
            return false;
        }
    }

    inline std::string read_file(std::string path) {
        std::shared_ptr<std::ifstream> t(new std::ifstream(path));
        std::shared_ptr<std::stringstream> buffer(new std::stringstream());
        *buffer << t->rdbuf();
        return buffer->str();
    }

    inline void write_file(std::string path, std::string contents) {
        std::shared_ptr<std::ofstream> o(new std::ofstream(path, std::ios::out | std::ios::trunc));
        *o << contents << std::endl;
        o->close();
        o.reset();
    }

    inline bool is_part_file(std::filesystem::path path) {
        if(path.string().find("part_") != std::string::npos) {
            return true;
        } else {
            return false;
        }
    }

    inline bool is_first_part(std::filesystem::path path) {
        if(path.string().find("part_000") != std::string::npos) {
            return true;
        } else {
            return false;
        }
    }

    inline bool is_last_part(std::filesystem::path path, int part_count) {
        if(part_count < 1) {
            return false;
        }
        if(part_count >= 1 && part_count <= 10) {
            std::string part_name = "part_00" + std::to_string(part_count - 1);
            if(path.string().find(part_name) != std::string::npos) {
                return true;
            } else {
                return false;
            }
        }
        if(part_count > 10 && part_count <= 100) {
            std::string part_name = "part_0" + std::to_string(part_count - 1);
            if(path.string().find(part_name) != std::string::npos) {
                return true;
            } else {
                return false;
            }
        }
        if(part_count > 100 && part_count <= 1000) {
            std::string part_name = "part_" + std::to_string(part_count - 1);
            if(path.string().find(part_name) != std::string::npos) {
                return true;
            } else {
                return false;
            }
        }
        if(part_count > 1000) {
            return false;
        }
        return false;
    } 
}


#endif