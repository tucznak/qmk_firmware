# Giulia

![Giulia](https://raw.githubusercontent.com/tucznak/giulia/main/Images/photo.png)

*A compact 40% DIY through-hole keyboard kit. More information can be found on [Github](https://github.com/tucznak/giulia)*

* Keyboard Maintainer: [TuCZnak](https://github.com/tucznak)
* Hardware Supported: Giulia rev. 1, ATMega32A
* Hardware Availability: currently all components can (and need) to be self-sourced. Limited number of kits are available from the maintainer.

Make example for this keyboard (after setting up your build environment):

    make tucznak/giulia:default

Flashing example for this keyboard:

    make tucznak/giulia:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Hold the button labeled BOOT on the top side of the PCB, then briefly press the button labeled RESET, then release the BOOT button after a second or two.
* **Keycode in layout**: Press the key mapped to `RESET` if it is available on your layout. On default keymap this combination is Fn + Escape
