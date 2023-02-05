//
//  MovieCapture.h
//  MovieCapture
//
//  Created by Morris Butler on 13/05/2019.
//  Copyright © 2019 RenderHeads. All rights reserved.
//

#include "MCTypes.h"

#ifdef __cplusplus
extern "C" {
#endif

NS_ASSUME_NONNULL_BEGIN

void *GetRenderEventFunc(void);
void *GetFreeResourcesEventFunc(void);
bool  Init(void);
void  Deinit(void);
void  SetMicrophoneRecordingHint(bool enabled);
bool  IsTrialVersion(void);
int   GetVideoCodecMediaApi(int index);
int   GetVideoCodecCount(void);
bool  IsConfigureVideoCodecSupported(int index);
void  ConfigureVideoCodec(int index);
int   GetAudioCodecMediaApi(int index);
int   GetAudioCodecCount(void);
bool  IsConfigureAudioCodecSupported(int index);
void  ConfigureAudioCodec(int index);
int   GetAudioInputDeviceCount(void);
int   CreateRecorderVideo(const unichar *filename, uint width, uint height, float frameRate, int format, bool isRealTime, bool isTopDown, int videoCodecIndex, int audioSource, int audioSampleRate, int audioChannelCount, int audioInputDeviceIndex, int audioCodecIndex, bool forceGpuFlush, VideoEncoderHints *hints);
int   CreateRecorderImages(const unichar *filename, uint width, uint height, float frameRate, int format, bool isRealTime, bool isTopDown, int imageFormatType, bool forceGpuFlush, int startFrame, ImageEncoderHints *hints);
int   CreateRecorderPipe(const unichar *filename, uint width, uint height, float frameRate, int format, bool isTopDown, bool supportAlpha, bool forceGpuFlush);
bool  Start(int handle);
bool  IsNewFrameDue(int handle);
void  EncodeFrame(int handle, void *data);
void  EncodeAudio(int handle, void *data, uint length);
void  EncodeFrameWithAudio(int handle, void *videoData, void *audioData, uint audioLength);
void  Pause(int handle);
void  Stop(int handle, bool skipPendingFrames);
bool  IsFileWritingComplete(int handle);
int   SetEncodedFrameLimit(int handle, uint limit);
void  SetTexturePointer(int handle, void *texture);
void  FreeRecorder(int handle);
uint  GetNumDroppedFrames(int handle);
uint  GetNumDroppedEncoderFrames(int handle);
uint  GetNumEncodedFrames(int handle);
uint  GetEncodedSeconds(int handle);
uint  GetFileSize(int handle);
void *GetPluginVersion(void);
bool  GetVideoCodecName(int index, unichar *name, int nameBufferLength);
bool  GetAudioCodecName(int index, unichar *name, int nameBufferLength);
bool  GetAudioInputDeviceName(int index, unichar *name, int nameBufferLength);
bool  GetContainerFileExtensions(int videoCodecIndex, int audioCodecIndex, unichar *extensions, int extensionsLength);
void  SetLogFunction(void *logFunction);
void  SetErrorHandler(int index, void *errorHandler);

// Ambisonic support
MCAmbisonicSourceRef AddAmbisonicSourceInstance(int maxCoefficients);
void  RemoveAmbisonicSourceInstance(MCAmbisonicSourceRef source);
void  UpdateAmbisonicWeights(MCAmbisonicSourceRef source, float azimuth, float elevation, MCAmbisonicOrder ambisonicOrder, MCAmbisonicChannelOrder channelOrder, float *weights);
void  EncodeMonoToAmbisonic(MCAmbisonicSourceRef source, float *inSamples, int inOffset, int inCount, int numChannels, void *outSamples, int outOffset, int outCount, MCAmbisonicOrder ambisonicOrder);

void MCUnityRegisterRenderingPlugin(void *unityRegisterRenderingPluginFunction);

NS_ASSUME_NONNULL_END

#if __cplusplus
}
#endif
