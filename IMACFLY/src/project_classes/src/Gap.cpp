#include "project_classes/Gap.hpp"

//constructor
Gap::Gap(const char type, const float width, const float height, const float posX, const float posY, const float posZ)
: Cell(type, width, height, posX, posY, posZ) {}

Gap::Gap(){}

//destructor
Gap::~Gap(){}