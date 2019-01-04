// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from ar.djinni

#import "SCKArEulerAngles.h"
#import "SCKArTrackingState.h"
#import <Foundation/Foundation.h>

/** public data object */
@interface SCKArCamera : NSObject
- (nonnull instancetype)initWithTransform:(nonnull NSArray<NSNumber *> *)transform
                               viewMatrix:(nonnull NSArray<NSNumber *> *)viewMatrix
                         projectionMatrix:(nonnull NSArray<NSNumber *> *)projectionMatrix
                              eulerAngles:(nonnull SCKArEulerAngles *)eulerAngles
                            trackingState:(SCKArTrackingState)trackingState
                              focalLength:(nonnull NSArray<NSNumber *> *)focalLength
                           principalPoint:(nonnull NSArray<NSNumber *> *)principalPoint;
+ (nonnull instancetype)arCameraWithTransform:(nonnull NSArray<NSNumber *> *)transform
                                   viewMatrix:(nonnull NSArray<NSNumber *> *)viewMatrix
                             projectionMatrix:(nonnull NSArray<NSNumber *> *)projectionMatrix
                                  eulerAngles:(nonnull SCKArEulerAngles *)eulerAngles
                                trackingState:(SCKArTrackingState)trackingState
                                  focalLength:(nonnull NSArray<NSNumber *> *)focalLength
                               principalPoint:(nonnull NSArray<NSNumber *> *)principalPoint;

@property (nonatomic, readonly, nonnull) NSArray<NSNumber *> * transform;

@property (nonatomic, readonly, nonnull) NSArray<NSNumber *> * viewMatrix;

@property (nonatomic, readonly, nonnull) NSArray<NSNumber *> * projectionMatrix;

@property (nonatomic, readonly, nonnull) SCKArEulerAngles * eulerAngles;

@property (nonatomic, readonly) SCKArTrackingState trackingState;

@property (nonatomic, readonly, nonnull) NSArray<NSNumber *> * focalLength;

@property (nonatomic, readonly, nonnull) NSArray<NSNumber *> * principalPoint;

@end