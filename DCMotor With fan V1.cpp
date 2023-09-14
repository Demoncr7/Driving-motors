/*
 * MotorPWMv1.cpp
 *Jose De Jesus 
 * Created: 11/13/2022 11:38:08 PM
 * Author : User
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void) {
	// Configure the motor control pins
	DDRD |= (1 << PORTD5) | (1 << PORTD4) | (1 << PORTD6); // Pins 4, 5, and 6 as outputs

	// Motor control logic here
	while (1) {
		// Forward rotation (IN1: HIGH, IN2: LOW)
		PORTD |= (1 << PORTD4); // Set IN1 (Arduino Pin 5) to HIGH
		PORTD &= ~(1 << PORTD5); // Set IN2 (Arduino Pin 4) to LOW
		PORTD |= (1 << PORTD6); // Enable 1 (Arduino Pin 6) to HIGH

		// Delay for a while (you can adjust this)
		_delay_ms(5000); // Pause for 5 seconds

		// Reverse rotation (IN1: LOW, IN2: HIGH)
		PORTD &= ~(1 << PORTD4); // Set IN1 (Arduino Pin 5) to LOW
		PORTD |= (1 << PORTD5); // Set IN2 (Arduino Pin 4) to HIGH
		PORTD |= (1 << PORTD6); // Enable 1 (Arduino Pin 6) to HIGH

		// Delay for a while (you can adjust this)
		_delay_ms(5000); // Pause for 5 seconds

		// Stop the motor (IN1: LOW, IN2: LOW)
		PORTD &= ~(1 << PORTD4); // Set IN1 (Arduino Pin 5) to LOW
		PORTD &= ~(1 << PORTD5); // Set IN2 (Arduino Pin 4) to LOW
		PORTD &= ~(1 << PORTD6); // Disable the motor (set Enable 1 to LOW)

		// Delay for a while (you can adjust this)
		_delay_ms(5000); // Pause for 5 seconds
	}

	return 0;
}
