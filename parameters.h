/*
 * Definitions of model parameters that are not configurable at the run time.
 */

#ifndef PARAMETERS_H
#define PARAMETERS_H

#include "clock.h"

constexpr Duration MINING_TIME_MIN = Clock::hours(1);
constexpr Duration MINING_TIME_MAX = Clock::hours(5);
constexpr Duration TRAVEL_TO_MINE = Clock::minutes(30);
constexpr Duration TRAVEL_TO_STATION = Clock::minutes(30);
constexpr Duration UNLOAD_TIME = Clock::minutes(5);

constexpr Duration SIMULATION_TIME = Clock::hours(72);

#endif // PARAMETERS_H
