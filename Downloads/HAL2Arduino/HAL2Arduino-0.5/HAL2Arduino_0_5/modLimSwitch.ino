// Setup your switches.
#define useLimitSwitches true

#if useLimitSwitches
#define XaxisEnableSwitches true
#define YaxisEnableSwitches true
#define ZaxisEnableSwitches true
#define AaxisEnableSwitches false
#define BaxisEnableSwitches false
#define CaxisEnableSwitches false
#define UaxisEnableSwitches false
#define VaxisEnableSwitches false
#define WaxisEnableSwitches false

  // 0 + axisEnabled = individually disabled switch.
#define xMinSwitch 0
#define xMaxSwitch 0
#define xHomeSwitch 9

#define yMinSwitch 0
#define yMaxSwitch 0
#define yHomeSwitch 10

#define zMinSwitch 0
#define zMaxSwitch 0
#define zHomeSwitch 11

#define aMinSwitch 0
#define aMaxSwitch 0
#define aHomeSwitch 0

#define bMinSwitch 0
#define bMaxSwitch 0
#define bHomeSwitch 0

#define cMinSwitch 0
#define cMaxSwitch 0
#define cHomeSwitch 0

#define uMinSwitch 0
#define uMaxSwitch 0
#define uHomeSwitch 0

#define vMinSwitch 0
#define vMaxSwitch 0
#define vHomeSwitch 0

#define wMinSwitch 0
#define wMaxSwitch 0
#define wHomeSwitch 0

  // Temporary section for virtual switches.
  // in the future these will be fetched from my-mill.ini file during each startup.
  // But until then, should you need virtual limit switches, set them here.
  // 10000 = 1 inch/mm
#define xVirtualMin -1250
#define xVirtualMax 120000
#define xVirtualHome 10000
#define yVirtualMin -10000
#define yVirtualMax 90000
#define yVirtualHome 10000
#define zVirtualMin -20000
#define zVirtualMax 20000
#define zVirtualHome 2500
#define aVirtualMin 0
#define aVirtualMax 0
#define aVirtualHome 0
#define bVirtualMin 0
#define bVirtualMax 0
#define bVirtualHome 0
#define cVirtualMin 0
#define cVirtualMax 0
#define cVirtualHome 0
#define uVirtualMin 0
#define uVirtualMax 0
#define uVirtualHome 0
#define vVirtualMin 0
#define vVirtualMax 0
#define vVirtualHome 0
#define wVirtualMin 0
#define wVirtualMax 0
#define wVirtualHome 0

// End of configuration. Begin of program.
//#if useLimitSwitches
  // Setup pin arrays.
boolean faultId[9][3] = { {0, 0, 0}
, {0, 0, 0}
, {0, 0, 0}
, {0, 0, 0}
, {0, 0, 0}
, {0, 0, 0}
, {0, 0, 0}
, {0, 0, 0}
, {0, 0, 0}
};
boolean faultIdOld[9][3] = { {0, 0, 0}
, {0, 0, 0}
, {0, 0, 0}
, {0, 0, 0}
, {0, 0, 0}
, {0, 0, 0}
, {0, 0, 0}
, {0, 0, 0}
, {0, 0, 0}
};

