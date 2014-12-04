// This #include statement was automatically added by the Spark IDE.
#include "HttpClient/HttpClient.h"
HttpClient http;

/****
 * This code uses the Beebotte API, you must have an account.
 * You can register here: http://beebotte.com/register
 ***/
 
//Channel Token for authentication
#define TOKEN "YOUR_CHANNEL_TOKEN"

//channel to write data to
#define CHANNEL "YOUR_CHANNEL"
//resource to write data to
#define RESOURCE "YOUR_RESOURCE"

http_header_t headers[] = {
      { "Content-Type", "application/json" },
      { "X-Auth-Token" , TOKEN },
    { NULL, NULL } // NOTE: Always terminate headers will NULL
};

http_request_t request;
http_response_t response;

void setup() {
    request.hostname = "api.beebotte.com";
    request.port = 80;
    
    //Assume an analog sensor is connected to pin A7
    pinMode(A7, INPUT);
}

void loop() {
    int value;
    value = analogRead(A7);

    //Send a write request with the read value
    request.path = "/v1/data/write/"CHANNEL"/"RESOURCE;
    request.body = "{\"data\":" + String(value) + "}";
    http.post(request, response, headers);

    //wait 15 seconds 
    delay(15000);
}
