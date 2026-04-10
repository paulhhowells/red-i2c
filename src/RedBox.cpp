#include <Arduino.h>
#include <RedBox.h>

RedBox::RedBox ()
{
}

bool RedBox::begin ()
{
	return true;
}

// Red::Red(uint8_t address, TwoWire &wire)
// 		: wire_(&wire), address_(address) {
// }

// bool Red::begin() {
// 	wire_->begin();
// 	return true;
// }

// uint8_t Red::address() const {
// 	return address_;
// }
