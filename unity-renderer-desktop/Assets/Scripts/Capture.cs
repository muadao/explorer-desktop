using System;
using System.IO;
using UnityEditor;
using UnityEngine;

public static class ScreenShot
{
    [MenuItem("Screen Capture/Capture")]
    public static void Capture()
    {
        var now = DateTime.Now;
        var folder = Path.Combine(Application.persistentDataPath, "Screenshot");
        var path = Path.Combine(folder, $"Screenshot_{now.Hour}_{now.Minute}_{now.Second}.png");
        if (!Directory.Exists(folder)) 
            Directory.CreateDirectory(folder);

        ScreenCapture.CaptureScreenshot(path);
        Debug.LogError(path);
    }
}