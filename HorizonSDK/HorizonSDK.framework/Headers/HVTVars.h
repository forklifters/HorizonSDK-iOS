//
//  HVTVars.h
//  HorizonSDK
//
//  Copyright (c) 2015 Horizon Video Technologies. All rights reserved.
//

#ifndef HorizonSDK_HVTVars_h
#define HorizonSDK_HVTVars_h

#ifndef NS_ENUM
#define NS_ENUM(_type, _name) enum _name : _type _name; enum _name : _type
#endif

// Parameters holding the scale and angle values as computed by Horizon SDK
typedef struct
{
    double scale;
    double angle;
} HVTParams;

// Constant used by NSError to distinguish errors belonging to the Horizon SDK domain
extern NSString *const HVTErrorDomain;

/**
 User-provided NSDictionary key for the HVTSDK class method
 activateWithAPIKey:settings: dictionary argument, which controls
 the frequency of the low-pass filter that is used internally to smoothen out the change of scale.
 
 Smaller values provide smoother result.
 
 The value must be a positive float number.
 
 Default value is 1.8
 */
extern NSString *const HVTScaleFilterFrequencySettingsKey;

/**
 Horizon SDK-related error codes
 */
typedef NS_ENUM(NSInteger, HVTErrorCode) {
/** Error (reason unknown).*/
    HVTErrorUnknown                         = -1,
/** Given resolution or frame rate not supported by the device.*/
    HVTErrorResolutionFrameRateNotSupported = -3300,
/** User tapped outside the tappable region.*/
    HVTErrorFocusOutOfBounds                = -3301,
/** Audio recording cannot be initiated in video recording.*/
    HVTErrorAudioRecordingNotAvailable      = -3302,
/** Video stream was not found during video composition.*/
    HVTErrorVideoNotFoundDuringComposition  = -3303,
/** Photo capture failed due to already pending photo capture.*/
    HVTErrorPhotoCaptureBusy                = -3304,
/** Full resolution photo not captured as the photo mode wasn't enabled.*/
    HVTErrorPhotoModeNotEnabled             = -3305,
/** HDR not supported by the device, or the camera is not currently in photo mode.*/
    HVTErrorPhotoHDRNotSupported            = -3306,
/** Capture device was not provided. */
    HVTErrorCaptureDeviceNotProvided        = -3307,
/** Video mode was not active during the call of the particular method.*/
    HVTErrorVideoModeNotEnabled             = -3308
};

/**
 The category of media for the camera to capture.
 
 The constants in this enumeration are for use as values of the captureMode property.
 */
typedef NS_ENUM(NSInteger, HVTCaptureMode) {
/** Specifies that the camera captures movies.*/
    HVTCaptureModeVideo = 0,
/** Specifies that the camera captures still images.*/
    HVTCaptureModePhoto
};

/**
 Constants indicating the still image frame orientation on the photo mode
 */
typedef NS_ENUM(NSInteger, HVTStillImageOrientation) {
/** Still image frame will switch automatically from horizontal to vertical and vice versa depending on the rotation of the device.*/
    HVTStillImageOrientationAuto = 0,
/** Still image frame will always be horizontal.*/
    HVTStillImageOrientationHorizontal,
/** Still image frame will always be vertical.*/
    HVTStillImageOrientationVertical,
};

/**
 Constants indicating the way the leveling algorithm adjusts the crop region according
 to the device's physical orientation.
 @see HVTLevelerFlexSpeed, HVTLevelerLockedOrientation
 */
typedef NS_ENUM(NSInteger, HVTLevelerCropMode) {
/** Crop region will rotate and scale accordingly.*/
    HVTLevelerCropModeFlex,
/** Crop region will rotate and use a constant scale level.*/
    HVTLevelerCropModeRotate,
/** Leveling is disabled. Crop region will rotate for *specific* angles (multiples of pi/2)
 in order to match a horizontal or vertical physical device orientation.
     
If recording starts, the current rotation will remain unchanged until recording stops.
*/
    HVTLevelerCropModeLocked
};

/**
 Constants indicating the speed that the crop region scales (the resulting video zooms) when the leveling algorithm
 uses `HVTLevelerCropModeFlex` mode.
 @see HVTLevelerCropMode
 */
typedef NS_ENUM(NSInteger, HVTLevelerFlexSpeed) {
    /**
     The scale speed will be slow. This slows down the zoom effect 
     and produces a smoother result.
     
     A low-pass filter is used internally to smoothen out the change of scale. 
     
     You can change its frequency by providing a settings NSDictionary at the HVTSDK class method
     activateWithAPIKey:settings: using the key HVTScaleFilterFrequencySettingsKey.
     */
    HVTLevelerFlexSpeedSmooth,
    /** 
     The scale speed will be more responsive. This results to a faster but more unsteady zoom effect.
     */
    HVTLevelerFlexSpeedResponsive
};

/**
 Constants indicating the expected psysical orientation of the device when the leveling algorithm
 uses `HVTLevelerCropModeLocked` mode.
 @see HVTLevelerCropMode
 */
typedef NS_ENUM(NSInteger, HVTLevelerLockedOrientation) {
    /** Horizontal or vertical orientation will be chosen according on the device's physical orientation.*/
    HVTLevelerLockedOrientationAuto = 0,
    /** Device must be held vertically.*/
    HVTLevelerLockedOrientationVertical,
    /** The leveler is always locked into the vertical orientation, regardless of the device's orientation.*/
    HVTLevelerLockedOrientationAlwaysVertical,
    /** Device must be held horizontally.*/
    HVTLevelerLockedOrientationHorizontal,
    /** The leveler is always locked into the horizontal orientation, regardless of the device's orientation.*/
    HVTLevelerLockedOrientationAlwaysHorizontal
};

/**
 Notification name for changes on the isFlashAvailable property of HVTCamera object
 */
extern NSString *const HVTFlashIsAvailableNotification;

/**
 Notification name when focus and exposure values are locked due to a long press on a HVTView
 */
extern NSString *const HVTFocusExposureIsLockedNotification;

/**
 Notification name when iOS detects significant area change in order to switch back to continuous autofocus
 */
extern NSString *const HVTSubjectAreaDidChangeNotification;

/**
 Notification name when camera has finished focusing (whether successfully or not)
 */
extern NSString *const HVTFocusFinishedNotification;

#endif
