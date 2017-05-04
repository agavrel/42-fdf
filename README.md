# FDF Project

## Project Overview
<img align="center" src="http://image.noelshack.com/fichiers/2016/52/1483109173-screen-shot-2016-12-30-at-3-40-16-pm.png" width="100%" />
FDF is a 42 Project to learn about 3d programming. The program takes a map as parameter and creates its 3d representation.
* Render a 3D map from a 2D representation. Initially I was using vectors and simple formulas as illustrated by formula.c file. Later I switched to matrixes.
* You can rotate, increase altitude coefficient and zoom in/out. All transformations are done through matrixes transformations except for the one translating the picture.
* Colors of the map altermate according to seasons and altitude. Colors slowly change to the next point's color. The program can parse colored maps and also handle transparency. Brightness of the image can also be decreased or increased. Please use menu (H button) for a full list of available options.

## Credits
* Thanks to my dear friend <a href="http://www.github.com/Janwalsh91">Janwalsh91</a> for the miscellaneous tips and the awesome colors.

## Mathematics Sources
* Also many thanks to these very informative sites: https://www.scratchapixel.com/lessons/mathematics-physics-for-computer-graphics/geometry/spherical-coordinates-and-trigonometric-functions
* https://web.archive.org/web/20150225192611/http://www.arcsynthesis.org/gltut/index.html
* http://inside.mines.edu/fs_home/gmurray/ArbitraryAxisRotation/

## Installation
```
$> make
$> ./fdf map.fdf
```

## "Quand la liberte reviendra, je reviendrai" Victor Hugo
<img align="center" src="http://image.noelshack.com/fichiers/2017/03/1484869443-output-tekfsz-2.gif" width ="100%" />

## Project Schema
<img align="center" src="http://image.noelshack.com/fichiers/2017/02/1484084381-screen-shot-2017-01-10-at-10-37-48-pm.png" width ="100%" />

## Contact & contribute
To contact me and helping me to (fix bugs || improve) FDF, feel free to e-mail me at **angavrel at student dot 42 dot fr**
<img align="left" src="http://image.noelshack.com/fichiers/2017/03/1484868498-output-l0pcgh-1.gif" width ="100%" />
