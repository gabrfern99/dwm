# Custom build of dwm
![image](https://i.imgur.com/WjNP4Fs.png)
## Available patches
***
- [Systray](https://dwm.suckless.org/patches/systray/) icons
- True fullscreen and prevents focus shifting.
- [Stacker](https://dwm.suckless.org/patches/stacker/)
- [Colorbar](https://dwm.suckless.org/patches/colorbar/)
- Netstack
- [Wincon](https://dwm.suckless.org/patches/winicon/) enables dwm to show window icons ![image](https://i.imgur.com/eKsNUSf.png)
- [Vanitygaps](https://dwm.suckless.org/patches/vanitygaps/)
- [Shiftview](https://dwm.suckless.org/patches/nextprev/) that allows you to cycle through tags
- [Clickable statusbar](https://dwm.suckless.org/patches/statuscmd/) with this build of [dwmblocks](https://github.com/LukeSmithxyz/dwmblocks)
- [Reads Xresources](https://dwm.suckless.org/patches/xresources/) colors and variables
- Support for multiple [scratchpads](https://dwm.suckless.org/patches/scratchpads/)
- [preserveonrestart](https://dwm.suckless.org/patches/preserveonrestart/) preserves clients on old tags
***

## Installation
```
git clone https://github.com/gabrfern99/dwm
cd dwm
sudo make install
```

## Advice

The configuration is done in `config.h`, you may tweak it the way you want

#### Dependencies
- libxft-bgra
- imlib2
