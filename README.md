## imariom-dwm

## Table of Contents:
  * [About Suckless dwm](#about-suckless-dwm)
    * [Patches added to this build include](#patches-added-to-this-build-include)
    * [Dependencies for imariom-dwm include](#dependencies-for-imariom-dwm-include)
  * [Installing imariom-dwm](#installing-imariom-dwm)
    * [Running and auto-starting dwm](#running-and-auto-starting-dwm)
    * [Configuring imariom-dwm](#configuring-imariom-dwm)
  * [Keybindings](#keybindings)
    * [Main keybindings](#main-keybindings)
    * [Application controls](#application-controls)

## About Suckless dwm
|![imariom-dwm](https://github.com/imariom/dotfiles/blob/main/.screenshots/imariom-dwm-thumbnail.png)|
|:--:|
| *imariom-dwm* |

Dwm is an exceptionally fast, lightweight, and dynamic window manager for X, developed by the talented team at suckless.org. This build is my personal version of dwm, where I’ve applied several patches to enhance its functionality and usability, making it more 'sensible' while maintaining its minimalist approach, rather than strictly adhering to the 'suckless' philosophy.

### Patches added to this build include:
  * statuspadding (horizontal and vertical padding in the status bar are now configurable options)
  * attachaside (new clients appear in the stack rather than as the master)
  * fullgaps (adding gaps when more than one window)

### Dependencies for imariom-dwm include:
  * ttf-inconsolata-nerd (you can substitute it with your preferred nerd font family)
  * ttf-nerd-fonts-symbols (for emojis in tags list)
  * Alacritty
  * rofi

Also, you will need to add the following from the AUR:
  * https://aur.archlinux.org/packages/libxft-bgra/ (needed for colored fonts and emojis)

## Installing imariom-dwm
Download the source code from this repository or use a git clone:

```
git clone https://gitlab.com/imariom/imariom-dwm.git
cd imariom-dwm
sudo make clean install
```

This build has only been tested on Arch Linux However, you are welcome to test it on your own system, and feel free to modify or customize it as needed. Your feedback and contributions are highly appreciated as we continue refining the project.

> [!NOTE]
> Installing ***imariom-dwm*** will overwrite your existing dwm installation.

### Running and auto-starting dwm
If you're not using a login manager (like LightDM), you can configure dwm to start automatically by adding the following line to your ```.xinitrc``` file and launching it with startx:

```exec dwm```

If you're using a login manager (such as LightDM), ensure there's a dwm.desktop file in your ```/usr/share/xsessions/``` directory. The file should look something like this:

```
[Desktop Entry]
Encoding=UTF-8
Name=Dwm
Comment=Dynamic window manager
Exec=dwm
Icon=dwm
Type=XSession
```
## Configuring imariom-dwm
Inside the downloaded source code of imariom-dwm you can configure it by editing the ```config.def.h``` and (re)compiling the source code.

> [!NOTE]
> Before (re)compiling with ```sudo make install``` make sure to delete the current (if exists) ```config.h``` file.

## Keybindings
The MODKEY is set to the Super key (aka the Windows key).

### Main keybindings

| Keybinding              | Action                                                       |
|-------------------------|--------------------------------------------------------------|
| MODKEY + RETURN         | opens terminal (alacritty but can be easily changed)         |
| MODKEY + SHIFT + RETURN | opens run launcher (dmenu but can be changed)                |
| MODKEY + SHIFT + c      | closes window with focus                                     |
| MODKEY + SHIFT + r      | restarts dwm                                                 |
| MODKEY + SHIFT + q      | quits dwm                                                    |
| MODKEY + b              | hides the bar                                                |
| MODKEY + 1-9            | switch focus to workspace (1-9)                              |
| MODKEY + SHIFT + 1-9    | send focused window to workspace (1-9)                       |
| MODKEY + j              | focus stack +1 (switches focus between windows in the stack) |
| MODKEY + k              | focus stack -1 (switches focus between windows in the stack) |
| MODKEY + SHIFT + j      | rotate stack +1 (rotates the windows in the stack)           |
| MODKEY + SHIFT + k      | rotate stack -1 (rotates the windows in the stack)           |
| MODKEY + h              | setmfact -0.05 (expands size of window)                      |
| MODKEY + l              | setmfact +0.05 (shrinks size of window)                      |
| MODKEY + .              | focusmon +1 (switches focus next monitors)                   |
| MODKEY + ,              | focusmon -1 (switches focus to prev monitors)                |

### Application controls

| Keybinding       | Action                                                                       |
|------------------|------------------------------------------------------------------------------|
| MODKEY + ALT + b | open Brave browser                                                           |
| MODKEY + ALT + c | open Visual Studio Code                                                      |
| MODKEY + ALT + s | open Spotify                                                                 |
| MODKEY + ALT + m | open [mailspring](https://github.com/Foundry376/Mailspring) Email Client     |
| MODKEY + ALT + f | open [Thunar](https://wiki.archlinux.org/title/Thunar) File Manager          |
