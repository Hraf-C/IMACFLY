#pragma once
#include "Cell.hpp"

// Doxygen menu
/// \version beta
/// \mainpage
/// \image html banner.png
/// \tableofcontents
/// \section instroduction_sec About 
/// IMACFLY By ACHRAF LEMGHARI -IMAC 2 -2022.
/// \section install_bigsec How to install
/// \subsection dependencies_sec Dependecies
/// \li C++
/// \li SDL
/// \li OpenGL 3
/// \li Doxygen
/// \subsection install_sec Install with cmake (Linux)
/// \li cd imacfly
/// \li mkdir build
/// \li cd build
/// \li cmake ..
/// \li (if you are in virtual machine) type : export MESA_GL_VERSION_OVERRIDE=3.3
/// \li make
/// \li make html (for documentation) 
/// \li The documentation is located in imacfly/build/doc/doc-doxygen/html/index.html


/// \class Skblock
/// \brief Class that defines an Skblock
class Skblock : public Cell {

public:

    /// \brief Constructor
	/// \param type : type to define the skyblock -> 'a'
	/// \param width : width of the requested skyblock
	/// \param height : height of the requested skyblock
	/// \param posX : X position of the skyblock
	/// \param posY : Y position of the skyblock
	/// \param posZ : Z position of the skyblock
    Skblock(const char type, const float width, const float height, const float posX, const float posY, const float posZ);

    /// \brief Default constructor
    Skblock();

    /// \brief Destructor
    ~Skblock();
};