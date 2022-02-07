#pragma once
#include "engine/Common.hpp"

namespace Containers
{
    class Group : public Engine::Basic
    {
        public:
        std::vector<Basic*> objects;
        Group();
        ~Group();
        void update();
        void add(Basic* object);
        void remove(Basic* object);
    };
} // namespace containers