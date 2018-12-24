// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from location.djinni

#import "SCKLocationSessionDetails.h"
#import <Foundation/Foundation.h>
@protocol SCKLocationSession;


/** public interface */
@protocol SCKLocationSessionObserver

- (void)onLocationSessionStarted:(nullable id<SCKLocationSession>)session
                         details:(nonnull SCKLocationSessionDetails *)details;

- (void)onLocationSessionError:(nullable id<SCKLocationSession>)session
                       details:(nonnull SCKLocationSessionDetails *)details;

- (void)onLocationSessionClosed:(nullable id<SCKLocationSession>)session
                        details:(nonnull SCKLocationSessionDetails *)details;

- (void)onLocationRawEstimated:(nullable id<SCKLocationSession>)session
                       details:(nonnull SCKLocationSessionDetails *)details;

@end
