#ifndef COPY_H_
#define COPY_H_

#include <iostream>
#include <filesystem>
#include <filesystem>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include <utime.h>
#include <sys/time.h>
#include <fstream>
#include <ostream>

namespace fs = std::filesystem;

void copy_directory(const fs::path& source, const fs::path& destination);
bool copyMetadata_exclu_slink(const char* sourcePath, const char* destinationPath);
bool copyMetadata_slink(const char* sourcePath, const char* destinationPath);

#endif