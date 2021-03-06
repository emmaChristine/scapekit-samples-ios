// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from scape.djinni

#import "SCKCoordinates.h"
#import "SCKScapeOrientation.h"
#import <Foundation/Foundation.h>

@interface SCKGeoPose : NSObject
- (nonnull instancetype)initWithGpsCoordinates:(nonnull SCKCoordinates *)gpsCoordinates
                                compassHeading:(double)compassHeading
                        compassHeadingAccuracy:(double)compassHeadingAccuracy
                              scapeCoordinates:(nullable SCKCoordinates *)scapeCoordinates
                                  scapeHeading:(nullable NSNumber *)scapeHeading
                              scapeOrientation:(nullable SCKScapeOrientation *)scapeOrientation
                        scapeRawHeightEstimate:(nullable NSNumber *)scapeRawHeightEstimate
                          scapeConfidenceScore:(nullable NSNumber *)scapeConfidenceScore
                               cameraTransform:(nonnull NSArray<NSNumber *> *)cameraTransform
                                  acceleration:(nonnull NSArray<NSNumber *> *)acceleration
                              userAcceleration:(nonnull NSArray<NSNumber *> *)userAcceleration
                                       gravity:(nonnull NSArray<NSNumber *> *)gravity
                                          gyro:(nonnull NSArray<NSNumber *> *)gyro
                                      attitude:(nonnull NSArray<NSNumber *> *)attitude;
+ (nonnull instancetype)geoPoseWithGpsCoordinates:(nonnull SCKCoordinates *)gpsCoordinates
                                   compassHeading:(double)compassHeading
                           compassHeadingAccuracy:(double)compassHeadingAccuracy
                                 scapeCoordinates:(nullable SCKCoordinates *)scapeCoordinates
                                     scapeHeading:(nullable NSNumber *)scapeHeading
                                 scapeOrientation:(nullable SCKScapeOrientation *)scapeOrientation
                           scapeRawHeightEstimate:(nullable NSNumber *)scapeRawHeightEstimate
                             scapeConfidenceScore:(nullable NSNumber *)scapeConfidenceScore
                                  cameraTransform:(nonnull NSArray<NSNumber *> *)cameraTransform
                                     acceleration:(nonnull NSArray<NSNumber *> *)acceleration
                                 userAcceleration:(nonnull NSArray<NSNumber *> *)userAcceleration
                                          gravity:(nonnull NSArray<NSNumber *> *)gravity
                                             gyro:(nonnull NSArray<NSNumber *> *)gyro
                                         attitude:(nonnull NSArray<NSNumber *> *)attitude;

/** Current GPS coordinates computed from the GPS's device */
@property (nonatomic, readonly, nonnull) SCKCoordinates * gpsCoordinates;

/** Current compass heading representing the real true north computed from the compass's device */
@property (nonatomic, readonly) double compassHeading;

/** Current compass heading accuracy representing the maximum deviation (measured in degrees) between the reported heading and the true geomagnetic heading */
@property (nonatomic, readonly) double compassHeadingAccuracy;

/** Current camera-based device's coordinates computed from the camera's device */
@property (nonatomic, readonly, nullable) SCKCoordinates * scapeCoordinates;

/** Current heading computed from the camera's device */
@property (nonatomic, readonly, nullable) NSNumber * scapeHeading;

/** Current orientation computed from the camera's device */
@property (nonatomic, readonly, nullable) SCKScapeOrientation * scapeOrientation;

/** Current height estimate computed from the camera's device: can be used to estimate where the ground is located */
@property (nonatomic, readonly, nullable) NSNumber * scapeRawHeightEstimate;

/** Percentage indicating how likely the current area is recognized by Scape Vision Engine */
@property (nonatomic, readonly, nullable) NSNumber * scapeConfidenceScore;

/** Camera transform matrix4x4 representing the current translation and rotation of the device computed from ARKit/ARCore */
@property (nonatomic, readonly, nonnull) NSArray<NSNumber *> * cameraTransform;

/** The acceleration vector measured by the accelerometer  */
@property (nonatomic, readonly, nonnull) NSArray<NSNumber *> * acceleration;

/** The acceleration vector that the user is giving to the device */
@property (nonatomic, readonly, nonnull) NSArray<NSNumber *> * userAcceleration;

/** The gravity vector expressed in the device's reference frame */
@property (nonatomic, readonly, nonnull) NSArray<NSNumber *> * gravity;

/** The rotation rate vector as measured by the gyro (structure containing 3-axis rotation rate data) */
@property (nonatomic, readonly, nonnull) NSArray<NSNumber *> * gyro;

/** The attitude vector of the device (yaw, pitch, roll) */
@property (nonatomic, readonly, nonnull) NSArray<NSNumber *> * attitude;

@end
