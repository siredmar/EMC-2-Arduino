Setup info for HAL2Arduino-0.3 (Assumes you have LinuxCNC installed and basic knowledge of the custom.hal)
Extract files to some temp folder.
Look them over.

Edit custom.hal file, edit the following line:
loadusr -Wn Hal2Arduino /home/dewy/Desktop/my-mill/HAL2Arduino-0.3.py
Replace "dewy" with your linux username.

Make any other adjustments as needed. (init.hacking.skillz)

Save files to ~/Desktop/my-mill/

Right click on HAL2Arduino-0.3.py select "Permissions" tab, and check "Allow executing file as program"
Click close.


Edit and upload sketch. (don't forget mods.)

Run linuxCNC.




For debugging:
 in console type:
	linuxcnc /home/dewy/linuxcnc/configs/my-mill/my-mill.ini
	(Again, replace "dewy" with your linux username.)