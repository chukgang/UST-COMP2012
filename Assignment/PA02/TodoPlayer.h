/*
 * This should contain the class of TodoPlayerModel.
 */

//You need to submit this file
//You need to modify this file

#ifndef TODOPLAYER_H_
#define TODOPLAYER_H_

//your code goes here



#include <string>
#include "Player.h"
#include "TodoProperty.h"
#include "param.h"
using namespace std;

/**
 *  This model class simulates a player in the game. A player has its name, cash, a set of properties,
 *  color, position on the board.
 */
class TodoPlayerModel : public PlayerModel{

public:
	/**
	 * Constructor
	 *
	 * @param name: name of the player
	 * @param cash: cash to start with
	 * @param color: the color of the player
	 */
	TodoPlayerModel(string name, int cash, Color color);

    /**
     * Destructor
     */
    virtual ~TodoPlayerModel();

//    /**
//     * Getter function of position.
//     *
//     * @return position on the chess board.
//     */
//    int getPosition() const;
//
//    /**
//     * Getter function of cash.
//     *
//     * @return cash that a player is owning.
//     */
//    int getCash() const;
//
//    /**
//     * Getter function of the propertyCount.
//     * @return the number of property a player is having.
//     */
//    int getPropertyCount() const;

    /**
     * Getter function of the restaurantCount.
     * @return the number of restaurant a player is having.
     */
    void gainRestaurant();

    /**
	* Getter function of the propertyCount.
    * @return the number of restaurant a player is having.
	*/
    int getRestaurantCount() const;

//    /**
//     * Getter function of the color.
//     *
//     * @return the color of the player.
//     */
//    Color getColor() const;
//
//    /**
//     * Getter function of the name.
//     *
//     * @return the name of the player.
//     */
//    string getName() const;
//
//    /**
//     * The player collect m dollars.
//     *
//     * @param m: dollars collected by the player.
//     */
//    void collect(int m);
//
//    /**
//     * The player pay m dollars.
//     *
//     * @param m: dollars paid by the player.
//     */
//    void pay(int m);
//
//    /**
//     * The player move a number of steps on the board.
//     *
//     * @param step: Number of cells the player moves on the board
//     */
//    void move(int step);

    /**
     * The player gains a property which is modeled by the class PropertyModel.
     *
     * @param pm: The property that the player is gaining. But in this demo program it does nothing.
     */
    virtual void gainProperty(PropertyModel* pm);

    /**
     * To check if a property is owned by a player.
     *
     * @param pm: Check the property pm is owned by a player. But in this demo it always says false.
     * @return: True if the property is owned by the player. But in this demo it always return  false.
     *
     */
    virtual bool isOwning(PropertyModel* pm) const;

//    /**
//     * It returns the list of the properties owned by the player.
//     *
//     * @return: A list of const addresses of const propertyModel.
//     */
//    const PropertyModel * const * getProperties() const;


protected:
//
//    /**
//     * The position of the board that the player is currently visiting.
//     */
//    int position;
//
//    /**
//     * A list of properties that the player is having.
//     */
//    PropertyModel** properties;
//
//    /**
//     * The number of properties that the player is having.
//     */
//    int propertyCount;

    /**
     * The number of restaurants that the player is having.
     */
    int restaurantCount;

};

#endif /* TODOPLAYER_H_ */
