#ifndef RESTAURANT_MANAGER_H
#define RESTAURANT_MANAGER_H
#include <iostream>
#include <string>
#include <vector>
#include "../models/Restaurant.h"
#include <algorithm>

using namespace std;

class RestaurantManager{
    private:
        vector<Restaurant*>restaurants;
        static RestaurantManager* instance;
        RestaurantManager()
        {
            //private constructor
        }
    public:
        static RestaurantManager* getInstance(){
            if(instance==NULL)
            {
                instance = new RestaurantManager();
            }
            return instance;
        }
        void addRestaurant(Restaurant* r){
            restaurants.push_back(r);
        }
        vector<Restaurant*> searchByLocation(string loc)
        {
            vector<Restaurant*> result;
            transform(loc.begin(), loc.end(), loc.begin(), ::tolower);
            for(auto r: restaurants)
            {
                string restaurantLocation = r->getLocation();
                transform(restaurantLocation.begin(), restaurantLocation.end(), restaurantLocation.begin(), ::tolower);
                if(restaurantLocation==loc){
                    result.push_back(r);
                }
            }
            return result;
        }
};
RestaurantManager* RestaurantManager::instance = NULL;
#endif