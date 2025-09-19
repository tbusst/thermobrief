#include "gpt_api.h"

String contactApi(String prompt) {
  HTTPClient http;
  http.begin("https://api.openai.com/v1/chat/completions");
  http.addHeader("Content-Type", "application/json");
  http.addHeader("Authorization", "Bearer " + String(API_KEY));

  // Request
  String requestBody = String("{\"model\": \"gpt-4o-mini\", \"messages\": [{\"role\": \"user\", \"content\": \"") + prompt + "\"}]}";
 
  // Response
  int httpResponseCode = http.POST(requestBody);
  String payload = "{}";

  // Checks if response is valid
  if (httpResponseCode > 0) {
    payload = http.getString();
    Serial.println("Response:");
    Serial.println(payload);

    // Parse JSON response
    JSONVar doc = JSON.parse(payload);
    if (JSON.typeof(doc) != "undefined") {
      String reply = (const char*) doc["choices"][0]["message"]["content"];
      return reply;
    }
  } else {
    Serial.print("Error on sending POST: ");
    Serial.println(httpResponseCode);
  }

  http.end();
  return "Error or no response";
}