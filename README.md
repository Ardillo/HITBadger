##The Hack In The Box (HITB) 2014 Amsterdam Badge
Also known as: <i>"HITBadger"</i> --> http://www.randomdata.nl/wiki/index.php/HITBadger <br>

Based on an arduino UNO with ATmega328.<br>
Goal is to have only through hole components so everybody can make one.<br>

We've used schematics from the Arduino Uno from Aruino.cc, 
Diavolino by Evil Mad Science and BoArduino by Adafruit.

We changed some default settings in the MIRF library to fit our needs.
Therefor we call it "HITBmirf" for example it uses 32 byte payloads as default.<br>
The NRF24L01+ could also used with the RF24 library from maniacbug and the standard MIRF 
library Look here for a good tutorial:<br>
http://maniacbug.wordpress.com/2011/11/02/getting-started-rf24/ <br>
His github can be cloned and used directly after copying the files to the
correct directory in your arduino installation.
https://github.com/maniacbug/RF24/ <br>

Build working concept with the "GettingStarted" program. I measured the power
consumption at 4.7V. it was 23mA. 
This could be enhanced by using a different library which puts the Arduino to
sleep, see: http://www.openhomeautomation.net/arduino-battery/ <br>
The power circuit seemed quite stable.

The HITBadger.zip contains all necessary Gerber files, 10 in total. 
Smart-prototyping needs 10 files, no offset, no mirror, no rotate, no upside
down. (http://smart-prototyping.com/PCB-Prototyping.html) <br>

##Arduino IDE
The board is completely programmable within the Arduino IDE. Therefor you need to copy the files 
of the <i>libraries</i> and <i>hardware</i> folder to the according folder of the Arduino IDE install folder.
The location of those folder varies depending on the OS you're using. A quick search on the internetzz will give 
you more information.
###Examples
We've included all the used programs during the event in the examples of our HITBmirf library, when 
imported correctly you can access them through the menu of your Arduino IDE.
A short explanation for the programs used in the event:
*HITBadgeClient <br>
The program everyone got on their personal badge with their nickname acting as a address.
*HITBadgeCommStation<br>
The program used on the base stations which where sending messages to the personal badges.
*HITBadgeCommSend -Receive <br>
Some testing code
*HITBadgeComStationParty<br>
The program used on the base stations during the after party to send everyone a message.
*HITBadgeLEDRoutine
A +/- 70 seconds during program which do all kinds of animations with the LED's.

###Hardware
Some of you have a ATmega328 and others have a ATmega328p both of the chips have the same pinout, but
when flashing a new bootloader (if you ever going to do so) you need some changements in your IDE.
If you copy the files of the <i> hardware</i> folder to the according location of your IDE you will notice
that two new options are available in the boards menu of the Arduino IDE. (Tools -> Board).
One of them is specific for uploading a new Arduino bootloader to a HITBadge with a ATmega328 (without the p).


##FTDI without DTR line
To use a FTDI uploader without a DTR line add a line to your preferences.txt of your Arduino IDE
<br>
<code>
upload.verbose = true
</code><br>
When the main init is started while uploading your code press the reset button to start the
bootloader of the Arduino again and upload your code. This takes some practice.
source: https://electronics.stackexchange.com/questions/2512/ftdi-basic-breakout-5v
<br>


Some url's to get you going:<br>
* https://learn.sparkfun.com/tutorials/how-to-install-and-setup-eagle/download-install-run<br>
* https://learn.sparkfun.com/tutorials/using-eagle-schematic/<br>
* https://learn.sparkfun.com/tutorials/using-eagle-board-layout/<br>
* https://learn.sparkfun.com/tutorials/making-custom-footprints-in-eagle/<br>
* https://learn.sparkfun.com/tutorials/designing-pcbs-smd-footprints/<br>
* http://arduino.cc/en/uploads/Hacking/Atmega168PinMap2.png<br>
* http://learn.adafruit.com/boarduino-kits<br>
* http://learn.adafruit.com/downloads/pdf/boarduino-kits.pdf<br>
* http://learn.adafruit.com/system/assets/assets/000/010/223/original/boarduinosch.png<br>
* https://www.adafruit.com/partfinder/<br>
* http://wiki.evilmadscientist.com/Diavolino<br>
* https://s3.amazonaws.com/evilmadscience/KitInstrux/diavolino_instrux.pdf<br>
* https://s3.amazonaws.com/evilmadscience/KitInstrux/diavolino_schematic.pdf<br>

####NRF24L01 specific URL's:
* http://arduino-info.wikispaces.com/Nrf24L01-2.4GHz-HowTo
* http://hack.lenotta.com/arduino-nrf24l01-modules-testing/
* http://maniacbug.wordpress.com/2011/11/02/getting-started-rf24/
* http://yourduino.com/docs/nRF24L01-Modules-connection-diagram.pdf
* http://playground.arduino.cc/InterfacingWithHardware/Nrf24L01

####Bill of "difficult" Materials (BOdM):
* http://nl.farnell.com/microchip/mcp1700-3302e-to/ic-v-reg-ldo-250ma-to-92-3/dp/1296588
* http://nl.farnell.com/microchip/mcp1702-5002e-to/ic-v-reg-ldo-250ma-to-92-3/dp/1331487
* http://nl.farnell.com/txc/9b-16-000meej-b/xtal-16-000mhz-18pf-hc-49s/dp/1842217<br>
