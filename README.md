# System Key Interceptor in 0.5

Catching system key presses (CapsLock, ScrollLock, NumLock). For keyboards without indication of pressing system keys.
Additional functionality: 
* shift + 'т/n'(ru/en) - switching of the right 'enter' to 'н/y'(ru/en)
* shift + 'щ/o'(ru/en) - switching of the right '+' to 'осв/jcd'(ru/en)

## Architecture:
* Full support for the MVC architectural pattern
* Compliance with SOLID rules
* Full OOP
* Design Pattern "Factory Method" for hook events
* DLL with exported classes (COM MS C++ style) with a hook
