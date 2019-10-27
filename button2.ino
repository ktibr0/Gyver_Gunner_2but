#ifdef ESP_USE_BUTTON



void button2Tick()
{
  if (!buttonEnabled)                                       // события кнопки не обрабатываются, если она заблокирована
  {
    return;
  }

  touch2.tick();
  uint8_t clickCount = touch.hasClicks() ? touch.getClicks() : 0U;


  // однократное нажатие
  if (clickCount == 1U)
  {

loadingFlag = true;
      while(!fillString(WiFi.localIP().toString().c_str(), CRGB::White)) { delay(1); ESP.wdtFeed(); }
      loadingFlag = true;


//letterColor = CRGB::Red;
//    char stringTime[10U];                                   // буффер для выводимого текста, его длина должна быть НЕ МЕНЬШЕ, чем длина текста + 1
//    sprintf_P(stringTime, PSTR("-> %u:%02u"), (uint8_t)((thisTime - thisTime % 60U) / 60U), (uint8_t)(thisTime % 60U));
//    loadingFlag = true;
//    FastLED.setBrightness(getBrightnessForPrintTime(thisTime, ONflag));
//    delay(1);
//    while (!fillString(stringTime, letterColor)) {
//      delay(1);
//      ESP.wdtFeed();
//    }
//    loadingFlag = true;

  }


  // двухкратное нажатие
  if (ONflag && clickCount == 2U)
  {
    if (++currentMode >= (int8_t)MODE_AMOUNT) currentMode = 0;
    FastLED.setBrightness(modes[currentMode].Brightness);
    loadingFlag = true;
    settChanged = true;
    eepromTimeout = millis();
    FastLED.clear();
    delay(1);

#if (USE_MQTT)
    if (espMode == 1U)
    {
      MqttManager::needToPublish = true;
    }
#endif
  }


  // трёхкратное нажатие
  if (ONflag && clickCount == 3U)
  {
    if (--currentMode < 0) currentMode = MODE_AMOUNT - 1;
    FastLED.setBrightness(modes[currentMode].Brightness);
    loadingFlag = true;
    settChanged = true;
    eepromTimeout = millis();
    FastLED.clear();
    delay(1);

#if (USE_MQTT)
    if (espMode == 1U)
    {
      MqttManager::needToPublish = true;
    }
#endif
  }




















}
#endif
