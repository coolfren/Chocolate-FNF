#include "core/Paths.hpp"

const char* getImage(const char* name, FileType filetype){ // originally was going to be constexpr but oh wellllll
    std::string* _path = new std::string(basePath);
    _path->append("images/").append(name);
    switch(filetype)
    {
        case FileType::JPG:
            _path->append(".jpg");
            break;
        case FileType::BMP:
            _path->append(".bmp");
            break;
        case FileType::PNG:
            _path->append(".png");
            break;
        case FileType::TTF:
            _path->append(".ttf");
            break;
    }
    return _path->c_str();
}

const char* getImage(const char* name){ // overloading so it automatically assumes PNG
    std::string* _path = new std::string(basePath); // lol goodbye memory management
    return _path->append("images/").append(name).append(".png").c_str();
}

const char* getFont(const char* name){
    std::string* _path = new std::string(basePath);
    return _path->append("fonts/").append(name).append(".ttf").c_str();
}