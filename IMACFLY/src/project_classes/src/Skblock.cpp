#include "project_classes/Skblock.hpp"

//constructor
Skblock::Skblock(const char type, const float width, const float height, const float posX, const float posY, const float posZ)
: Cell(type, width, height, posX, posY, posZ) {}

Skblock::Skblock(){}

//destructor
Skblock::~Skblock(){}