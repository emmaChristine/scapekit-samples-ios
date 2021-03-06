// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from ar.djinni

#import "SCKArFrame.h"
#import "SCKArPlane.h"
#import "SCKArTrackingState.h"
#import <Foundation/Foundation.h>
@protocol SCKArSession;


/** (public) */
@protocol SCKArSessionObserver

- (void)onPlaneDetected:(nullable id<SCKArSession>)session
                  plane:(nonnull SCKArPlane *)plane;

- (void)onPlaneUpdated:(nullable id<SCKArSession>)session
                 plane:(nonnull SCKArPlane *)plane;

- (void)onPlaneRemoved:(nullable id<SCKArSession>)session
                 plane:(nonnull SCKArPlane *)plane;

- (void)onTrackingStateUpdated:(nullable id<SCKArSession>)session
                         state:(SCKArTrackingState)state;

- (void)onFrameUpdated:(nullable id<SCKArSession>)session
                 frame:(nonnull SCKArFrame *)frame;

@end
