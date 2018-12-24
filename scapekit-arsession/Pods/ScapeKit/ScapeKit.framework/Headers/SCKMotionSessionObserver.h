// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from motion.djinni

#import "SCKMotionSessionDetails.h"
#import <Foundation/Foundation.h>
@protocol SCKMotionSession;


/** public interface */
@protocol SCKMotionSessionObserver

- (void)onMotionSessionStarted:(nullable id<SCKMotionSession>)session
                       details:(nonnull SCKMotionSessionDetails *)details;

- (void)onMotionSessionError:(nullable id<SCKMotionSession>)session
                     details:(nonnull SCKMotionSessionDetails *)details;

- (void)onMotionSessionClosed:(nullable id<SCKMotionSession>)session
                      details:(nonnull SCKMotionSessionDetails *)details;

- (void)onMotionRawEstimated:(nullable id<SCKMotionSession>)session
                     details:(nonnull SCKMotionSessionDetails *)details;

@end