/**
 * @file BusType.h
 * @brief Enum for defining different types of buses in the power system.
 * 
 * This enum class represents different types of buses used in power system studies,
 * including slack, PV, and PQ buses.
 * 
 * Author: Subhendu Mishra
 * License: GPL
 */

#ifndef BUSTYPE_H
#define BUSTYPE_H

enum class BusType {
    SLACK, ///< Slack bus (reference bus)
    PV,    ///< PV bus (generator bus with voltage control)
    PQ     ///< PQ bus (load bus)
};

#endif // BUSTYPE_H