void switchesSetup()
{
#if xMinSwitch && XaxisEnableSwitches
    pinMode(xMinSwitch, INPUT_PULLUP);
#endif
#if xMaxSwitch && XaxisEnableSwitches
    pinMode(xMaxSwitch, INPUT_PULLUP);
#endif
#if xHomeSwitch && XaxisEnableSwitches
    pinMode(xHomeSwitch, INPUT_PULLUP);
#endif

#if yMinSwitch && YaxisEnableSwitches
    pinMode(yMinSwitch, INPUT_PULLUP);
#endif
#if yMaxSwitch && YaxisEnableSwitches
    pinMode(yMaxSwitch, INPUT_PULLUP);
#endif
#if yHomeSwitch && YaxisEnableSwitches
    pinMode(yHomeSwitch, INPUT_PULLUP);
#endif

#if zMinSwitch && ZaxisEnableSwitches
    pinMode(zMinSwitch, INPUT_PULLUP);
#endif
#if zMaxSwitch && ZaxisEnableSwitches
    pinMode(zMaxSwitch, INPUT_PULLUP);
#endif
#if zHomeSwitch && ZaxisEnableSwitches
    pinMode(zHomeSwitch, INPUT_PULLUP);
#endif

#if aMinSwitch && AaxisEnableSwitches
    pinMode(aMinSwitch, INPUT_PULLUP);
#endif
#if aMaxSwitch && AaxisEnableSwitches
    pinMode(aMaxSwitch, INPUT_PULLUP);
#endif
#if aHomeSwitch && AaxisEnableSwitches
    pinMode(aHomeSwitch, INPUT_PULLUP);
#endif

#if bMinSwitch && BaxisEnableSwitches
    pinMode(bMinSwitch, INPUT_PULLUP);
#endif
#if bMaxSwitch && BaxisEnableSwitches
    pinMode(bMaxSwitch, INPUT_PULLUP);
#endif
#if bHomeSwitch && BaxisEnableSwitches
    pinMode(bHomeSwitch, INPUT_PULLUP);
#endif

#if cMinSwitch && CaxisEnableSwitches
    pinMode(cMinSwitch, INPUT_PULLUP);
#endif
#if cMaxSwitch && CaxisEnableSwitches
    pinMode(cMaxSwitch, INPUT_PULLUP);
#endif
#if cHomeSwitch && CaxisEnableSwitches
    pinMode(cHomeSwitch, INPUT_PULLUP);
#endif

#if uMinSwitch && UaxisEnableSwitches
    pinMode(uMinSwitch, INPUT_PULLUP);
#endif
#if uMaxSwitch && UaxisEnableSwitches
    pinMode(uMaxSwitch, INPUT_PULLUP);
#endif
#if uHomeSwitch && UaxisEnableSwitches
    pinMode(uHomeSwitch, INPUT_PULLUP);
#endif

#if vMinSwitch && VaxisEnableSwitches
    pinMode(vMinSwitch, INPUT_PULLUP);
#endif
#if vMaxSwitch && VaxisEnableSwitches
    pinMode(vMaxSwitch, INPUT_PULLUP);
#endif
#if vHomeSwitch && VaxisEnableSwitches
    pinMode(vHomeSwitch, INPUT_PULLUP);
#endif

#if wMinSwitch && WaxisEnableSwitches
    pinMode(wMinSwitch, INPUT_PULLUP);
#endif
#if wMaxSwitch && WaxisEnableSwitches
    pinMode(wMaxSwitch, INPUT_PULLUP);
#endif
#if wHomeSwitch && WaxisEnableSwitches
    pinMode(wHomeSwitch, INPUT_PULLUP);
#endif
}

