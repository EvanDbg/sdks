//
//  ARCamera.h
//  ARKit
//
//  Copyright © 2016-2017 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIApplication.h>
#import <simd/simd.h>

NS_ASSUME_NONNULL_BEGIN

/**
 A value describing the camera’s tracking state.
 */
API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(macos, watchos, tvos)
typedef NS_ENUM(NSInteger, ARTrackingState) {
    /** Tracking is not available. */
    ARTrackingStateNotAvailable,
    
    /** Tracking is limited. See tracking reason for details. */
    ARTrackingStateLimited,
    
    /** Tracking is Normal. */
    ARTrackingStateNormal,
} NS_REFINED_FOR_SWIFT;

/**
 A reason describing why the camera’s tracking state is limited.
 */
API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(macos, watchos, tvos)
typedef NS_ENUM(NSInteger, ARTrackingStateReason) {
    /** Tracking is not limited. */
    ARTrackingStateReasonNone,
    
    /** Tracking is limited due to initialization in progress. */
    ARTrackingStateReasonInitializing,
    
    /** Tracking is limited due to a excessive motion of the camera. */
    ARTrackingStateReasonExcessiveMotion,
    
    /** Tracking is limited due to a lack of features visible to the camera. */
    ARTrackingStateReasonInsufficientFeatures,
} NS_REFINED_FOR_SWIFT;


/**
 A model representing the camera and its parameters.
 */
API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(macos, watchos, tvos)
@interface ARCamera : NSObject <NSCopying>

/**
 The transformation matrix that defines the camera’s rotation and translation in world coordinates.
 */
@property (nonatomic, readonly) matrix_float4x4 transform;

/**
 The camera’s orientation defined as Euler angles.
 
 @dicussion The order of components in this vector matches the axes of rotation:
               1. Pitch (the x component) is the rotation about the node’s x-axis (in radians)
               2. Yaw   (the y component) is the rotation about the node’s y-axis (in radians)
               3. Roll  (the z component) is the rotation about the node’s z-axis (in radians)
            ARKit applies these rotations in the reverse order of the components:
               1. first roll
               2. then yaw
               3. then pitch
 */
@property (nonatomic, readonly) vector_float3 eulerAngles;

/**
 The tracking state of the camera.
 */
@property (nonatomic, readonly) ARTrackingState trackingState NS_REFINED_FOR_SWIFT;

/**
 The reason for the camera’s current tracking state.
 */
@property (nonatomic, readonly) ARTrackingStateReason trackingStateReason NS_REFINED_FOR_SWIFT;

/**
 The camera intrinsics.
 @discussion The matrix has the following contents:
 fx 0   px
 0  fy  py
 0  0   1
 fx and fy are the focal length in pixels.
 px and py are the coordinates of the principal point in pixels.
 The origin is at the center of the upper-left pixel.
 */
@property (nonatomic, readonly) matrix_float3x3 intrinsics;

/**
 The camera image resolution in pixels.
 */
@property (nonatomic, readonly) CGSize imageResolution;

/**
 The projection matrix of the camera.
*/
@property (nonatomic, readonly) matrix_float4x4 projectionMatrix;

/**
 Project a 3D point in world coordinate system into 2D viewport space.
 
 @param point 3D point in world coordinate system.
 @param orientation Viewport orientation.
 @param viewportSize Viewport (or image) size.
 @return 2D point in viewport coordinate system with origin at top-left.
 */
- (CGPoint)projectPoint:(vector_float3)point orientation:(UIInterfaceOrientation)orientation viewportSize:(CGSize)viewportSize;

/**
 Creates a projection matrix for the camera given rendering parameters.
 
 @discussion The projection matrix returned provides an aspect fill for the provided viewport size and orientation.
 @param orientation Viewport orientation.
 @param viewportSize Viewport size.
 @param zNear Near depth limit.
 @param zFar Far depth limit.
 */
- (matrix_float4x4)projectionMatrixForOrientation:(UIInterfaceOrientation)orientation viewportSize:(CGSize)viewportSize zNear:(CGFloat)zNear zFar:(CGFloat)zFar;

/**
 Creates a view matrix for the camera given an interface orientation.
 
 @discussion The view matrix can be used to transform geometry into camera space for a given orientation
 @param orientation The interface orientation that will be used to render the camera’s view.
 */
- (matrix_float4x4)viewMatrixForOrientation:(UIInterfaceOrientation)orientation;

/** Unavailable */
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
