#pragma once
#include "engine/Common.hpp"

namespace Containers
{
    class Group : public Engine::Basic
    {
        public:
        std::vector<Basic*> objects;
        Group();
        virtual ~Group();
        void update();
        void add(Basic* object);
        void remove(Basic* object);
        void remove(int index);
        int size();
        inline Engine::Basic* &operator[](int index);
    };
} // namespace containers