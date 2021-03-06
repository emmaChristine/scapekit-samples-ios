// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from scape.djinni

#import "SCKGeoSourceType.h"
#import "SCKScapeSessionDetails.h"
#import <Foundation/Foundation.h>
@class SCKScapeSession;
@protocol SCKArSession;
@protocol SCKLocationSession;
@protocol SCKMotionSession;
@protocol SCKScapeSessionObserver;
@protocol SCKVideoFrame;


/**
 * public
 * ScapeKit's main service: gets GeoPose based on the raw device's built-in sensors as well as the camera
 */
@interface SCKScapeSession : NSObject

/**
 * internal
 * Create the GeoPose service
 */
+ (nullable SCKScapeSession *)create;

/**
 * internal
 * Needed for all GPS and Compass related features
 */
- (nullable SCKScapeSession *)withLocationSession:(nullable id<SCKLocationSession>)locationSession;

/**
 * internal
 * Needed for all Gyroscope/Accelerometer related features
 */
- (nullable SCKScapeSession *)withMotionSession:(nullable id<SCKMotionSession>)motionSession;

/**
 * internal
 * Needed for all AR related features (camera frame, camera transform, camera intrinsics)
 */
- (nullable SCKScapeSession *)withArSession:(nullable id<SCKArSession>)arSession;

/**
 * public
 * Start GeoPose fetching at continuous interval
 * Need to specify the @param type to determine if we only want to get a device's sensors-based GeoPose (gyroscope, accelerometer, gps, magnetometer) 
 * or if we want to combine those sensors with Scape Vision Engine to get a hyper-accurate GeoPose 
 */
- (void)startFetch:(SCKGeoSourceType)type;

/**
 * public
 * Stop GeoPose fetching
 */
- (void)stopFetch;

/**
 * public
 * Attempt to get the current GeoPose asynchronously
 * Need to specify the @param type to determine if we only want to get a device's sensors-based GeoPose (gyroscope, accelerometer, gps, magnetometer) 
 * or if we want to combine those sensors with Scape Vision Engine to get a hyper-accurate GeoPose 
 */
- (void)getCurrentGeoPose:(SCKGeoSourceType)type;

/**
 * public
 * Attempt to get the last known GeoPose synchronously
 */
- (nonnull SCKScapeSessionDetails *)getLastGeoPose;

/**
 * public
 * Retrieve the current callback observer for the current session
 */
- (nullable id<SCKScapeSessionObserver>)getScapeSessionObserver;

/**
 * public
 * Set the camera frame manually (when ArSession is not used)
 */
- (void)setRawFrame:(nullable id<SCKVideoFrame>)frame;

/**
 * public
 * Set the Y channel manually (when ArSession is not used)
 */
- (void)setYChannelPtr:(int64_t)pointer
                 width:(int32_t)width
                height:(int32_t)height;

/**
 * public
 * Set the camera intrinsics manually (when ArSession is not used)
 */
- (void)setCameraIntrinsics:(double)xFocalLength
               yFocalLength:(double)yFocalLength
            xPrincipalPoint:(double)xPrincipalPoint
            yPrincipalPoint:(double)yPrincipalPoint;

/**
 * public
 * Set camera transform manually (when ArSession is not used)
 */
- (void)setCameraTransform:(nonnull NSArray<NSNumber *> *)transform;

/**
 * public
 * Set the current callback observer for the current session
 */
- (void)setScapeSessionObserver:(nullable id<SCKScapeSessionObserver>)observer;

@end
