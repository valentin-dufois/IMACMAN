#ifndef GHOST_HPP
#define GHOST_HPP

#include <iostream>
#include <glm/glm.hpp>

class Ghost {
    private:
    std::string m_name;
    uint m_id;
    glm::vec2 m_position;
    bool m_isAlive;
    bool m_isAfraid;

    public:

};

#endif /* GHOST_HPP */