// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from scape.djinni

#import "SCKScapeSessionDetails.h"
#import <Foundation/Foundation.h>
@class SCKScapeSession;


/**
 * public
 * Observer for all scape session related callbacks
 */
@protocol SCKScapeSessionObserver

/** Called when startFetch is used */
- (void)onScapeSessionStarted:(nullable SCKScapeSession *)session
                      details:(nonnull SCKScapeSessionDetails *)details;

/** Called when stopFetch is used */
- (void)onScapeSessionError:(nullable SCKScapeSession *)session
                    details:(nonnull SCKScapeSessionDetails *)details;

/** Called whenever any kind of error happens during the session lifetime */
- (void)onScapeSessionClosed:(nullable SCKScapeSession *)session
                     details:(nonnull SCKScapeSessionDetails *)details;

/** Called when the call to getCurrentGeoPose succeeds */
- (void)onGeoPoseEstimated:(nullable SCKScapeSession *)session
                   details:(nonnull SCKScapeSessionDetails *)details;

@end
