The virtual camera is a very useful addition to OBS, but it is frustrating to have to replace the default placeholder.png file every time OBS Studio is upgraded. It would be quite useful to be able to create a custom placeholder.png file ONCE and not have to track down the default file over and over and over.

This plugin provides simple UI access (via Tools->Virtual Camera Placeholder) for the user to select a custom PNG file to be used by the Virtual Camera when the Virtual Camera in OBS is stopped. Skype, Zoom, etc., will no show your own branded image instead of the the default OBS placeholder.png file if you start Skype, Zoom, etc., before starting OBS or the Virtual Camera.

Prerequisites:

On MacOS, the mac-virtualcam module has been modified to support this plugin. That modification was added AFTER 26.1.2 was released, so you'll have to build OBS yourself, or wait for the next release following 26.1.2.

On Windows, I've submitted a Pull Request (https://github.com/obsproject/obs-studio/pull/4446) to support a custom placeholder.png file on Windows. This plugin won't really do anything on Windiws until the suporting change is made in the OBS win-dshow virtualcam-module.
    
