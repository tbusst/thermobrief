#ifndef GPT_API_H
#define GPT_API_H

#include <Arduino.h>
#include <HTTPClient.h>
#include <Arduino_JSON.h>
#include <WiFi.h>
#include "secrets.h"

String contactApi(const char* requestBody);

#endif