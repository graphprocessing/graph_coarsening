// Copyright [year] <Copyright Owner>
#include "../../pch/include/precomp.h"

void get_temp_filename(char *buffer) {
    #ifndef _WIN32
    strncpy(buffer, "file_XXXXXX", 19);
    if (mkstemp(buffer) == -1)
        throw std::runtime_error("mkstemp failed");
    #else
    if (!tmpnam(buffer))
        throw std::runtime_error("tmpnam failed");
    #endif  // _WIN32
}
