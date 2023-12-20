#ifndef SEARCH_H_
#define SEARCH_H_

#include <cstring>
#include <iostream>
#include <iomanip>
#include <filesystem>
#include <unistd.h>
#include <chrono> 
#include <iomanip>
#include <sys/stat.h>

namespace fs = std::filesystem;

void printTree(const fs::path& path, int level = 0);

#endif