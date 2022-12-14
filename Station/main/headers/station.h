#ifndef STATION_H 
#define STATION_H

#include "repairBay.h"
#include "ships.h"

#include <array>
#include <queue>

const int NUM_OF_REPAIR_BAYS = 3;

/**
 * Station class.
 * 
 * Responsible for managing a collection of repair bays and wait line to the bays.
 */
class Station 
{
    public:
        using bayCollection = std::array<RepairBay, NUM_OF_REPAIR_BAYS>;
        using lineCollection = std::queue<Ship*>;

        /**
         * Default constructor for Station.
         */
        Station();

        /**
         * Non-Default constructor for Station.
         * 
         * @param string = sets the identification of this Station.
         */
        Station(std::string);

        /**
         * Returns station id.
         * 
         * @return string representation of identification. 
         */
        std::string StationID() const {
            return this->stationID;
        }

        /**
         * Get the repair bays.
         */
        bayCollection Bays() const {
            return this->bays;
        }

        /**
         * Runs through all the bays and handles one time cycle worth of repairs if needed.
         */
        void RepairTimeStep();

        /**
         * Add ship to the appropriate state (bay or queue).
         */
        void AddShip(Ship*);

        /**
         * Return the queue of ships to the user.
         * 
         * @return queue of ship pointers.  
         */
        lineCollection WaitLine() const {
            return this->waitLine;
        }

        /**
         * Create a string report of the Station's status.
         */
        std::string toString() const;

    private: 
        /**
         * String representation of a Station object's identification. 
         */
        std::string stationID;
        
        /**
         * Collection of repair bays.
         * Number is determined by the constant supplied.
         */
        bayCollection bays;

        /**
         * Queue of ship pointers.
         * Occupants are added whenever a bay is unavailable.
         * Occupant is freed when a bay is made available.
         */
        lineCollection waitLine;

        /**
         * Sets the station id.
         * 
         * @param string representation of identification.
         */
        void StationID(std::string sid) {
            this->stationID = sid;
        }

        /** 
         * Set the repair bays.
         * 
         * @param RepairBays are the bays to be added to a Station's collection.
         */
        void Bays(RepairBay a, RepairBay b, RepairBay c) {
            this->bays[0] = a;
            this->bays[1] = b; 
            this->bays[2] = c;
        }

        /**
         * Attempt to add the ship to the bay.
         * 
         * @return true if ship was added.
         * @return false if the ship was not added.
         */
        bool AddShipToBay(Ship*);

        /**
         * Add a ship to this wait line.
         * 
         * @param sp a ship pointer to be added. 
         */
        void AddShipToQueue(Ship* sp) {
            this->waitLine.push(sp);
        }

        /**
         * Remove the ship from the top of the queue.
         */
        void RemoveShipFromQueue() {
            this->waitLine.pop();
        }
};

#endif 