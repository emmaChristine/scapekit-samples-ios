// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from scape.djinni

#import <Foundation/Foundation.h>

/**
 * (public)
 * Current session state
 */
typedef NS_ENUM(NSInteger, SCKScapeSessionState)
{
    /** No current error to report */
    SCKScapeSessionStateNoError,
    /** Locations sensors (compass, gps) error  */
    SCKScapeSessionStateLocationSensorsError,
    /** Motion sensors (gyro, magnetometer) error */
    SCKScapeSessionStateMotionSensorsError,
    /** Scape Vision Engine error */
    SCKScapeSessionStateVisionEngineError,
    /** Authentication error */
    SCKScapeSessionStateAuthenticationError,
    /** Fetching measurements resulted in an unexpected error */
    SCKScapeSessionStateUnexpectedError,
};
