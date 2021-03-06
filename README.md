The virtual camera is a very useful addition to OBS, but it is frustrating to have to replace the default placeholder.png file every time OBS Studio is upgraded. It would be quite useful to be able to create a custom placeholder.png file ONCE and not have to track down the default file over and over and over.

This plugin provides simple UI access (via Tools->Virtual Camera Placeholder) for the user to select a custom PNG file to be used by the Virtual Camera when the Virtual Camera in OBS is stopped. Skype, Zoom, etc., will no show your own branded image instead of the the default OBS placeholder.png file if you start Skype, Zoom, etc., before starting OBS or the Virtual Camera.

Prerequisites:

On MacOS, the mac-virtualcam module has been modified to support this plugin. That modification is in OBS 27 for MacOS.

On Windows, I've submitted a Pull Request to support a custom placeholder.png file on Windows. This plugin won't really do anything on Windows until the supporting change is made in the OBS win-dshow virtualcam-module.
    
Screenshot of the PNG file selection dialog added by this plugin:

https://github.com/pedanticdan/obs-placeholder/blob/master/UI-screenshot.png

----------------------------------
When a user selects a PNG file using the above dialog, the plugin will:

    A) Save the path to the custom PNG file

    B) Locate the standard application support directory (creating it if necessary)

    C) Copy the user-selected PNG file to the standard application support directory as placeholder.png

If the user clears the text box in the file selection dialog, the plugin will delete the custom placeholder.png file from the standard application support directory. The result is that the Virtual Camera module will use the default placeholder.png file.
