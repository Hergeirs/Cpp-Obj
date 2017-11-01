//  File:         SimConst.h
//  Objective:    Default values for burger bar simulation parameters
//  Date:         2007 / �rjan Sterner


const int COST_PER_CHAIR = 150;  // Daily cost for one chair
const int MIN_ARRIVAL_DELAY = 1; // Min time between two arrivals
const int MAX_ARRIVAL_DELAY = 4; // Max time between two arrivals
const int MIN_GRP_SIZE = 1;      // Min nr of persons for each arrival
const int MAX_GRP_SIZE = 10;     // Max nr of persons for each arrival
const int MIN_ORDER_WAIT = 1;    // Min wait time for ordering after arrival
const int MAX_ORDER_WAIT = 5;   // Max wait time for ordering after arrival
const int SEAT_SEARCH_TIME= 1;   // Time to search for chairs
const int MIN_SERVICE_WAIT = 1;  // Min time to service after ordering
const int MAX_SERVICE_WAIT = 5;  // Max time to service after ordering
const int MIN_EATING_TIME = 5;   // Min time to finish the meal after seated
const int MAX_EATING_TIME = 15;  // Max time to finish the meal after seated
const int BURGERS_PER_PERSON = 1; // Nr of burgers ordered by a person
const float PROFIT_PER_BURGER = 6;  // Profit for each sold burger

const int SIM_TIME = 480; // Duration of simulation
