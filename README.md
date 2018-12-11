# raytracing
This was a C++ program I made years ago realizing 2D ray tracing for imaging systems. 
It calculates for 2D optical imaging systems with aperture stop at first surface by defaulting set:
For on-axis objects
1) first order parameters (for paraxial rays), f', l' of chief ray, y'
2) spherical aberration for full aperture and 0.707 aperture.
3) longitudinal chromatic aberration for full aperture, 0.707 aperture.
4) Distortion of full aperture, 0.707 aperture, of d light.
5) Lateral chromatic aberration at full aperture, 0.707 aperture.

For off-axis objects, it calculates height of image for
1)full field/full aperture, full field/negative aperture, 
2)full field/0 aperture, full field/0.707 aperture, full field/negative 0.707 aperture
3) 0.707 field/full aperture, 0.707 field/negative full aperture, 0.707 field/0 aperture,
4) 0.707 field/0.707 aperture, 0.707 field/negative 0.707 aperture
for d, f, c lights respectively.



This program was created under Qt. https://www.qt.io/developers/
To use it, please do following steps first :
1) put qt5core.dll file under sys64WOW and system32 folder in C:\windows\.
2) set environment variables (in windows systems, you can find it at "advanced properties")
3) set lens parameters of your imaging system in try.txt file. (you can find it in "bin" folder).
** Note: don't delete the first row of try.txt. 

Copyright researved by me at xiananqin2018@gmail.com.
Feel free to send emails to me if you have any questions.
