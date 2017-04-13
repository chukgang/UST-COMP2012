/*
 * Player.h
 *
 *  Created on: Feb 27, 2017
 *      Author: kevinw
 *
 */

//You are not allowed to modify this file
//You are not required to submit this file


#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>
#include "Property.h"
#include "param.h"
using namespace std;

/**
 *  This model class simulates a player in the game. A player has its name, cash, a set of properties,
 *  color, position on the board.
 */
class PlayerModel {

public:
	/**
	 * Constructor
	 *
	 * @param name: name of the player
	 * @param cash: cash to start with
	 * @param color: the color of the player
	 */
    PlayerModel(string name, int cash, Color color) : name(name), cash(cash), color(color), position(0), properties(NULL), propertyCount(0) {}
    /**
     * Destructor
     */
    virtual ~PlayerModel() {delete [] properties;};
    /**
     * Getter function of position.
     *
     * @return position on the chess board.
     */
    int getPosition() const {return position;}
    /**
     * Getter function of cash.
     *
     * @return cash that a player is owning.
     */
    int getCash() const {return cash;}
    /**
     * Getter function of the propertyCount.
     *
     * @return the number of property a player is having.
     */
    int getPropertyCount() const {return propertyCount;}
    /**
     * Getter function of the color.
     *
     * @return the color of the player.
     */
    Color getColor() const {return color;}
    /**
     * Getter function of the name.
     *
     * @return the name of the player.
     */
    string getName() const {return name;}
    /**
     * The player collect m dollars.
     *
     * @param m: dollars collected by the player.
     */
    void collect(int m) {cash += m;}
    /**
     * The player pay m dollars.
     *
     * @param m: dollars paid by the player.
     */
    void pay(int m) {cash -= m;}
    /**
     * The player move a number of steps on the board.
     *
     * @param step: Number of cells the player moves on the board
     */
    void move(int step) {position = (position + step) % BOARD_SIZE;}
    /**
     * The player gains a property which is modeled by the class PropertyModel.
     *
     * @param pm: The property that the player is gaining. But in this demo program it does nothing.
     */
    virtual void gainProperty(PropertyModel* pm) { return; }
    /**
     * To check if a property is owned by a player.
     *
     * @param pm: Check the property pm is owned by a player. But in this demo it always says false.
     * @return: True if the property is owned by the player. But in this demo it always return  false.
     *
     */
    virtual bool isOwning(PropertyModel* pm) const {return false;};
    /**
     * It returns the list of the properties owned by the player.
     *
     * @return: A list of const addresses of const propertyModel.
     */
    const PropertyModel * const * getProperties() const {return properties;}
protected:
    /**
     * The name of a player. It is not supposed to be changed after the constructor.
     */
    const string name;
    /**
     * The color of a player. It is not supposed to be changed after the constructor.
     */
    const Color color;
    /**
     * The cash processed by the player.
     */
    int cash;
    /**
     * The position of the board that the player is currently visiting.
     */
    int position;
    /**
     * A list of properties that the player is having.
     */
    PropertyModel** properties;
    /**
     * The number of properties that the player is having. This should be the size of the array
     * properties.
     */
    int propertyCount;


};

#endif /* PLAYER_H_ */
