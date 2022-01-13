#pragma once

#include <string>
#include <fstream>
#include <vector>
#include "project_classes/Coin.hpp"
#include "project_classes/Cell.hpp"
#include "project_classes/Player.hpp"
#include "project_classes/Arrival.hpp"
#include "project_classes/Ground.hpp"
#include "project_classes/Gap.hpp"
#include "project_classes/Block.hpp"
#include "project_classes/Skblock.hpp"


/// \class Level
/// \brief Class that defines a Level
class Level {

private:
    int _sizeX; /*!< Size x */
    int _sizeY; /*!< Size y */
    int _sizeZ;  /*!< Size z */

    Player _mainCharacter; /*!< Main character of the level */
    std::vector<Cell*> _cells; /*!< Vertor of cells */
    std::vector<Coin*> _coins; /*!< Vertor of coins */
    std::vector<Block*> _blocks; /*!< Vector of blocks */
    std::vector<Skblock*> _skyblock; /*!< Vector of skyblock */
    std::vector<Arrival*> _arrivals; /*!< Vector of arrivals */
    std::vector<Cell*> _leftTurns; /*!< Vector of leftTurns */
    std::vector<Cell*> _rightTurns; /*!< Vector of rightTurns */
    std::string _sourceFile; /*!< Source of the file level */

public:
    /// \brief Constructor
    /// \param Source string of the file level
    Level(std::string sourceFile);

    /// \brief Default constructor
    Level();

    /// \brief Destructor
    ~Level();

    /// \brief Get the X size
    /// \return Integer size
    int getSizeX() const;

    /// \brief Get the Y size
    /// \return Integer size
    int getSizeY() const;

    /// \brief Get the Z size
    /// \return Integer size
    int getSizeZ() const;

    /// \brief Get the player
    /// \return Player informations
    Player getPlayer() const;

    /// \brief Get cells
    /// \return Vectors of cells
    std::vector<Cell*> getCells() const;

    /// \brief Get coin
    /// \return Vectors of coin
    std::vector<Coin*> getCoins() const;

    /// \brief Get blocks
    /// \return Vectors of blocks
    std::vector<Block*> getBlocks() const;

    /// \brief Get skyblock
    /// \return Vectors of skyblock
    std::vector<Skblock*> getSkyblock() const;

    /// \brief Get arrivals
    /// \return Vectors of arrivals
    std::vector<Arrival*> getArrivals() const;

    /// \brief Get leftTurns
    /// \return Vectors of leftTurns
    std::vector<Cell*> getLeftTurns() const;

    /// \brief Get rightTurns
    /// \return Vectors of rightTurns
    std::vector<Cell*> getRightTurns() const;

    /// \brief Get file source of a level
    /// \return Source string of the file level
    std::string getSourceFile() const;

    /// \brief Set the X size
    /// \param Takes an integer n
    void setSizeX(const int n);

    /// \brief Set the Y size
    /// \param Takes an integer n
    void setSizeY(const int n);

    /// \brief Set the Z size
    /// \param Takes an integer n
    void setSizeZ(const int n);

    /// \brief Set a player
    /// \param Player
    void setPlayer(const Player &player);

    /// \brief Set cells
    /// \param Vectors of cells
    void setCells(const std::vector<Cell*> &cells);

     /// \brief Set coins
    /// \param Vectors of coins
    void setCoins(const std::vector<Coin*> &coins);

    /// \brief Set blocks
    /// \param Vectors of blocks
    void setBlocks(const std::vector<Block*> &blocks);

    /// \brief Set skyblock
    /// \param Vectors of skyblock
    void setSkyblock(const std::vector<Skblock*> &skyblock);

    /// \brief Set arrivals
    /// \param Vectors of arrivals
    void setArrivals(const std::vector<Arrival*> &arrivals);

    /// \brief Set leftTurns
    /// \return Vectors of leftTurns
    void setLeftTurns(const std::vector<Cell*> &leftTurns);

    /// \brief Set rightTurns
    /// \return Vectors of rightTurns
    void setRightTurns(const std::vector<Cell*> &rightTurns);

    /// \brief Set file source of the level
    /// \param Source string of the file level
    void setSourceFile(const std::string &sourceFile);
};