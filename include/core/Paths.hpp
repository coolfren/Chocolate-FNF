#pragma once
#ifdef __SWITCH__
#define basePath ""
#else
#define basePath "romfs/"
#endif
#include "engine/Common.hpp"

enum class FileType
{
    JPG,
    BMP,
    PNG,
    TTF
};

const char* getImage(const char* name, FileType filetype);
const char* getImage(const char* name);

const char* getFont(const char* name);