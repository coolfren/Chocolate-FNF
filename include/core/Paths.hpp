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

/**
 * @brief Get the Image object
 * @todo make this work cross platform
 * @param name name of the image
 * @param filetype the filetype of the image
 * @return const char* 
 */
const char* getImage(const char* name, FileType filetype);
const char* getImage(const char* name);

const char* getXML(const char* name);

const char* getFont(const char* name);

std::string* getSound(const char* name, bool music);