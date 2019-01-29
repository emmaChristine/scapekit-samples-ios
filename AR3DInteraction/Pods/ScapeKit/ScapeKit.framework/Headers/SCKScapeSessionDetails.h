// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from scape.djinni

#import "SCKGeoPose.h"
#import "SCKScapeSessionState.h"
#import <Foundation/Foundation.h>

/**
 * public
 * Session details object representing the GeoPose request result as well as the current state of the session
 */
@interface SCKScapeSessionDetails : NSObject
- (nonnull instancetype)initWithTimestamp:(double)timestamp
                             currentState:(SCKScapeSessionState)currentState
                             errorMessage:(nonnull NSString *)errorMessage
                                  geoPose:(nonnull SCKGeoPose *)geoPose;
+ (nonnull instancetype)scapeSessionDetailsWithTimestamp:(double)timestamp
                                            currentState:(SCKScapeSessionState)currentState
                                            errorMessage:(nonnull NSString *)errorMessage
                                                 geoPose:(nonnull SCKGeoPose *)geoPose;

/** Used to identify in a unique manner the current GeoPose request */
@property (nonatomic, readonly) double timestamp;

/** Current session state */
@property (nonatomic, readonly) SCKScapeSessionState currentState;

/** Error message for the current session  */
@property (nonatomic, readonly, nonnull) NSString * errorMessage;

/** Current geo pose */
@property (nonatomic, readonly, nonnull) SCKGeoPose * geoPose;

@end