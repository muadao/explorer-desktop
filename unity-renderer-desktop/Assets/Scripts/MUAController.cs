using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using UnityEngine;
using UnityEngine.Rendering;
using UnityEngine.Rendering.PostProcessing;

public class MUAController : MonoBehaviour
{
    private readonly HashSet<Canvas> disabledCanvases = new();

    private void Update()
    {
        if (Input.GetKey(KeyCode.LeftShift))
        {
            if (Input.GetKeyDown(KeyCode.H))
            {
                var canvases = FindObjectsOfType<Canvas>();
                foreach (var canvas in canvases)
                {
                    if (disabledCanvases.Contains(canvas))
                        continue;
                    if (!canvas.enabled)
                        continue;

                    canvas.enabled = false;
                    disabledCanvases.Add(canvas);
                }
            }

            if (Input.GetKeyDown(KeyCode.S))
            {
                foreach (var canvas in disabledCanvases)
                {
                    canvas.enabled = true;
                }

                disabledCanvases.Clear();
            }

            if (Input.GetKeyDown(KeyCode.E))
            {
                Process.Start(Path.Combine(Application.persistentDataPath, "Screenshot"));
            }

            if (Input.GetKeyDown(KeyCode.C))
            {
                ScreenShot.Capture();
            }
        }
    }
}