int faultCountOld = 0;
void checkSwitches()
{
    boolean switchState;
    int faultCount = 0;
#if XaxisEnableSwitches
#if xMinSwitch
    switchState = digitalRead(xMinSwitch);
    faultId[0][0] = switchState;
    faultCount += switchState;
#else
    if (targetPos[0] < xVirtualMin) {
	switchState = 1;
    } else {
	switchState = 0;
    }
    faultId[0][0] = switchState;
    faultCount += switchState;
#endif
#if xMaxSwitch
    switchState = digitalRead(xMaxSwitch);
    faultId[0][1] = switchState;
    faultCount += switchState;
#else
    if (targetPos[0] > xVirtualMax) {
	switchState = 1;
    } else {
	switchState = 0;
    }
    faultId[0][1] = switchState;
    faultCount += switchState;
#endif
#if xHomeSwitch
    switchState = digitalRead(xHomeSwitch);
    faultId[0][2] = switchState;
    faultCount += switchState;
#else
    if (targetPos[0] > xVirtualHome
	&& targetPos[0] < (xVirtualHome + 2500)) {
	switchState = 1;
    } else {
	switchState = 0;
    }
    faultId[0][2] = switchState;
    faultCount += switchState;
#endif
#endif

#if YaxisEnableSwitches
#if yMinSwitch
    switchState = digitalRead(yMinSwitch);
    faultId[1][0] = switchState;
    faultCount += switchState;
#else
    if (targetPos[1] < yVirtualMin) {
	switchState = 1;
    } else {
	switchState = 0;
    }
    faultId[1][0] = switchState;
    faultCount += switchState;
#endif
#if yMaxSwitch
    switchState = digitalRead(yMaxSwitch);
    faultId[1][1] = switchState;
    faultCount += switchState;
#else
    if (targetPos[1] < yVirtualMax) {
	switchState = 1;
    } else {
	switchState = 0;
    }
    faultId[1][1] = switchState;
    faultCount += switchState;
#endif
#if yHomeSwitch
    switchState = digitalRead(yHomeSwitch);
    faultId[1][2] = switchState;
    faultCount += switchState;
#else
    if (targetPos[1] > yVirtualHome
	&& targetPos[1] < (yVirtualHome + 2500)) {
	switchState = 1;
    } else {
	switchState = 0;
    }
    faultId[1][2] = switchState;
    faultCount += switchState;
#endif
#endif

#if ZaxisEnableSwitches
#if zMinSwitch
    switchState = digitalRead(zMinSwitch);
    faultId[2][0] = switchState;
    faultCount += switchState;
#else
    if (targetPos[2] < zVirtualMin) {
	switchState = 1;
    } else {
	switchState = 0;
    }
    faultId[2][0] = switchState;
    faultCount += switchState;
#endif
#if zMaxSwitch
    switchState = digitalRead(zMaxSwitch);
    faultId[2][1] = switchState;
    faultCount += switchState;
#else
    if (targetPos[2] < zVirtualMax) {
	switchState = 1;
    } else {
	switchState = 0;
    }
    faultId[2][1] = switchState;
    faultCount += switchState;
#endif
#if zHomeSwitch
    switchState = digitalRead(zHomeSwitch);
    faultId[2][2] = switchState;
    faultCount += switchState;
#else
    if (targetPos[2] > zVirtualHome
	&& targetPos[2] < (zVirtualHome + 2500)) {
	switchState = 1;
    } else {
	switchState = 0;
    }
    faultId[2][2] = switchState;
    faultCount += switchState;
#endif
#endif

#if AaxisEnableSwitches
#if aMinSwitch
    switchState = digitalRead(aMinSwitch);
    faultId[3][0] = switchState;
    faultCount += switchState;
#else
    if (targetPos[3] < aVirtualMin) {
	switchState = 1;
    } else {
	switchState = 0;
    }
    faultId[3][0] = switchState;
    faultCount += switchState;
#endif
#if aMaxSwitch
    switchState = digitalRead(aMaxSwitch);
    faultId[3][1] = switchState;
    faultCount += switchState;
#else
    if (targetPos[3] < aVirtualMax) {
	switchState = 1;
    } else {
	switchState = 0;
    }
    faultId[3][1] = switchState;
    faultCount += switchState;
#endif
#if aHomeSwitch
    switchState = digitalRead(aHomeSwitch);
    faultId[3][2] = switchState;
    faultCount += switchState;
#else
    if (targetPos[3] > aVirtualHome
	&& targetPos[3] < (aVirtualHome + 2500)) {
	switchState = 1;
    } else {
	switchState = 0;
    }
    faultId[3][2] = switchState;
    faultCount += switchState;
#endif
#endif

#if BaxisEnableSwitches
#if bMinSwitch
    switchState = digitalRead(bMinSwitch);
    faultId[4][0] = switchState;
    faultCount += switchState;
#else
    if (targetPos[4] < bVirtualMin) {
	switchState = 1;
    } else {
	switchState = 0;
    }
    faultId[4][0] = switchState;
    faultCount += switchState;
#endif
#if bMaxSwitch
    switchState = digitalRead(bMaxSwitch);
    faultId[4][1] = switchState;
    faultCount += switchState;
#else
    if (targetPos[4] < bVirtualMax) {
	switchState = 1;
    } else {
	switchState = 0;
    }
    faultId[4][1] = switchState;
    faultCount += switchState;
#endif
#if bHomeSwitch
    switchState = digitalRead(bHomeSwitch);
    faultId[4][2] = switchState;
    faultCount += switchState;
#else
    if (targetPos[4] > bVirtualHome
	&& targetPos[4] < (bVirtualHome + 2500)) {
	switchState = 1;
    } else {
	switchState = 0;
    }
    faultId[4][2] = switchState;
    faultCount += switchState;
#endif
#endif

#if CaxisEnableSwitches
#if cMinSwitch
    switchState = digitalRead(cMinSwitch);
    faultId[5][0] = switchState;
    faultCount += switchState;
#else
    if (targetPos[5] < cVirtualMin) {
	switchState = 1;
    } else {
	switchState = 0;
    }
    faultId[5][0] = switchState;
    faultCount += switchState;
#endif
#if cMaxSwitch
    switchState = digitalRead(cMaxSwitch);
    faultId[5][1] = switchState;
    faultCount += switchState;
#else
    if (targetPos[5] < cVirtualMax) {
	switchState = 1;
    } else {
	switchState = 0;
    }
    faultId[5][1] = switchState;
    faultCount += switchState;
#endif
#if cHomeSwitch
    switchState = digitalRead(cHomeSwitch);
    faultId[5][2] = switchState;
    faultCount += switchState;
#else
    if (targetPos[5] > cVirtualHome
	&& targetPos[5] < (cVirtualHome + 2500)) {
	switchState = 1;
    } else {
	switchState = 0;
    }
    faultId[5][2] = switchState;
    faultCount += switchState;
#endif
#endif

#if UaxisEnableSwitches
#if uMinSwitch
    switchState = digitalRead(uMinSwitch);
    faultId[6][0] = switchState;
    faultCount += switchState;
#else
    if (targetPos[6] < uVirtualMin) {
	switchState = 1;
    } else {
	switchState = 0;
    }
    faultId[6][0] = switchState;
    faultCount += switchState;
#endif
#if uMaxSwitch
    switchState = digitalRead(uMaxSwitch);
    faultId[6][1] = switchState;
    faultCount += switchState;
#else
    if (targetPos[6] < uVirtualMax) {
	switchState = 1;
    } else {
	switchState = 0;
    }
    faultId[6][1] = switchState;
    faultCount += switchState;
#endif
#if uHomeSwitch
    switchState = digitalRead(uHomeSwitch);
    faultId[6][2] = switchState;
    faultCount += switchState;
#else
    if (targetPos[6] > uVirtualHome
	&& targetPos[6] < (uVirtualHome + 2500)) {
	switchState = 1;
    } else {
	switchState = 0;
    }
    faultId[6][2] = switchState;
    faultCount += switchState;
#endif
#endif

#if VaxisEnableSwitches
#if vMinSwitch
    switchState = digitalRead(vMinSwitch);
    faultId[7][0] = switchState;
    faultCount += switchState;
#else
    if (targetPos[7] < vVirtualMin) {
	switchState = 1;
    } else {
	switchState = 0;
    }
    faultId[7][0] = switchState;
    faultCount += switchState;
#endif
#if vMaxSwitch
    switchState = digitalRead(vMaxSwitch);
    faultId[7][1] = switchState;
    faultCount += switchState;
#else
    if (targetPos[7] < vVirtualMax) {
	switchState = 1;
    } else {
	switchState = 0;
    }
    faultId[7][1] = switchState;
    faultCount += switchState;
#endif
#if vHomeSwitch
    switchState = digitalRead(vHomeSwitch);
    faultId[7][2] = switchState;
    faultCount += switchState;
#else
    if (targetPos[7] > vVirtualHome
	&& targetPos[7] < (vVirtualHome + 2500)) {
	switchState = 1;
    } else {
	switchState = 0;
    }
    faultId[7][2] = switchState;
    faultCount += switchState;
#endif
#endif

#if WaxisEnableSwitches
#if wMinSwitch
    switchState = digitalRead(wMinSwitch);
    faultId[8][0] = switchState;
    faultCount += switchState;
#else
    if (targetPos[8] < wVirtualMin) {
	switchState = 1;
    } else {
	switchState = 0;
    }
    faultId[8][0] = switchState;
    faultCount += switchState;
#endif
#if wMaxSwitch
    switchState = digitalRead(wMaxSwitch);
    faultId[8][1] = switchState;
    faultCount += switchState;
#else
    if (targetPos[8] < wVirtualMax) {
	switchState = 1;
    } else {
	switchState = 0;
    }
    faultId[8][1] = switchState;
    faultCount += switchState;
#endif
#if wHomeSwitch
    switchState = digitalRead(wHomeSwitch);
    faultId[8][2] = switchState;
    faultCount += switchState;
#else
    if (targetPos[8] > wVirtualHome
	&& targetPos[8] < (wVirtualHome + 2500)) {
	switchState = 1;
    } else {
	switchState = 0;
    }
    faultId[8][2] = switchState;
    faultCount += switchState;
#endif
#endif

    if (faultCount != faultCountOld) {	//One or more switches has changed.
	canMove = 0;
	faultCountOld = faultCount;
	for (int i = 0; i < 9; i++) {
	    for (int e = 0; e < 3; e++) {
		if (faultId[i][e] != faultIdOld[i][e]) {
		    faultIdOld[i][e] = faultId[i][e];
		    if (e == 0) {
			Serial.print("233 ");
			Serial.print(i);
			Serial.print(" ");
			Serial.print(faultId[i][e]);
			Serial.print(" ");
			Serial.print(233 + i + faultId[i][e]);
			Serial.println(";");
		    }
		    if (e == 1) {
			Serial.print("231 ");
			Serial.print(i);
			Serial.print(" ");
			Serial.print(faultId[i][e]);
			Serial.print(" ");
			Serial.print(231 + i + faultId[i][e]);
			Serial.println(";");
		    }
		    if (e == 2) {
			Serial.print("215 ");
			Serial.print(i);
			Serial.print(" ");
			Serial.print(faultId[i][e]);
			Serial.print(" ");
			Serial.print(215 + i + faultId[i][e]);
			Serial.println(";");
		    }
		}
	    }
	}
    } else {
	canMove = 1;
    }
}
#endif

