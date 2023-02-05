//
//  MCUnityRegisterPlugin.m
//  AVPro MovieCapture
//
//  Created by Morris Butler on 29/03/2021.
//  Copyright © 2021 RenderHeads. All rights reserved.
//

#import "AVProMovieCapture/AVProMovieCapture.h"

void MCPluginBootstrap(void)
{
	MCUnityRegisterRenderingPlugin(UnityRegisterRenderingPluginV5);
}
