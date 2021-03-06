// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from scape.djinni

#import <Foundation/Foundation.h>

/**
 * (public)
 * The Scape Vision Engine measurements status
 */
typedef NS_ENUM(NSInteger, SCKScapeMeasurementsStatus)
{
    /** Current area may exist within Scape Vision Engine but no results could be found */
    SCKScapeMeasurementsStatusNoResults,
    /** Current area does not exist within Scape Vision Engine */
    SCKScapeMeasurementsStatusUnavailableArea,
    /** Current area exists within Scape Vision Engine and results were found */
    SCKScapeMeasurementsStatusResultsFound,
    /** Internal error */
    SCKScapeMeasurementsStatusInternalError,
};
