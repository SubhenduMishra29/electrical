// dc_load_flow.h 
/**
 * Author: Subhendu Mishra
 * License: GPL
 */
#ifndef DC_LOAD_FLOW_H
#define DC_LOAD_FLOW_H

class PowerSystem;  // Forward declaration

class DCLoadFlow {
public:
    DCLoadFlow(); // Constructor

    void perform(PowerSystem& powerSystem);
    // Add more methods and members as needed
};

#endif // DC_LOAD_FLOW_H
