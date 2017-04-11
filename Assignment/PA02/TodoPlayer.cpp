/*
 * This should contain the implementation of the class of TodoPlayerModel.
 */

//You need to submit this file
//You need to modify this file

#include "TodoPlayer.h"

//your code goes here

/**
	 * Constructor
	 * @param name: name of the player
	 * @param cash: cash to start with
	 * @param color: the color of the player
	 */
    TodoPlayerModel::TodoPlayerModel(string name, int cash, Color color) : PlayerModel(name, cash, color), restaurantCount(0){

    }

    /**
     * Destructor
     */
    TodoPlayerModel::~TodoPlayerModel(){
    	delete [] properties;
    }

//    /**
//     * Getter function of position.
//     * @return position on the chess board.
//     */
//    int TodoPlayerModel::getPosition() const{
//    	return position;
//    }
//
//    /**
//     * Getter function of cash.
//     * @return cash that a player is owning.
//     */
//    int TodoPlayerModel::getCash() const{
//    	return cash;
//    }
//
//    /**
//     * Getter function of the propertyCount.
//     * @return the number of property a player is having.
//     */
//    int TodoPlayerModel::getPropertyCount() const{
//    	return propertyCount;
//    }

    /**
	* The player gains a restaurant.
	*/
	void TodoPlayerModel::gainRestaurant(){
		restaurantCount += 1;
	}

    /**
	* Getter function of the propertyCount.
    * @return the number of restaurant a player is having.
	*/
	int TodoPlayerModel::getRestaurantCount() const{
		return restaurantCount;
	}

//
//    /**
//     * Getter function of the color.
//     * @return the color of the player.
//     */
//    Color TodoPlayerModel::getColor() const{
//    	return color;
//    }
//
//    /**
//     * Getter function of the name.
//     * @return the name of the player.
//     */
//    string TodoPlayerModel::getName() const{
//    	return name;
//    }
//
//    /**
//     * The player collect m dollars.
//     * @param m: dollars collected by the player.
//     */
//    void TodoPlayerModel::collect(int m){
//    	cash += m;
//    }
//
//    /**
//     * The player pay m dollars.
//     * @param m: dollars paid by the player.
//     */
//    void TodoPlayerModel::pay(int m){
//    	cash -= m;
//    }
//
//    /**
//     * The player move a number of steps on the board.
//     * @param step: Number of cells the player moves on the board
//     */
//    void TodoPlayerModel::move(int step){
//    	position = (position + step) % BOARD_SIZE;
//    }

    /**
     * The player gains a property which is modeled by the class TodoPropertyModel.
     * @param pm: The property that the player is gaining.
     */
    void TodoPlayerModel::gainProperty(PropertyModel* pm){
    	if(propertyCount == 0){
    		properties = new PropertyModel*[propertyCount+1];
    		properties[propertyCount] = pm;
    		propertyCount++;
    		this->pay(pm->getRate());
    	}else{
    		PropertyModel* backup[propertyCount];
    		for(int i = 0; i < propertyCount; i++){
    			backup[i] = properties[i];
    		}
    		delete []properties;
    		properties = new PropertyModel*[++propertyCount];
    		for(int j = 0; j < propertyCount; j++){
    			properties[j] = backup[j];
    		}
    		properties[propertyCount-1] = pm;
    		this->pay(pm->getRate());
    	}

    	return;
    }

    /**
     * To check if a property is owned by a player.
     * @param pm: Check the property pm is owned by a player.
     * @return: True if the property is owned by the player.
     */
    bool TodoPlayerModel::isOwning(PropertyModel* pm) const{
    	if(pm->getOwner()->getName() == this->name){
    		return true;
    	}else{
    		return false;
    	}
    }

//    /**
//     * It returns the list of the properties owned by the player.
//     * @return: A list of const addresses of const propertyModel.
//     */
//    const PropertyModel * const * TodoPlayerModel::getProperties() const{
//    	return properties;
//    }
