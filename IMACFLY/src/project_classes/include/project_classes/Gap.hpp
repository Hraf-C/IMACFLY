#pragma once
#include "Cell.hpp"

/// \class Gap
/// \brief Class that defines a Gap
class Gap : public Cell {

public:

    //// \brief Constructor
    /// \param type : type to define a gap -> 'g'
    /// \param width : width of the requested gap
    /// \param height : height of the requested gap
    /// \param posX : X position of a gap
    /// \param posY : Y position of a gap
    /// \param posZ : Z position of a gap
    Gap(const char type, const float width, const float height, const float posX, const float posY, const float posZ);
    
    /// \brief Default constructor
    Gap();

    /// \brief Destructor
    ~Gap();
};