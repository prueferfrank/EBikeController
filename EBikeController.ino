#include <Arduino.h>
#include <HardwareSerial.h>
#include <pins_arduino.h>
#include <Print.h>

//The setup function is called once at startup of the sketch

const byte interruptPin = 3;
const byte ledPin = 13;

volatile byte state = LOW;

volatile unsigned long lastTime = 0;
volatile unsigned long deltaTime = 0;

double totalDistance = 0.0;
double wheelsize = 2.228; // in meter
double totalTime = 0;  // in seconds

double currentSpeed = 0.0; // in km/h
double averageSpeed = 0.0; // in km/h

long turns = 0;

void setup() {
	pinMode(ledPin, OUTPUT);
	pinMode(interruptPin, INPUT_PULLUP);
	attachInterrupt(digitalPinToInterrupt(interruptPin), isr, FALLING);
	Serial.begin(115200);
}

void loop() {
	digitalWrite(ledPin, state);

	//in rpm umrechnen
	if (deltaTime > 0) {
		// deltatime = millis since last time
		// speed = distance / time
		totalDistance = (turns * wheelsize) / 1000; // in km

		Serial.print("Total Time:");
		Serial.print(totalTime);
		Serial.print("-");
		Serial.println(micros());
		Serial.print("Turns:");
		Serial.println(turns);
		Serial.print("Total Distance (km):");
		Serial.println(getDistance(), 3);

		Serial.print("DeltaTime (seconds):");
		Serial.println(microsToSeconds(deltaTime), 3);
		Serial.print("DeltaTime (minutes):");
		Serial.println(microsToMinutes(deltaTime), 6);
		Serial.print("DeltaTime (hours):");
		Serial.println(microsToHours(deltaTime), 8);


		Serial.print("TotalTime (seconds):");
		Serial.println(microsToSeconds(totalTime), 3);
		Serial.print("TotalTime (minutes):");
		Serial.println(microsToMinutes(totalTime), 6);
		Serial.print("TotalTime (hours):");
		Serial.println(microsToHours(totalTime), 8);

		Serial.print("Current Speed (km/h):");
		Serial.println(getSpeed(microsToHours(deltaTime), getDeltaDistance()), 3);

		Serial.print("Average Speed (km/h):");
		Serial.println(getSpeed(microsToHours(totalTime), getDistance()), 3);

		// deltatime = micros since last trigger

		deltaTime = 0;

	}

	// current speed
	// average speed =  total distance / totaltime
	// total distance in km
}

void isr() {
	state = !state;
	deltaTime = micros() - lastTime;
	lastTime = micros();
	totalTime += deltaTime;
	turns++;
}

// in km
double getDistance() {
	double totalDistance = (turns * wheelsize) / 1000;
	return totalDistance;
}

double getDeltaDistance() {
	return  wheelsize / 1000;
}

// distance in metern
// deltaTime in hours
// return speed in km/h
double getSpeed(double hours, double kilometers) {
	return kilometers / hours;
}

double microsToHours(unsigned long microSeconds) {
	return microsToMinutes(microSeconds) / (double) (60);
}

double microsToMinutes(unsigned long microSeconds) {
	return microsToSeconds(microSeconds) / (double) (60);
}

double microsToSeconds(unsigned long microSeconds) {
	return ((double) microSeconds) / (double) (1000000);
}
